#include <iostream>
#include <string>

std::string getName()
{
    std::cout << "Please enter you full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    return name;
}

long int lenOfName(std::string name)
{
    long int name_len{};

    name_len = std::ssize(name);

    return name_len;
}

int getAge()
{
    std::cout << "Please enter you age: ";
    int age;
    std::cin >> age;

    return age;
}

int main()
{
     
    std::string name { getName() };

    int age { getAge() };

    long int name_len { lenOfName(name) };

    std::cout << "You age + length of name is: " << name_len + age << std::endl; 

    return 0;
}
