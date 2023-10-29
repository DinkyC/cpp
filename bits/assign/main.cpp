#include <bitset>
#include <iostream>

int main () {

    std::bitset<4>bits { 0b0100 };
    bits >>= 1;
    std::cout << bits << '\n';
    
    return 0;
}
