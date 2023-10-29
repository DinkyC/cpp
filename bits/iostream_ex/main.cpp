#include <iostream>
#include <bitset>

int main()
{
    unsigned int x { 0b0110 };
    x = x << 1; // use operator<< for left shift
    std::cout << std::bitset<4>{ x } << '\n'; // use operator<< for output
    std::cout << (std::bitset<4>{ x >> 1 } ) << '\n'; // use paranethesizes 
    // << operator is overloaded
    return 0;
}
