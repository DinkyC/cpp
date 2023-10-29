#include <iostream>

void printInt(const int x) // don't usually make parameters const
{
    std::cout << x << '\n';
}

int main()
{
    printInt(5); // 5 will be used as the initializer for x
    printInt(6); // 6 will be used as the initializer for x 

    return 0;
}
