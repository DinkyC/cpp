#include <iostream>
#include <bitset>

int main()
{
    std::cout << ~std::bitset<4>{ 0b0100 } << ' ' << ~std::bitset<8>{ 0b0100 } << '\n';
    return 0;
}
