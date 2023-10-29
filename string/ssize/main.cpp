#include <iostream>
#include <string>

int main()
{
    std::string name{ "Alex" };
    // This returns a signed int
    std::cout << name << " has " << std::ssize(name) << " characters\n";

    return 0;
}
