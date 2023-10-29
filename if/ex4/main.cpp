#include <iostream>
// Always be sure when nesting to not get any dangling else statements
// One can also flatten the logic by using else if statements
int main()
{
    std::cout << "Enter a name: ";
    int x{};
    std::cin >> x;

    if (x >=0)
    {
        if (x <= 20)
            std::cout << x << " is between 0 and 20\n";
        else // attach to inner if statement 
            std::cout << x << " is greater than 20\n";
    }
    else // attach to outer if statement 
        std::cout << x << " is negative\n";

    return 0;
}
