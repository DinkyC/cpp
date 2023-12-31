#include <iostream>

//  favor while loops over do-while-loop since the evaluation is at the end

int main()
{
    // selection must be declared outside of the do-while-loop, so we can use it later
    int selection{};
    
    do {
        std::cout << "Please make a selection: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> selection;
    } while (selection != 1 && selection != 2 && selection != 3
            && selection != 4);

    // do something with selection here
    // such as switch statement

    std::cout << "You selected option #" << selection << '\n';

    return 0;
}
