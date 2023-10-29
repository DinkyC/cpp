#include <iostream>
// avoid numeric comparisons with != or ==
// always best practice to use the first version 

int main()
{
    for (int i{ 1 }; i < 10; ++i) { // uses <, still terminates
        std::cout << i;
        if (i == 9) ++i; // jump over value 10
    }

    for (int i{ 0 }; i != 10; ++i) { // uses !=, infinite loop
        std::cout << i;
        if (i == 9) ++i; // jump over value 10
    }
    return 0;
}
