#include <iostream>
#include <cmath>
float multiply(int x, float y);

int main()
{
	int num1 = 2000000;
	float num2 = 444.3233;
	std::cout << "The sum of 2,000,000 X 444.3233 is: " << static_cast<int>(round(multiply(num1, num2)));

	return 0;
}

