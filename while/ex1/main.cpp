#include <iostream>

int main()
{
    int count{ 1 };
    while (count <= 10) {
        std::cout << count << ' ';
        ++count;
    }
    std::cout << "done!\n";
    
    return 0;
}
