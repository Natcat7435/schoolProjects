#include <iostream>
using namespace std;

int findMode(int* pointer, int size)
{
  int mode;
  int recorder = 0;  // counts number of repeats
  int tempRecord = 0; // counts number of repeats in nested loop
  for(int i = 0; i < size; i++)
    {
    for(int j = i; j < size; j++)
      {
        if(i != j && *(pointer + i) == *(pointer + j))
        {
          recorder++;
          if(recorder > tempRecord)
            mode = *(pointer + i);
          tempRecord = recorder;
        }
        recorder = 0;
      }
    }
  if(tempRecord == 0)
    return -1;
  else
    return mode;
}

int main() {
   const int SIZE1 = 8;
   const int SIZE2 = 11;
   const int SIZE3 = 5;
    int list1[SIZE1] = {0,1,2,2,2,2,2,3};
    int list2[SIZE2] = {5,6,5,4,3,6,6,5,4,5,6};
    int list3[SIZE3] = {10,11,12,13,14};
    int* ptr;
    int* ptr1;
    int* ptr2;
    int mode, mode1, mode2;

  ptr = list1;
  ptr1 = list2;
  ptr2 = list3;

  mode = findMode(ptr, SIZE1);
  mode1 = findMode(ptr1, SIZE2);
  mode2 = findMode(ptr2, SIZE3);

    

   cout << "Natalie Swartz" << endl << endl;

  cout << "The first array is: " << endl;
  for(int i = 0; i < SIZE1; i++)
    {
      cout << *(ptr + i) << "  ";
    }
  if(mode != -1)
    cout << endl << "The mode is " << mode << endl << endl;
  else
    cout << endl << "This array has no mode";

  cout << "The second array is: " << endl;
  for(int i = 0; i < SIZE2; i++)
    {
      cout << *(ptr1 + i) << "  ";
    }
  if(mode1 != -1)
  { 
    cout << endl << "The mode is " << mode1 << endl << 
    endl;
  }
  else
    cout << endl << "This array has no mode";
    

    cout << "The third array is: " << endl;
  for(int i = 0; i < SIZE3; i++)
    {
      cout << *(ptr2 + i) << "  ";
    }
  if(mode2 != -1){
    cout << endl << "The mode is " << mode2 << endl << 
    endl;
  }
  else
    cout << endl << "This array has no mode" << endl;
  
  
    return 0;
}