#include <iostream>

void print() // this print() lives in the global namespace
{
    std::cout << " there\n";
}

namespace Foo 
{
    void print() // this print() lives in the Foo namespace
    {
        std::cout << "Hello";
    }
}

int main()
{
    Foo::print(); // call print() in the Foo namespace

    ::print(); // call print() in the global namespace (same as just calling print() in this case)

    return 0;
}
