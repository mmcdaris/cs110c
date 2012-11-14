#include "StackA.h"
#include <iostream>

using namespace std;

void collect(int total, Stack &aStack);

int main()
{
  Stack bigStack;
  int total;
  
  cout << "Enter Number Of Items In Array: ";
  cin >> total;
  
  cout << "Enter Items: ";
  collect(total, bigStack);
  
  cout << endl;
  
  bigStack.display();
}

void collect(int total, Stack &aStack)
{
  int item;
  for(int i = 0; i != total; i++)
  {
    cin >> item;
    aStack.push(item);
  }
}

/* ------------ output section ------------------
Enter Number Of Items In Array: 20
Enter Items: 5 10 15 20 4 3 17 19 14 2 1 12 18 9 6 13 8 7 11 16
Item inserted: 5. 1 item in stack. Array size: 4
Item inserted: 10. 2 items in stack. Array size: 4
Item inserted: 15. 3 items in stack. Array size: 4
Item inserted: 20. 4 items in stack. Array size: 4
Item inserted: 4. 5 items in stack. Array size: 8
Item inserted: 3. 6 items in stack. Array size: 8
Item inserted: 17. 7 items in stack. Array size: 8
Item inserted: 19. 8 items in stack. Array size: 8
Item inserted: 14. 9 items in stack. Array size: 16
Item inserted: 2. 10 items in stack. Array size: 16
Item inserted: 1. 11 items in stack. Array size: 16
Item inserted: 12. 12 items in stack. Array size: 16
Item inserted: 18. 13 items in stack. Array size: 16
Item inserted: 9. 14 items in stack. Array size: 16
Item inserted: 6. 15 items in stack. Array size: 16
Item inserted: 13. 16 items in stack. Array size: 16
Item inserted: 8. 17 items in stack. Array size: 32
Item inserted: 7. 18 items in stack. Array size: 32
Item inserted: 11. 19 items in stack. Array size: 32
Item inserted: 16. 20 items in stack. Array size: 32

Items (from top to bottom):
16 11 7 8 13 6 9 18 12 1 2 14 19 17 3 4 20 15 10 5
------------------------------------------------- */
