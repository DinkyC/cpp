#include <iostream>

// These wrap arounds can commonly happen when doing a for loop that is decremented by 1 (--)

// int is 4 bytes
int main()
{
	unsigned int x{ 2 };
	unsigned int y{ 3 };

	std::cout << x - y << '\n'; // 2 - 3 = 4294967295
	
	return 0;
}
