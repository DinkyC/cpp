#include <iostream>

int main()
{
    std::cout << std::boolalpha; // print bools as true or false
    
    bool b1 = 4; // copy initialization allows for implicit conversion from int to bool
    std::cout << b1 << '\n';

    bool b2 = 0; // copy initialization allows implicit conversion from int to bool
    std::cout << b2 << '\n';

    return 0;
}
