#include <iostream>

int main()
{
    int y { 5 }; // we're declaring y here because we need it in this outer block layer

    {
        int x{};
        std::cin >> x;
        // if we declared y here, immediately before its actual first use ...
        if (x == 4)
            y = 4;
    } // ... it would be destroyed here 
    std::cout << y << std::endl; // and we need y to exist here 

    return 0;
}
