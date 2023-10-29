#include <iostream>
#include <string_view> // preferred choice when string symbolic constants are needed

int main()
{
    constexpr std::string_view s{ "Hello, world!" }; // s is a string symbolic constant

    std::cout << s << '\n'; // s will be replaced with "Hello, world!" as compile time

    return 0;
}
