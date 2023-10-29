#include <iostream>
// Similar to a typical if else statement
// Convient way of compacting the if else statement
// Be carefull of type conversions

int main()
{
    constexpr bool inBigClassroom { false };
    constexpr int classSize { inBigClassroom ? 30 : 20 };
    std::cout << "The class size is: " << classSize << '\n';

    return 0;
}
