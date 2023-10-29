#include <iostream>
#include <string> // for std::string

int main()
{
    using namespace std::string_literals; // easy access to the s suffix 

    std::cout << "foo\n"; // no suffix is a C-style string literal
    std::cout << "goo\n"s; // s suffix is a std::string literal

    return 0;
}
