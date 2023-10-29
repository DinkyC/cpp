#include <iostream>

void print(int x) // print now takes an int parameter 
{
    std::cout << x << '\n';
}

bool compare(double x, double y)
{
    if (x == y){
        std::cout << "True" << std::endl;
    }

    return true;
}

int main()
{
    bool x{ compare(11.55, 12.77) };
    std::cout << x;
    return 0;
}
