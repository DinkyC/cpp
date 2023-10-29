#include <iostream>

int getValueFromUser()
{
	std::cout << "Enter an interger: ";
	int input{};
	std::cin >> input;

	return input;
}

void printDouble(int value)
{
	std::cout << value << " double is: " << value * 2 << '\n';
}

int main()
{
	int num { getValueFromUser() };

	printDouble(num);

	return 0;
}
