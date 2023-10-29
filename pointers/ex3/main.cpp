#include <iostream>

int main()
{
	int SomeArray[10] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30};

	int *pLocation0 = &SomeArray[0];

	for(int i=0; i<10; i++)
	{
		//std::cout << SomeArray + i << " = " << *(SomeArray + i) <<std::endl;

		std::cout << pLocation0 << " = " << *pLocation0 << std::endl;
		pLocation0++;
	}

	return 0;
}
