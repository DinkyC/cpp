#include <iostream>

int main()
{
	char SomeString[] = "Hello";

	char *pSomeString = &SomeString;

	std::cout << "pSomeString = " << pSomstring << std::endl;

	char *pLocation3 = &SomeString[3];
	char *pLocation0 = &SomeString[0];

	for(i=0; i<sizeof(SomeString); i++)
	{
		std::cout << pSomeString << " = " << *pSomeString << std::endl;

		++SomString;
	}

	return 0;
}
