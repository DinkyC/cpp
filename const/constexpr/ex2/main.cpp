#include <iostream>
#include <type_traits> // for std::is_constant_evaluated

constexpr int greater(int x, int y) // now a constexpr function
{
    return (x > y ? x : y);
}

constexpr int someFunction()
{
    if (std::is_constant_evaluated()) // if compile-time evaluation
        // do something
    else // run-time evaluation
         // do something else
}

// in order to be evaluated at compile-time all of the variables and functions need to be consexpr
// can be run-time or compile-time
int main () 
{
    constexpr int x{ 5 };
    constexpr int y{ 6 };

    constexpr int g { greater(x, y) };
    
    std::cout << g << " is greater" << std::endl; // will be evaluated at compile-time

    return 0;
}
