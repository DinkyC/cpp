#include <iostream>

int getVal()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    return x;
}

void isEven(int val)
{
    if (val == 0)
    {
        std::cout << val << " is 0" << std::endl;
    }
    else if ((val % 2) == 0)
    {
        std::cout << val << " is even" << std::endl;
    }
    else
    {
        std::cout << val << " is odd" << std::endl;
    }
}

int main()
{
    int x{};

    x = getVal();

    isEven(x);
}
