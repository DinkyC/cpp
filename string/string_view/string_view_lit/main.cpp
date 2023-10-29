#include <iostream>
#include <string>
#include <string_view>

int main()
{
    using namespace std::string_literals; // access the s suffix
    using namespace std::string_view_literals; // access the sv suffix

    std::cout << "foo\n"; // no suffix is a C-style string literal
    std::cout << "goo\n"s; // s suffix is a std::string literal
    std::cout << "moo\n"sv; // sv suffix is a std::string_view literal

    return 0;
}
