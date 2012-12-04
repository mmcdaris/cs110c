#include "StackA.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  /*  string prompts  */
  string    prompt = "1) Add item to queue\n2) Remove item from queue\n3) Exit program\nEnter your Selection (1-3): ",
            insert = "Enter item to insert: ",
           rmError = "Unable to remove item from empty queue",
           inError = "Unable to instert into full queue"
  /*  ints for flow control and temp  */
  int choice;
  int number;

  /*  queue creation  */
  theQueue = queue.new;
  
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
        theQueue.insert(number);
      } 
      else
        cout << inError;   
    }

    /*  Removal  */
    else if(choice == 2) // Remove
    {
      if(theQueue.size() != 0)
      {
        theQueue.remove();
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

