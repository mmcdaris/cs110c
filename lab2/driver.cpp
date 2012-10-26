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
        escape = true;
    }
  }
  return(0);

}

void prompt()
{
 cout << "1) Insert Item(s)\n2) Delete Item\n3) Exit\nPlease enter your choice: ";
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
        cout << "Out of Range\nEnter position of insert(" << 1 << "-" << p << "): ";
      else
        cout << "Out of Range\nEnter item number to delete(" << 1 << "-" << p << "): ";
    }
    extra = true;
    cin.clear();
    cin >> pos;
  }
  return pos;
}
