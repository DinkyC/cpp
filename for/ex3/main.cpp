#include <iostream>

int main()
{
    // can have multiple init or incrementors
    for (int x{ 0 }, y{ 9 }; x < 10; ++x, --y) {
        std::cout << x << ' ' << y << '\n'; 
    }

    return 0;
}
