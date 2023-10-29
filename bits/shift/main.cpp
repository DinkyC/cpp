#include <bitset>
#include <iostream>

int main()
{
    std::bitset<4> x { 0b1100 };
    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
    std::cout << (x << 1) << '\n'; // shift left 1, yielding 1000

    return 0;
}
