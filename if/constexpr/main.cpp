#include <iostream>
// Evaluated at compile time
int main()
{
    constexpr double gravity{ 9.8 }; // won't compile since it is comparing floats

    if constexpr (gravity == 9.8) // now using constexpr if
        std::cout << "Gravity is normal.\n";
    else
        std::cout << "We are not on Earth.\n";

    return 0;
}
