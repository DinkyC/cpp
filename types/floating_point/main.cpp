#include <iostream>

int main()
{
	std::cout << 5.0 << '\n'; // If there is a zero at the end it will be cut off
	std::cout << 6.7f << '\n'; // String literal
	std::cout << 9876543.21 << '\n'; // This will be printed in scientific notation
	
	return 0;
}
