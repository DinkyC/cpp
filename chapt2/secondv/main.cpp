#include <iostream>


int readValue() {
	std::cout << "Enter value here: ";
	int a{};

	std::cin >> a;

	return a;

}


int addValue(int a, int b) {
	return a + b;
}


int main(){
	int x { readValue() };

	int y { readValue() };
	
	// Be sure to output the value that you want to see 
	std::cout << addValue(x, y) << std::endl;  

	return 0;

}
