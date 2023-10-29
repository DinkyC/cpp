#include <iostream>

int main()
{
    std::cout << "Enter an integer: "; // remainder of the FIRST value divided by the second
    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    std::cout << "The remainder is: " << x % y << '\n';

    if ((x % y) == 0) // can check if this is evenly divisible
        std::cout << x << " is evenly divisible by " << y << '\n';
    else
        std::cout << x << " is not evenly divisible by " << y << '\n';

    return 0;
}
