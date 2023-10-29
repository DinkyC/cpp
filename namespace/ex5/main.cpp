#include <iostream>

namespace Foo::Goo 
{
}

namespace V2 
{
    int add(int x, int y)
    {
        return x + y;
    }
}

int main()
{
    namespace Active = V2; // active now refers to V2

    std::cout << Active::add(1, 2) << std::endl; // We don't have to chage this

    return 0;
}
