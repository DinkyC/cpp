#include <iostream>
#include <unistd.h>

int main()
{
	int SomeArray[10] = {};

	int *pLocation6 = &SomeArray[6]; // getting the address 
	int *pLocation0 = &SomeArray[0];
	
	std::cout << "pLocation = " << (int*)pLocation6 << std::endl; // deallocate
	std::cout << "pLocation0 = " << (int*)pLocation0 << std::endl;
	// There is no real control of where in memory things are being stored
	std::cout << "Difference = " << pLocation6 - pLocation0 << std::endl;

	std::cout << std::endl; 
	
	usleep(10000 *30);

	return 0;
}
