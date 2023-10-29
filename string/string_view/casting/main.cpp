#include <iostream>
#include <string>
#include <string_view>

void printString(std::string str)
{
    std::cout << str << '\n';
}

int main()
{
    std::string_view sv{ "Hello, world!" };

    // printString(sv); // compile error: won't implicitly convert std::string_view to a std::string

    std::string s{ sv }; // ok: we can create std::string using std::string_view init

    printString(s); // and call function with the std::string

    printString(static_cast<std::string>(sv)); // okay: we can explicitly cast a std::string_view to a std::string

    return 0;
}
