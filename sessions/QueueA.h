#ifndef __QUEUEA_H__
#define __QUEUEA_H__
/** @file QueueA.h */

#include "QueueException.h"
const int MAX_QUEUE = 12;
typedef char QueueItemType;

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

private:
   QueueItemType items[MAX_QUEUE];
   int           front;
   int           back;
   int           count;
}; // end Queue
// End of header file.
#endif
