#include <iostream>

consteval int greater(int x, int y) // function is now consteval
{
    return (x > y ? x : y);
}

int main()
{
    constexpr int g { greater(5, 6) }; // ok: will evaluate at compile-time

    std::cout << g << std::endl;
    
    std::cout << greater(5, 6) << " is greater!" << std::endl; // ok: will evaluate at compile-time

    int x{ 5 };
    std::cout << greater(x, 6)<< " is greater!" << std::endl; // error: consteval functions must evaluate at compile-time
}
