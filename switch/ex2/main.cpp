#include <iostream>

bool isVowel(char c)
{
    switch (c)
    {
        case 'a': // if c is 'a'
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
    }
}

int main()
{
    
    char d; // can make a definition but can not instantiate with {} prior to switch
    std::cout << "Pleaee enter a letter: ";
    std::cin >> d;

    if (isVowel(d)) {
        std::cout << "yep";
    }
    else {
        std::cout << "nah";
    }

    return 0;
}
