#ifndef __LISTP_H__
#define __LISTP_H__
/** @file ListP.h */

#include "ListException.h"
#include "ListIndexOutOfRangeException.h"


/*  Class list Pointer based*/
lass List
{
public:
   List(); //default constructor

   List(const List& aList); //copies a list passed by reference

   ~List(); // destructor

// List operations:
   void display();                                        // Traverses the list and displays items
   void displayReverse();                                 // Displays in reverse (recursive || circular)
   bool isEmpty() const;                                  // return(Head == NULL)
   int getLength() const;                                 // return(size)
   void insert(int index, const ListItemType& newItem)    // insert this list Item at a list index 
      throw(ListIndexOutOfRangeException, ListException); // If ((index > size) || (index < 1)) exception!
   void remove(int index)                                 // remove an item at index (1 -> size) 
      throw(ListIndexOutOfRangeException);                // same as 2 lines up.
   void retrieve(int index, ListItemType& dataItem) const // get an item @ index and store it in dataItem 
      throw(ListIndexOutOfRangeException);                // same as 4 lines up

private:
   struct ListNode
   {
      ListItemType item;        /*                        */
      ListNode    *prev;        /*  <-[prev[Item]next]->  */
      ListNode    *next;        /*                        */
   };

   int size;
   
   ListNode *head;              /*  [head]-> [p[item]n]      */

   /** Locates a specified node in a linked list.
     @pre index is the number of the desired node.
     @post None.
     @param index The index of the node to locate.
     @return A pointer to the index-th node. If index < 1
             or index > size 
             returns NULL. 
     @example:
        cur = find(1);
    
    */

   ListNode *find(int index) const;

}; // end List




#endif
