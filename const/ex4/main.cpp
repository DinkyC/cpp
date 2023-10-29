#include <iostream>

int getNumber()
{
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y;

    return y;
}

int main()
{
    const int x{ 3 }; // x is a compile time const
    
    const int y{ getNumber() }; // y is a runtime const

    const int z{ x + y }; // x + y is a runtime expression
    std::cout << z << '\n'; // this is also a runtime expression

    return 0;
}
