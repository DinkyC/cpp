#include <iostream>
#include <cmath>

using namespace std; // Don't have to put std in front of output functions


int main()
{

	/* These are all different ways of assigning values to integer variables
	 * It can be asigned anyway 
	*/

	[[maybe_unused]] int x { 5 }; // Declare an unused variable 

	int width { 5 }; 

	int height = { 6 };


	int depth {}; // Intialize value to zero

	std::cout << "The Max: "<< std::max(width, height) << endl;

	return 0;
}
