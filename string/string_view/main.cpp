#include <iostream>
#include <string_view>
// This allows you to print and init a str variable w/o copying 
// str provides read-only access to whatever argument is passed in
// Can be init with many different types
void printSV(std::string_view str) // now a std::string_view
{
    std::cout << str << '\n';
} 

int main()
{
    std::string_view s{ "Hello, world!" }; 
    printSV(s);

    return 0;
}
