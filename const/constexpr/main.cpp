#include <iostream>
/* 
 * Any variable that should not be modifiable after initialization and whose initializer is known at compile-time should be declared as constexpr.
 * Any variable that should not be modifiable after initialization and whose initializer is not known at compile-time should be declared as const
 */


int five()
{
    return 5;
}

int main()
{
    constexpr double gravity { 9.8 }; // ok: 9.8 is a const
    constexpr int sum { 4 + 5 }; // ok: 4 + 5 is a const
    constexpr int something { sum }; // ok: sum is a const

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    constexpr int myAge { age }; // compile error: age is not a const expr
    constexpr int f { five() }; // compile error: return value of five() is not a constexpr

    return 0;
}
