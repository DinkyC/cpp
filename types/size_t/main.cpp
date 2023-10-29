#include <cstddef> // for std::size_t
#include <iostream>

int main()
{
	std::cout << sizeof(std::size_t) << '\n'; // This is the size of the largest creatable object on this archetecture 

	return 0;
}
