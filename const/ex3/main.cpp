#include <iostream>

int main()
{
    const int x { 3 }; // x is a compile-time const
    const int y { 4 }; // y is a compile-time const

    const int z { x+y }; // x + y is a constant expression, so z is compile-time const

    std::cout << z << '\n';

    return 0;
}
