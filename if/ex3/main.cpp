#include <iostream>

bool isEqual(int x, int y)
{
    return (x == y); // operator == returns true if x equals y, and false otherwise

}

int main()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y {};
    std::cin >> y;

    if (isEqual(x, y)) // now this program uses if and else statements to determine statements
        std::cout << x << " and " << y << " are equal\n";
    else
        std::cout << x << " and " << y << " are not equal\n";

    return 0;
}
