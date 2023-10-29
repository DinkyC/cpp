#include <iostream>

int add(int, int); // forward declation of add function. This doesn't require actual vriabes

int main()
{
	std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';

	return 0;
}

int add(int x, int y) // regualarly define the function below
{
	return x + y;
}
