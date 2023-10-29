#include <iostream>

int main()
{
    bool b{ 4 }; // error: narrowing conversions disallowed
    std::cout << b << '\n';

    return 0;
}
