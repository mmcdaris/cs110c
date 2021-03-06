/*
 Authors:    Morgan McDaris & Arthur Luk
 Course:     cs110c
 Instructor: Steve Abensohn
 Assignment: Lab1 - modify a recursive function to find the median
 Notes: you should check out our commit history :)
 	https://github.com/mmcdaris/cs110c/commits/master
	we colaborated remotely using github to push to this repository!
	talk to us about it if you are interested!
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
void quickSort (int anArray[], int first, int last, int length, bool &medianFound);
void swapIntArray (int anArray[], int x, int y);
void getArray(int anArray[],int length, int x, int y); //used for debugging
int findMedian(int anArray[], int length);


int main()
{
	int length;           // length of the array
  bool escape = false;  // controls escape
  int median;           // returns the median as an int to be displayed
  string yn;            // user prompt string
  
  while (escape == false)
  {
    cout << "Enter the number of items (please enter an odd number): ";
    cin >> length;
    
    // If length is ODD, begin the collection!
    if( length % 2 != 0 )
    {
      int* array = new int[length]; // new dynamic integer array

      cout << "Enter " << length << " integers:";
      for(int i=0; i < length; i++)
      {
        cin >> array[i];
        cin.clear();
      }
      // findMedian uses quickSort to find the median
	    cout << "The median is value is " << findMedian(array, (length -1)) << "." << endl;
      delete [] array; // delete dynamic array
    }

    else // length is EVEN
    {
      cout << length << " is not an odd number.\n";
    }
    
    cout << "Go again (y/n)? "; // continue?
    cin.clear();
    cin >> yn;
    if(!(yn[0] == 'y')) // must be 'y', "y" raises a compile error
    { 
      escape = true;
    }
  } // end of while loop

	return(0);

}

/************************************************
|                  findMedian                   |
| Finds the Median in an array and returns it!  |
| PRE: Int array w/ odd number of elements      |
| POST: returns the median of the array         |
************************************************/
int findMedian(int anArray[], int length)
{
	int median;
	bool medianFound = false;
	if(length <= 0)
	{
		medianFound = true;
	}
	else
	{
		quickSort(anArray, 0, length, length, medianFound);//first length is the last element in the set of data of anArray
	}
	if(medianFound == true)
		median = anArray[((length) / 2)];
	else
		median = -1;
	return(median);
}

/******************************************************
|                  swapIntArray                       |
| Takes and array by reference and 2 indexes(x and y) |
| swaps the values of array[x] and array[y]           |
| Return: void                                        |
******************************************************/
void swapIntArray(int anArray[], int x, int y)
{
	//pre : requires an integer array, X and Y must be in the array
	//post: swaps the X and Y elements of anArray
  int tempX = anArray[x];
	int tempY = anArray[y];
	anArray[x] = tempY;
	anArray[y] = tempX;
}

/******************************************************
|                  quickSort                          |
| pages 479-481 - Quicksort                           |
| Pass by reference!                                  |
******************************************************/

void quickSort (int anArray[], int first, int last, int length, bool &medianFound)
{
	// first is the start of the sub array, last is the end of the sub array

	int pivot = first;            // index of pivot
	int startS1 = first + 1;      // starting of S1, which is the index of elements in anArray which are less than the pivot
	int endS1 = first + 1;        // starting of S2, which is the index of elements in anArray which are greater than the pivot, this is also the end of S1
                            
  // if first is equal to last, then we have hit a base case, this occures if there is only one element in the subarray and it is not the median

	if((first >= last) || (medianFound)) //median found stops the function from recursing if the median has been found in a previous recursion
	{
		if(pivot == ((length)/2))
		{
			medianFound = true;
		}
		return;
	}

	for(int i = startS1; i<=last; i++) // checks if the value is less than the pivot, if it is then its moved towards the left of the array populating S1
	{
		if(anArray[i] < anArray[pivot]) // 
		{
			swapIntArray(anArray, i, endS1);
			endS1 = endS1 + 1;
		}
	}
  
	swapIntArray(anArray, pivot, endS1-1); //endS1 -1 is the last element in the S1 subarray, doing this moves the pivot to the middle
	
  quickSort(anArray, first, (endS1 - 1), length, medianFound); //quick sorts S1
	quickSort(anArray, endS1, last, length, medianFound); //quick sorts S2
}


/******************************************************
|                  getArray                           |
| Pass by reference w/ size, couts the array          |
******************************************************/

void getArray(int anArray[], int length, int x, int y)
{
  for(int i=0;i<length;i++)
  {
    if((i == x) ||(i == y))
      cout << "|" << anArray[i] << "| ";
    else
      cout << "'" << anArray[i] << "' ";
  }
  cout << endl;
}
/*
Program Output:
------------------------------------------------------------
Admin$ ./a.out 
Enter the number of items (please enter an odd number): 9
Enter 9 integers:20  30  10  -40  80  0  25  15  60
The median is value is 20.
Go again (y/n)? y
Enter the number of items (please enter an odd number): 12
12 is not an odd number.
Go again (y/n)? y
Enter the number of items (please enter an odd number): 11
Enter 11 integers:27  35  48  15  -46  -58  5  26  58  -2  25
The median is value is 25.
Go again (y/n)? y
Enter the number of items (please enter an odd number): 9
Enter 9 integers:80  60  30  25  20  15  10  0  -40
The median is value is 20.
Go again (y/n)? n
*/
