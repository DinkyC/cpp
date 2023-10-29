#include <iostream>

int getUserInput()
{
// Use std::cerr instead of std::cout for immediate output instead of buffered output
std::cerr << "getUserInput() called\n"; 
	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

int main()
{
std::cerr << "main() called\n";
    int x{ getUserInput() };
    std::cout << "You entered: " << x << '\n';

    return 0;
}
