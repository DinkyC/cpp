#include <iostream>

int main()
{ // the block here ensures block scope for i
    int i{ 1 }; // out init-statement
    while (i <= 10) // our condition
    {
        std::cout << i << ' '; // our statement 
        ++i; // our end-expression
    }

    std::cout << '\n';
}
