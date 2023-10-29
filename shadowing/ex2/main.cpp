#include <iostream>

int value { 5 }; // global variable

void foo()
{
    std::cout << "global value: " << value << std::endl;
    // value is not shadowed here, so this refers to the global value
}

int main()
{
    int value { 7 }; // hides the global variable value until the end of this block

    ++value; // increments local value, not global value

    std::cout << "local variable value: " << value << std::endl;
    
    foo();

    return 0;
} // local value is destroyed
