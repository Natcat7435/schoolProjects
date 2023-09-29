#include <iostream>
#include <iomanip>
using namespace std;

// This program uses a structure to hold data about a rectangle
// It calculates the area and perimeter of a box

// Natalie Swartz

// Fill in code to declare a structure named dimensions that
// contains 2 float members, length and width
struct dimensions {
  float length;
  float width;
};

struct results {
  float area;
  float perimeter;
};
// Fill in code to declare a structure named rectangle 
struct rectangle {
  results values;
  dimensions sizes;
};

float compute_area(float length, float width)
{
  return length * width;
}

float compute_perimeter(float length, float width)
{
  return (2 *length) + (2 * width);
}

int main()
{
	// Fill in code to define a rectangle structure variable named box.
  rectangle box;

	cout << "Enter the length of a rectangle: ";

	// Fill in code to read in the length to the appropriate location
  cin >> box.sizes.length;

	cout << "Enter the width of a rectangle: ";

	// Fill in code to read in the width to the appropriate location
  cin >> box.sizes.width; 


	// Fill in code to compute the area and store it in the appropriate
	// location
box.values.area = compute_area(box.sizes.length, box.sizes.width);
	// Fill in code to compute the perimeter and store it in the
	// appropriate location
box.values.perimeter = compute_perimeter(box.sizes.length, box.sizes.width);
	cout << fixed << showpoint << setprecision(2);

	cout << "The area of the rectangle is " << box.values.area << endl;

	cout << "The perimeter of the rectangle is " << box.values.perimeter
		 << endl;

	return 0;
}