#include <iostream>

int readNumber(){
	std::cout << "Enter a value: ";

	int a{};

	std::cin >> a;

	return a;
}

void writeAnswer(int a, int b){

	std::cout << a + b << std::endl;

}
