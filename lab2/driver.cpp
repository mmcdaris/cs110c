#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "ListP.h"
using namespace std;

int prompt();
void response(int choice, List myslist);

int main()
{
  int choice = 0;           // holds user's choice 
  bool escape = false;      // controls escape
  string yn;
  List myList; 
  

  while (escape == false)
  {
    choice = prompt();
    if(choice > 0)
      response(choice, myList);
    else if(choice == 0)
      escape = true;
    else
    {
      cout << "Go again (y/n)? "; // continue?
      cin.clear();
      cin >> yn;
      if(!(yn[0] == 'y')) // must be 'y', "y" raises a compile error
        escape = true;
    }
  }

  return(0);

}

int prompt()
{
 int choice = 0;
 cout << "1) Insert Item(s)\n2) Delete Item\n3) Exit\nPlease enter your choice: ";
 cin >> choice;
 return choice;
}

void response(int choice, List myList)
{
  int pos = 9999, num = 0, mx = myList.getLength();
  bool extra = false;
  if(choice == 1) // add to the list at the pos
  {  
     while(pos > mx)
     {
    
      if(extra == false)
      {
        cout << "Enter position of insert: ";
      }
      else
      {
        cout << "Enter position of insert(" << 1 << "-" << mx << "): ";
      }

      cin >> pos;
      extra = false;
    
      if(pos > mx || pos < 1)
      {
        cout << "Out of Range";
        extra = true;
      }
      else
      {
        string data;
        cout << "Enter items to insert: ";
        for(int in = pos; in > num; in++)
        {
         cin >> data;
         myList.insert(pos, data);
  
        }
      }
    }
  }
 else // delete an element at a pos
 {
  
 }
 myList.display();
 myList.displayReverse();
}
