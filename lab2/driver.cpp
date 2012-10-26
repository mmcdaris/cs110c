#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "ListP.h"
using namespace std;

void prompt();
void response(int choice, List &myslist);
int  getValidPos(int mx, int choice);

int main()
{
  int choice = 0;           // holds user's choice 
  bool escape = false;      // controls escape
  string yn;                // used for choices
  List myList;              // make a new list

  while (escape == false)
  {
    prompt();
    cin.clear();
    cin >> choice;
    if((choice == 2) || (choice == 1))
      response(choice, myList);
    
    else if(choice == 3)
      escape = true;

    if(escape != true)
    {
      cout << "Go again (y/n)? "; // continue?
      cin.clear();
      cin >> yn;
      if(!(yn[0] == 'y')) // must be 'y', "y" raises a compile error
      { 
        escape = true;
      }
    }
  }
  return(0);

}

void prompt()
{
 cout << "\n1) Insert Item(s)\n2) Delete Item\n3) Exit\nPlease enter your choice: ";
}

void response(int choice, List &myList)
{
  int num = 0, mx = myList.getLength(), pos = (mx+1);
  /*--getValidPosition-------------------*/
    pos = getValidPos(mx, choice);        
  /*---------add/delete/how-many---------*/
      
      /*---insertion-section--------*/
      if(choice == 1)
      {
        string data;                            
        cout << "Enter number of items to insert: ";      
        cin >> num;
          if(num > 10){num = 10;}
        cout << "Enter items to insert: ";
        for(int i = 0; i != num; i++)         
        {                                         
          cin >> data;
          myList.insert(pos + i, data);
        }                                       
      } 
      else/*----deletion-section--------*/
      {
        // cout << "Enter item number to delete: ";                                           
        if(mx != 0)
          myList.remove(pos);
        else
          cout << "nothing to remove, check for yourself!\n";
      }

      myList.display();
      myList.displayReverse();
      mx = myList.getLength();
}

int getValidPos(int mx, int choice)
{
  bool extra = false;
  int p = mx; int pos = 0;
  if(mx == 0){ p++; }

  while(pos > mx+1 || pos < 1)
  {
    if(extra == false)
    {
      if(choice == 1)
        cout << "Enter position of insert: ";
      else
        cout << "Enter item number to delete: ";
    }
    else // (extra == true)
    {
      if(choice == 1)
        cout << "Out of Range\nEnter position of insert(" << 1 << "-" << p+1 << "): ";
      else
        cout << "Out of Range\nEnter item number to delete(" << 1 << "-" << p << "): ";
    }
    extra = true;
    cin.clear();
    cin >> pos;
  }
  return pos;
}
/*
Program Output:
1) Insert Item(s)
2) Delete Item
3) Exit
Please enter your choice: 1
Enter position of insert: 1
Enter number of items to insert: 4
Enter items to insert: California Nevada Utah Colorado
Item(s): California Nevada Utah Colorado 
Item(s) in reverse order: Colorado Utah Nevada California 
Go again (y/n)? y

1) Insert Item(s)
2) Delete Item
3) Exit
Please enter your choice: 2
Enter item number to delete: 3
Item(s): California Nevada Colorado 
Item(s) in reverse order: Colorado Nevada California 
Go again (y/n)? y

1) Insert Item(s)
2) Delete Item
3) Exit
Please enter your choice: 2
Enter item number to delete: 3
Item(s): California Nevada 
Item(s) in reverse order: Nevada California 
Go again (y/n)? y

1) Insert Item(s)
2) Delete Item
3) Exit
Please enter your choice: 1
Enter position of insert: 4
Out of Range
Enter position of insert(1-3): 2
Enter number of items to insert: 3
Enter items to insert: Idaho Montana Wyoming
Item(s): California Idaho Montana Wyoming Nevada 
Item(s) in reverse order: Nevada Wyoming Montana Idaho California 
Go again (y/n)? y

1) Insert Item(s)
2) Delete Item
3) Exit
Please enter your choice: 2
Enter item number to delete: 0
Out of Range
Enter item number to delete(1-5): 1
Item(s): Idaho Montana Wyoming Nevada 
Item(s) in reverse order: Nevada Wyoming Montana Idaho 
Go again (y/n)? y

1) Insert Item(s)
2) Delete Item
3) Exit
Please enter your choice: 2
Enter item number to delete: 2
Item(s): Idaho Wyoming Nevada 
Item(s) in reverse order: Nevada Wyoming Idaho 
Go again (y/n)? n
*/
