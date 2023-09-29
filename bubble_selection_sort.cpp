#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>
using namespace std;

// the sort functions 
void bubbleSort(int theArray[], int arrayLength);
void selectionSort(int theArray[], int arrayLength);

// the provided helper functions
void randomFillArray(int theArray[], int arrayLength);
void startTimer();
int endTimer();


chrono::time_point<chrono::high_resolution_clock> startTime;


// The length of the arrays - change this as needed
const int ARRAY_LENGTH = 20000;


int main() {
    // COMPLETE THIS FUNCTION'S CODE
    cout << "Natalie Swartz" << endl << endl;
    // Create one array
    int randomValues[ARRAY_LENGTH];
    int randomValuesCopied[ARRAY_LENGTH];
    // Fill the array with random numbers
    randomFillArray(randomValues, ARRAY_LENGTH);
    // Make an exact copy of the array
    for(int i = 0; i < ARRAY_LENGTH; i++)
    {
      randomValuesCopied[i] = randomValues[i];
    }

  // Sort one of the arrays using bubble sort and keep track of how long it took
    startTimer();
    bubbleSort(randomValues, ARRAY_LENGTH);
    int bubbleTime = endTimer();
    // Sort the other array using selection sort and keep track of how long it took
    startTimer();
    selectionSort(randomValuesCopied, ARRAY_LENGTH);
   int selectionTime = endTimer();
    // Output the results
   cout << "bubble sort took about " << bubbleTime << " milliseconds on average and selection sort took about " << selectionTime << " milliseconds on average. ";  
    return 0;
}

// sorts the array argument using the bubble sort algorithm
void bubbleSort(int theArray[], int arrayLength) {
  int maxElement;
  int i;
  
  for(maxElement = arrayLength - 1; maxElement > 0; maxElement--) 
    {
      for(i = 0; i < maxElement; i++)
        {
          if(theArray[i] > theArray[i + 1])
          {
            swap(theArray[i], theArray[i + 1]);
          }
        }
    }
}

// sorts the array argument using the selection sort algorithm
void selectionSort(int theArray[], int arrayLength) {
   int minIndex, minValue;
  for(int i = 0; i < (arrayLength - 1); i++)
   {
     minIndex = i;
     minValue = theArray[i];
     for(int j = i + 1; j < arrayLength; j++)
       {
         if(theArray[j] < minValue)
         {
           minValue = theArray[j];
           minIndex = j;
         }
       }
     swap(theArray[minIndex], theArray[i]);
   }
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

/**
 * Helper functions:
 * You may use any of the functions below in your program
 * You do not need to make any changes to the helper functions
 */

// fills an array with random integers
void randomFillArray(int theArray[], int arrayLength) {
    // sets the random number seed
    srand(time(0));

    // fills the array with randomly generated numbers
    for (int i = 0; i < arrayLength; i++) {
        theArray[i] = rand();
    }
}

// sets the beginning point for the timer
void startTimer() {
    startTime = chrono::high_resolution_clock::now();
}

// returns how much time has passed since the timer was started in milliseconds (1000 milliseconds == 1 second)
int endTimer() {
    chrono::time_point<chrono::high_resolution_clock> endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
    return duration.count();
}

