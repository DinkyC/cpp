#include <iostream>
#include <limits>

bool isPrime(int x)
{
    if (x < 2) {
        return false;
    }
    
    for (int i=2; i*i<= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    
    return true;
}

int prompt()
{
    std::cout << "Enter a value between 0 - 9: ";
    int x {};
    std::cin >> x;
    
    // Check if the input is of the right type (integer)
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid integer: ";
        std::cin >> x;
    } 

    return x;
}

int main()
{
    int x {};
    x = prompt();
    
    while (!isPrime(x))
    {
        if (isPrime(x)){       
            break;
        }
        else if (x > 9){
            std::cout << x << " is too large" << std::endl;
        }
        else if (x < 0){
            std::cout << x << " is too small" << std::endl;
        }
        else{
            std::cout << "What you entered was just plain fucking wrong" << std::endl;
        }
        
        x = prompt();
    }
    
    std::cout << x << " is a prime number" << std::endl;

    return 0;
}
