#include <iostream>

// readNumber() -- Get user input 
// writeAnswer() -- Output answer
// main() -- Glue functions above together 
// Goal -- Read input from user, calculate addition and output answer

std::pair<int, int> readNumber() { // std::pair is used to intialize two variables, i.e. a pair of values

	std::cout << "Please enter first value ";
	int a = {};
	std::cin >> a;

	std::cout << "Please enter second value ";
	int b = {};
	std::cin >> b;

	return std::make_pair(a, b); // This is how you would return the given pair 
}

int writeAnswer(int a, int b) {
	return a + b; 
}

int main() {
	std::pair<int, int> values = readNumber(); // set a pair of values again
	std::cout << writeAnswer(values.first, values.second) << std::endl; // second and first values can be accessed this way

	return 0;

}
