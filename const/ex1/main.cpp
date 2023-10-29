#include <iostream>
#include <typeinfo>

int main()
{
    char d[] = "h";

    std::cout << typeid(d).name();

    return 0;
}
