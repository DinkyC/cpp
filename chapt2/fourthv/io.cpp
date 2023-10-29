#include <iostream> // have to inlude the iostream library since it is in use

// Include header guards so that there are no naming collisions 

int readNumber(){
	std::cout << "Enter a value: ";

	int a{};

	std::cin >> a;

	return a;
}

void writeAnswer(int a, int b){

	std::cout << a + b << std::endl;

}

