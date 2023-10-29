#include <iostream>

namespace Foo 
{
    namespace Goo 
    {
        int add(int x, int y)
        {
            return x + y;
        }
    }
}

namespace Foo::Goo // Nested namespace can also be defined this way in c++ 17
{
    int minus(int x, int y)
    {
        return x - y;
    }
}

int main()
{
    std::cout << Foo::Goo::add(1, 2) << std::endl;
    std::cout << Foo::Goo::minus(3, 2) << std::endl;
    return 0;
}
