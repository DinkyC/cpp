#include <iostream>

int main(){
	int sum = 0, value = 0;
	// read until there is either a keyboard interuption or an incorrect input is given
	while (std::cin >> value)
		sum += value; // equivalent to sum = sum + value
	std::cout << "Sum is: " << sum << std::endl;
	return 0;
}
