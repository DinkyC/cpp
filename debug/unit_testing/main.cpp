#include <iostream>

int add(int x, int y) {
	return x + y;
}

void testadd() { // These are the unit test to see if the add() function performs properly on some edge cases 
	std::cout << "This function should print: 2 0 0 -2\n";
	std::cout << add(1, 1) << " ";
	std::cout << add(-1, 1) << " ";
	std::cout << add(1, -1) << " ";
	std::cout << add(-1, -1) << " ";
}

int main() {
	testadd();

	return 0;
}
