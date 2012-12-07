#include "Queue.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
  /*  string prompts  */
  string prompt = "1) Add item to queue\n2) Remove item from queue\n3) Exit program\nEnter your Selection (1-3): ";
  string insert = "Enter item to insert: ";
  string rmError = "Unable to remove item from empty queue\n";
  string inError = "Unable to instert into full queue\n";
  /*  ints for flow control and temp  */
  int choice;
  int number;

  /*  queue creation  */
  Queue theQueue;
  
  while(choice != 3)
  {
    cout << prompt;
    /*  Insertion  */
    if(choice == 1) 
    {
      if(theQueue.size() < theQueue.capacity())
      {
        cout << insert;
        cin >> number; 
        theQueue.enqueue(number);
      } 
      else
        cout << inError;   
    }

    /*  Removal  */
    else if(choice == 2) // Remove
    {
      if(theQueue.size() != 0)
      {
        theQueue.dequeue();
        theQueue.display();
      }
      else
        cout << rmError;
    }

    /*   Exit  */
    else
    { /*  Game Over  */ }
  }
 
  return(0);
}


