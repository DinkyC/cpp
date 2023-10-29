#include <iostream>

int getValueFromUser()
{

	std::cout << "Enter an integer: "; 
	int input{}; // Intialize input variable
	std::cin >> input;

	return input; // Make sure to return the variable you want
}


int main()
{

	int num { getValueFromUser() }; // Call function above 
	std::cout << num << " double is: " << num * 2 << '\n';

	return 0; // Return 0 if successfull 
}
