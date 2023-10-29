#include <iostream>

int main()
{
	int val = 100;

	// declare and define pointer p as a reference to the address of val
	int *p = &val;

	*p = 500; // redefine p as to point to the address to of 500
	
	// deallocate memory (derefference) and print the value of p
	std::cout << *p << std::endl; 

	return 0;

	
}
