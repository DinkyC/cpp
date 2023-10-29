#include <cstdint>
#include <iostream>

int main()
{
    constexpr std::uint8_t mask0{ 1 << 0 }; // 0000 0001
    constexpr std::uint8_t mask1{ 1 << 1 }; // 0000 0010
    constexpr std::uint8_t mask2{ 1 << 2 }; // 0000 0100
    constexpr std::uint8_t mask3{ 1 << 3 }; // 0000 1000
    constexpr std::uint8_t mask4{ 1 << 4 }; // 0001 0000
    constexpr std::uint8_t mask5{ 1 << 5 }; // 0010 0000
    constexpr std::uint8_t mask6{ 1 << 6 }; // 0100 0000
    constexpr std::uint8_t mask7{ 1 << 7 }; // 1000 0000
    
    std::cout << static_cast<bool>(mask0) << static_cast<bool>(mask1) << static_cast<bool>(mask2) << static_cast<bool>(mask3) 
        << static_cast<bool>(mask4) << static_cast<bool>(mask5) << static_cast<bool>(mask6) << static_cast<bool>(mask7) << std::endl;
}
