#include <string> // allows use of std::string
#include <iostream>

int main()
{
    std::string name { "Alex" }; // initialize name with string literal

    name = "John"; // change name to john

    std::cout << name << std::endl;
    return 0;
}
