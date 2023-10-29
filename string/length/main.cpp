#include <iostream>
#include <string>

int main()
// std::string is expensive comp. if passing by value. Use parameters
{
    std::string name{ "Alex" };
    int length { static_cast<int>(name.length()) }; // cast the variable as int instead of an unsigned
    std::cout << name << " has " << length << " characters\n";

    return 0;
}
