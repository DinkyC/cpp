#include <iostream>

void printDigitName(int x)
{
    switch (x)
    {
        case 1:
            std::cout << "One";
            return; // exits out of the whole program 
        case 2:
            std::cout << "Two";
            return; // can replace with the break keyword
        case 3:
            std::cout << "Three";
            return;
        default: // which does not match to any case labels
            std::cout << "Unknown"; // so execution starts here
            return; // and then we return to the caller
    }
}

int main()
{
    printDigitName(2);
    std::cout << '\n';

    return 0;
}
