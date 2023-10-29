#include <iostream>
#include <bitset>

int main () 
{
    // evaluates to true if either the left, right or both operands are true (1) and 0 otherwise
    std::cout << (std::bitset<4>{ 0b0101 } | std::bitset<4>{ 0b0110 }) << '\n';    
    return 0;
}
