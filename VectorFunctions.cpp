/**********************
Program title: Vector Functions
Date: 08/29/2023
Description: This program creates a vector with random integers and performs various functions on the vector including sort, reverse, remove elements, and calculates the average. The vector will be displayed to the screen throughout the program to demonstrate how the vector changes throughout the program.
**********************/

#include "VectorHeader.h"

	// populate the vector with VECTOR_SIZE number of random integers of value between 1 and 100
	// pass by ref ensures vector is returned with values to calling program
void initializeVector(std::vector<int>& numbers) { 
	srand(time(0)); // seed the random number
	// put this in a loop to populate the vector with VECTOR_SIZE (ie 10) number of values
	for (int i = 0; i < VECTOR_SIZE; i++) {

		int randomNumber = rand() % MAX_VALUE + 1;//returns random numbers between 1 and 100;
		numbers.push_back(randomNumber); // adds random values to the vector
	}
}

	// use  sort on this  vector database from the begining to the end.
void sortVector(std::vector<int>& numbers) {    
	sort(numbers.begin(), numbers.end()); // uses iterators to to traverse the vector
}

//  reverse this vector database
void reverseVector(std::vector<int>& numbers) {   
	reverse(numbers.begin(), numbers.end()); //  uses iterators to to traverse the vector
}

// display the vector contents by iterating through the vector
void displayVector(std::vector<int>numbers) {     
	for (auto iter = numbers.begin(); iter < numbers.end(); iter++) // the for loop will use iterators to traverse the vector 
		std::cout << *iter << " "; // derefernces the iterator to display the value in each position of the vector
  std::cout << std::endl; // starts a new line 
}

// remove the number with the least value
void removeLowest(std::vector<int>& numbers) {   
	numbers.pop_back(); // The sort function rearranged the numbers in descending order so the lowest number is the last number in the vector. The pop_back function will remove the last value in the vector.
}

	// display the calculated average of the values
void displayResults(double value) {
	std::cout << "The average is " << value; //displays the average to the screen based on the calculations from calculateAverage function
}

// calculate the average of the vector contents
double calculateAverage(std::vector<int>numbers) { 
	int total = 0; // variable to hold the sum of the numbers in the vector
	double value = 0; // variable to hold the average of the numbers in the vector
	for (int i = 0; i < numbers.size(); i++) { // a for loop that traveses the vector until the last number
		total += numbers[i]; //this expression will add each number in the vector to find the sum
		value = static_cast<double>(total/numbers.size()); //this expression will find the average of the vector by dividing the sum and number of elements in the vector. 
	}
	//return the value
	return value;
}
