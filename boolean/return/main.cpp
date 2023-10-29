#include <iostream>

bool isEqual(int x, int y) // This is conventional naming 
{
    return (x == y); // Checks the truth value of this expression
}

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    std::cout << std::boolalpha; // Display as true or fale instead of 0 or 1

    std::cout << x << " and " << y << " are equal? " << std::endl;
    std::cout << isEqual(x, y) << std::endl; // Apply function 

    return 0;

}
