// Morgan Mikel Mcdaris

#include <stdlib.h>
#include <iostream>
#include <string>
#include "StackA.h"
#include "QueueA.h"

using namespace std;

bool isPal(string str);

int main()
{
  for(int i = 5; i > 1;) 
  {
    string str;
    cout << "PALENDROME: ";
    cin >> str;
    if(isPal(str))
    {
      cout << "\nbingo!";
      i++;
    }
    else
    {
      cout << "\nNo Good!\n";
      i--;
    }
    cout << i << " \033[1;36m Credits Left\033[0m\n"; //cyan and back 
  }

  return 0;
}

bool isPal(string str)
{
  bool pal = false;
  char qt,st;
  Queue que;
  Stack stk;
  for(int i = 0; i < str.length(); i++)
  {
    cout << str[i] << " ";
    que.enqueue(str[i]);
  }
  for(int i = 0; i < str.length(); i++)
  {
    stk.pop(st);
    que.dequeue(qt);
    if(qt == st)
      pal = true; 
  }
  return pal;
}
