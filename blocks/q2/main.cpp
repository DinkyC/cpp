#include <iostream>
// best practice is to keep nesting to 3 layers
int main()
{ // block 1, nesting level 1
    std::cout << "Enter an interger: ";
    int value {};
    std::cin >> value;

    if (value > 0) 
    { // block 2, nesting level 2
        if ((value % 2) == 0) 
        { // block 3, nesting level 3
            std::cout << value << " is positive and even\n" << std::endl;
        }
        else
        { // block 4, also nesting level 3
            std::cout << value << " is positive and odd\n" << std::endl;
        }
    }

    return 0;
}
