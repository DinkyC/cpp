#include <iostream>
#include <istream>
// This is a work around
// Uses abbreviated function template (C++20) and 'auto' return type to make this function work with any type of value

consteval auto compileTime(auto value) 
{
    return value;
}

constexpr int greater(int x, int y) // function is constexpr
{
    return (x > y ? x : y);
}

int main()
{
    std::cout << greater(5, 6) << '\n'; // may or may not execute at compile-time

    std::cout << compileTime(greater(5, 6)) << '\n'; // will execute at compile-time

    int x { 5 };
    std::cout << greater(x, 6) << '\n'; // we can still call the constexpr version at runtime if we wish

    return 0;
}

// The compiler must be able to see the full definition of a constexpr function, not just a forward declaration.
