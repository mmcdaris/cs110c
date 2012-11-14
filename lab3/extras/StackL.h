/** @file StackL.cpp */

#include <iostream>
#include "StackA.h"    // header file

Stack::Stack()
{
  max = 4;
  top = 0;
  size = 0;
  array = StackItemType[max];
}  // end default constructor

Stack::Stack(const Stack& aStack)
{
  
}  // end copy constructor

Stack::~Stack()
{
  delete [] array;
}  // end destructor

bool Stack::isEmpty() const
{
  return(size == 0);
}  // end isEmpty

void Stack::push(const StackItemType& newItem)
{
  if(size == max)
  {
    StackItemType *oldArray = array;
    array = new StackItemType[2*max];
    for(int index = 0; index < size; ++index)
      array[index] = oldArray[index];
    delete [] oldArray
  }
  array[top] = newItem;
  ++size;
  ++top;
}  // end push

void Stack::pop()
{
  if(size < 0)
  {
    --top;
    --size;
  }
  else
    cout << "Empty Stack"

}  // end pop

void Stack::pop(StackItemType& stackTop)
{
  if(size < 0)
  {
     stackTop = array[top];
     --top;
     --size;
  }
}  // end pop

void Stack::getTop(StackItemType& stackTop)
{
  
}  // end getTop

void Stack::display()
{
  cout << "Items (from top to bottom):" << endl;
  for(int tempTop = top; temptop =; --index)
  {
    cout << array << " ";
  }
} // end display

// End of implementation file.
