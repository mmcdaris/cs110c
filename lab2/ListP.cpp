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
    
    // cout << "<" << head->precede << "|" << "HEAD" << "|" << head->next << ">""<"<< cur->precede << "|"<< cur->item << "|" << cur->next << ">\n"; // cout the n->item
    
    
    cout << cur->item << " "; // cout the n->item
    cur = cur->next;   // until (n?)cur(dh)
  }
  cout << endl;
} // end display

void List::displayReverse()
{
  ListNode *cur = head->precede;               //(nMAX-1)nMAX(n1) <-(nMAX)cur(..)  (nMax)n1(n2)
  cout << "Item(s) in reverse order: ";
  while(cur != head)
  {
    cout << cur->item << " ";          
    cur = cur->precede;                        
  }
  cout << endl;
} // end displayReverse

bool List::isEmpty() const
{
   return size == 1;
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
	      else // insert new node inbetween prev and prv->next
	      {  
          ListNode *prv = find(index-1);  // one behind index
          newPtr->precede = prv;          // (prv)np()
          newPtr->next = prv->next;       // (prv)np(prv->next)
          prv->next = newPtr;             // (..)prv(np)(prv)np(prv->next)(prv)prv->next(..)
          newPtr->next->precede = newPtr; // (..)prv(np)(prv)np(prv->next)(np)prv->next(..)
	      }  
      
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
   ListNode *target;

   if ( (index < 1) || (index > getLength()) )
      throw ListIndexOutOfRangeException(
	 "ListIndexOutOfRangeException: remove index out of range");
   else
   {  
     target = find(index);
     if (index == 1)
     {  // delete the first node from the list
        head->next = target->next;    // (nn)H(n2)..(h )T(n2)--(t )n2(n3) | >Hn->n2<>n3<>n4<>n5<
        head->next->precede = head;   // (nn)H(n2)..(h )T(n2)..(H )n2(n3) | >Hn<>n2<>n3<>n4<>n5<
     }  
     else
     {  
	      target->precede->next = target->next;    // (..)n1(n3), (n1)ta(n3), (ta)n3(..)
        target->next->precede = target->precede; // (..)n1(n3), (n1)ta(n3), (n1)n3(..)
                                                 // (..)n1(n3), (n1)n3(..)      | to be deleted: (n1)ta(n3)
     }  // end if
      
      // return node to system
      target->next = NULL;
      target->precede = NULL;
      delete target;
      target = NULL;
   }  --size;// end if
}  // end remove
