#include <cstdint> // for fixed-width integers
#include <iostream>

int main()
{
	std::uint_fast16_t sometype { 0 };
	--sometype; // this will intentially overflow to invoke a wraparound 
	
	std::cout << sometype << '\n';

	return 0;
	
}
