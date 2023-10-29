#include <iostream>

namespace // same as below 
{
    void doSomething()
    {
        std::cout << "v1" << std::endl;
    }
}

static void doSomethingElse() // can only be accessed in this file
{
    std::cout << "v1" << std::endl;
}

int main()
{
    doSomething(); // we can call doSomething() without a namespace prefix
    doSomethingElse();

    return 0;
}
