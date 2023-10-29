#include <iostream>

int main()
{
    bool b{};
    std::cout << "Enter a boolean value: ";
    std::cin >> b; // this only takes 0 or 1
    std::cout << "You entered: " << b << '\n'; // this will evaluate the truth value

    return 0;
}
