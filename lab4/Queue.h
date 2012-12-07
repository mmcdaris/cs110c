#ifndef __Queue__
#define __Queue__

/** @file Queue.h */

#include "QueueException.h"
const int MAX_QUEUE = 4; // MAX_QUEUE is 4
typedef int QueueItemType; // QueueItemType is integer

/** @class Queue
 * ADT queue - Array-based implementation. */
class Queue
{
public:
// constructors and destructor:
   /** Default constructor. */
   Queue();
   // copy constructor and destructor are
   // supplied by the compiler

// Queue operations:
   bool isEmpty() const;
   void enqueue(const QueueItemType& newItem)
      throw(QueueException);
   void dequeue() throw(QueueException);
   void dequeue(QueueItemType& queueFront)
      throw(QueueException);
   void getFront(QueueItemType& queueFront) const
      throw(QueueException);
   int capacity();
   int size();
   void display();
private:
   QueueItemType items[MAX_QUEUE];
   int           front;
   int           back;
   int           count;
}; // end Queue
// End of header file.

#endif
