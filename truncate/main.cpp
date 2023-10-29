#include <iostream>

int main()
{
    // all of the floating point variables will be truncated at 6 digits
    std::cout << 9.87654321f << '\n'; 
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << '\n';

    return 0;
}
