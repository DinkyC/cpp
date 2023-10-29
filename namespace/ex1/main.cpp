#include <iostream>

namespace Foo // define a namespace named Foo 
{
    // This doSomething() belongs to namespace Foo
    int doSomething(int x, int y)
    {
        return x + y;
    }
}

namespace Goo // define a namespace named Goo 
{
    // This doSomething() belongs to namespace Goo
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

int main()
{
    // use the doSomething() that exists in namespace Foo
    std::cout << Foo::doSomething(4, 3) << std::endl;

    std::cout << Goo::doSomething(4, 3) << std::endl;

    return 0;
}
