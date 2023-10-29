#include <iostream>
#include <cmath> // for sqrt() function

int main()
{
    double x{};
tryagain:
    std::cout << "Enter a non-negative number: ";
    std::cin >> x;

    if (x < 0.0) {
        goto tryagain;
    }

    std::cout << "The square root of " << x << " is " << std::sqrt(x) << '\n';

    return 0;
}
