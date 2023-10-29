#include <iostream>

int main()
{
	unsigned u = 10, u2 = 42;
	
	// Unsigned is always going to be positive
	std::cout << u2 - u << std::endl;
	
	// This should produce the highest unsigned value since it goes to the negative
	std::cout << u - u2 << std::endl;

	int i = 10, i2 = 42;

	// These should be ok since they are int types
	std::cout << i2 - i << std::endl;
	std::cout << i - i2 << std::endl;
	
	// These produce zero
	std::cout << i - u << std::endl;
	std::cout << u - i << std::endl;

	return 0;
}
