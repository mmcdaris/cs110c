/** @file ListP.cpp
 *  ADT list - Pointer-based implementation. */

#include <cstddef>     // for NULL
#include <new>         // for bad_alloc
#include "ListP.h"     // header file
#include <iostream>    // for display and displayReverse


using namespace std;

// definitions of methods follow:
//  List structure:
//
//  p[dh]n<->p[n1]n<->p[n2]n<->p[n3]n<->p[n4]n
//  ↑__↑__________________________________↑  ↑
//     |_____________________________________|
//

List::List()
{
  head = new ListNode;
  head->next = head;    
  head->precede = head;
  size = 0;

}

List::List(const List& aList) : size(aList.size)
{
   if (aList.head == NULL)
   {
      head = new ListNode;  // h-> ()dh()                  
      head->next = head;    //     ()dh(dh)    h = dh (dh)dh(dh)
      head->precede = head; //   (dh)dh(dh)        
   }
   else
   {  // copy first node                            
      head->next = new ListNode;                    //  (  )dh(n1), (  )n1(  )   
      head->precede = head->next;                   //  (n1)dh(n1), (  )n1(  )       
      head->next->item = aList.head->next->item;    //  (n1)dh(n1), (  )n1(  ), (n1 + (a[n1]->item) )    
      head->next->next = head;                      //  (n1)dh(n1), (dh)n1(  )
      head->next->precede = head;                   //  (n1)dh(n1), (dh)n1(dh)

      // copy rest of list
      ListNode *newPtr = head->next;  // new list pointer newPtr -> n1
      // newPtr points to dh->next
      // origPtr points to the node a[n2].
      for (ListNode *origPtr = aList.head->next->next;
	      origPtr != head;
	      origPtr = origPtr->next)
        {  
          newPtr->next = new ListNode;    // (n1)dh(n1), (dh)n1|n2|, |  |n2|  |, newptr = n1, origPtr = a[n2]
          head->precede = newPtr->next;   // |n2|dh(n1), (dh)n1(n2), (  )n2(  ), newptr = n1, origPtr = a[n2]
          newPtr->next->precede = newPtr; // (n1)dh(n1), (dh)n1(n2), |n1|n2(  ), newptr = n1, origPtr = a[n2]
          newPtr->next->next = head;      // (n2)dh(n1), (dh)n1(n2), (n1)n2|dh|, newptr = n1, origPtr = a[n2]
          newPtr = newPtr->next;          // (n2)dh(n1), (dh)n1(n2), (n1)n2(dh), newptr = n2, origPtr = a[n2]
	        newPtr->item = origPtr->item;   // (n2)dh(n1), (dh)n1(n2), (n1)n2(dh), newptr = n2, origPtr = a[n2] , ( n2 +(a[n2]->item) ) 
          
        }  // end for

   }  // end if
}  // end copy constructor

List::~List()
{
   while (!isEmpty())
      remove(1);
}  // end destructor

void List::display()
{
  ListNode *cur = head->next;  // cur = (nMAX-1)nMAX(dh)
  cout << "Item(s): ";
  while(cur != head)
  {
    cout << cur->item << " "; // cout the n->item
    cur = cur->next;   // until (n?)cur(dh)
  }
  cout << endl;
} // end display

void List::displayReverse()
{
  ListNode *cur = head;
  cout << "Item(s) in reverse order: ";
  while(cur->precede != head)
  {
    cout << cur->precede->item << " ";   // cout the n1 item
    cur = cur->precede;         // until (n?)cur(dh)
  }
  cout << endl;
} // end displayReverse

bool List::isEmpty() const
{
   return size == 0;
}  // end isEmpty

int List::getLength() const
{
   return size;
}  // end getLength

List::ListNode *List::find(int index) const
{
   if ( (index < 1) || (index > getLength()) )
      return NULL;

   else  // count from the beginning of the list.
   {  ListNode *cur = head->next;                // cur = (dh)n1(n2)
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;                       
      return cur;                                // returns match cur = (??)n?(??)
   }  // end of if
}  // end find

void List::retrieve(int index,
                    ListItemType& dataItem) const
   throw(ListIndexOutOfRangeException)
{
   if ( (index < 1) || (index > getLength()) )
      throw ListIndexOutOfRangeException(
	 "ListIndexOutOfRangeException: retrieve index out of range");
   else
   {  // get pointer to node, then data in node
      ListNode *cur = find(index);
      dataItem = cur->item; 
      // dataItem's value is changed b/c it is passed by value
   }  // end of if
}  // end retrieve

void List::insert(int index, const ListItemType& newItem)
   throw(ListIndexOutOfRangeException, ListException)
{
   int newLength = getLength() + 1;

   if ( (index < 1) || (index > newLength) )
      throw ListIndexOutOfRangeException(
	 "ListIndexOutOfRangeException: insert index out of range");
   else
   {  // try to create new node and place newItem in it
      try
      {
	      ListNode *newPtr = new ListNode;                // newPtr = ()nIn()
	      size = newLength;                               // size++ :)
	      newPtr->item = newItem;                         // nIn->item = newItem

	      // attach new node to list
	      if (index == 1)
	      {  // insert new node at beginning of list
	        newPtr->next = head; newPtr->precede = head;  // (   )dh(   ), (dh)nIn(dh)
	        head->next = newPtr; head->precede = newPtr;  // (nIn)dh(nIn), (dh)nIn(dh)
	      }
	      else
	      {  
          ListNode *prev = find(index-1);                     // find node at index -1 insert new node after, call it prev
          newPtr->next = prev->next;
          newPtr->precede = prev;                             // (dh)prev(next), (prev)nIn(next)
	        prev->next = newPtr;                                // (dh)prev(nIn) , (prev)nIn(next)
          head->precede = newPtr;                             // adjust the end!
	      }  // end if
      }  // end try
      catch (bad_alloc e)
      {
	      throw ListException(
	        "ListException: memory allocation failed on insert");
      }  // end catch
   }  // end if
}  // end insert

void List::remove(int index) throw(ListIndexOutOfRangeException)
{
   ListNode *cur;

   if ( (index < 1) || (index > getLength()) )
      throw ListIndexOutOfRangeException(
	 "ListIndexOutOfRangeException: remove index out of range");
   else
   {  --size;
      if (index == 1)
      {  // delete the first node from the list
         cur = head->next;  // save pointer to node
         head = head->next->next;
         head->next->next->precede = head; // head is dh| dhn = n1, n1n = n2, n2p set to head!  
      }

      else
      {  
         ListNode *target = find(index);         // (..)n1(ta), (n1)ta(n3), (ta)n3(..) 
         cur = target;                           // save target to cur for deletion         
	       target->precede->next = target->next;   // (..)n1(n3), (n1)ta(n3), (ta)n3(..)
         target->next->precede = target->precede; // (..)n1(n3), (n1)ta(n3), (n1)n3(..)
                                                 // (..)n1(n3), (n1)n3(..)      | to be deleted: (n1)ta(n3)
      }  // end if

      // return node to system
      cur->next = NULL;
      cur->precede = NULL;
      delete cur;
      cur = NULL;
   }  // end if
}  // end remove
