#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
int findMedian (int anArray[], int first, int last, int length);
void swapIntArray (int anArray[], int x, int y);
void getArray(int anArray[],int length);


int main()
{
	int length; // length of the array
  bool escape = false;
  string yn;
  int array [0];
  
  while (escape == false)
  {
    cout << "Enter the number of items (please enter an odd number): ";
    cin >> length;
    
    // length is ODD, begin the collection!
    if( length % 2 != 0 )
    {
      cout << "Enter " << length << " integers:";
      for(int i=0;i<length;i++)
      {
        cin >> array[i];
      }
      // quickSort the array
      getArray(array, length);// array output for debugging
    }

    else // length is EVEN
    {
      cout << length << " is not an odd number.\n";
    }
    
    cout << "Go again (y/n)? "; // quit?
    
    cin >> yn;
    if(yn.find("y"))
      escape = true;
  } // end of while loop

	return(0);

}

/************************************************
|                  findMedian                   |
| Finds the Median in an array and returns it!  |
| PRE: Int array w/ odd number of elements      |
| POST: returns the median of the array         |
************************************************/

int findMedian (int anArray[], int first, int last, int length)
{
	// first is the start of the sub array, last is the end of the sub array
	
	int pivot = first;        // index of pivot
	int startS1 = first;      // starting of S1, which is the index of elements in anArray which are less than the pivot
	int endS1 = first + 1;    // starting of S2, which is the index of elements in anArray which are greater than the pivot, this is also the end of S1
                            
  // if first is equal to last, then we have hit a base case, this occures if there is only one element in the subarray and it is not the median

	cout<< "false";

	for(int i = startS1; i<=last; i++) // checks if the value is less than the pivot, if it is then its moved towards the left of the array populating S1
	{
		if(anArray[i] < anArray[pivot]) // 
		{
			swapIntArray(anArray, i, endS1);
			endS1 = endS1 + 1;
		}
	}
	swapIntArray(anArray, pivot, endS1-1); //endS1 -1 is the last element in the S1 subarray, doing this moves the pivot to the middle
	pivot = endS1 -1; //used to check for median
	if (pivot == (length/2)) //length/2 gets the middle of the array
		return (pivot);
	else
		return (findMedian(anArray,first,endS1,length)); //quick sorts S1
		return (findMedian(anArray,endS1,last,length)); //quick sorts S2
	
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

/*
function quicksort('array')
      if length('array') ? 1
          return 'array'  // an array of zero or one elements is already sorted
      select and remove a pivot value 'pivot' from 'array'
      create empty lists 'less' and 'greater'
      for each 'x' in 'array'
          if 'x' ? 'pivot' then append 'x' to 'less'
          else append 'x' to 'greater'
      return concatenate(quicksort('less'), 'pivot', quicksort('greater')) // two recursive calls
*/


/******************************************************
|                  getArray                           |
| Pass by reference w/ size, couts the array          |
******************************************************/

void getArray(int anArray[],int length)
{
  for(int i=0;i<length;i++)
  {
    cout << anArray[i] << " ";
  }
  cout << endl;
}
