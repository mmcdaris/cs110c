/** @file StackA.cpp */

#include <iostream>
#include <new>
#include "StackA.h"    // header file

using namespace std;

Stack::Stack()
{
  max = 4;
  top = 0;
  size = 0;
  array = new StackItemType[max];
} // end default constructor

//Stack::Stack(const Stack& aStack)
//{
//  array = aStack.getArray();    
//}  // end copy constructor

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
    max = 2*max;
    for(int index = 0; index < size; ++index)
    {
      array[index] = oldArray[index];
    }
    delete [] oldArray;
  }
  array[top] = newItem;
  ++size;
  ++top;
  
  cout << "Item inserted: " << array[(top - 1)] << ". " << size << ((size == 1) ? " item in stack. " : " items in stack. ") << "Array size: " << max << endl;
}  // end push

void Stack::pop()
{
  if(size < 0)
  {
    --top;
    --size;
  }
  else
    cout << "Empty Stack";

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
  stackTop = array[top];  
}  // end getTop

void Stack::display()
{
  cout << "Items (from top to bottom):" << endl;
  for(int tmpTop = size-1; tmpTop >= 0; --tmpTop)
  {
    cout << array[tmpTop] << " ";
  }
} // end display

StackItemType* Stack::getArray()
{
  StackItemType* tempArray = new StackItemType[size];
  return tempArray;
}


// End of implementation file.
