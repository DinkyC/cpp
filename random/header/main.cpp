#include "random.h"
#include <iostream>

int main()
{
    // We can use Random::get() to generate random numbers
    std::cout << Random::get(1, 6) << '\n'; // returns int between 1 and 6
    std::cout << Random::get(1u, 6u) << '\n'; // returns unsigned int between 1 and 6
    
    // The following uses a template type argument 
    std::cout << Random::get<std::size_t>(1, 6u) << '\n'; // returns std::size_t between 1 and 6

    // We can access Random::mt directly if we have our distribution
    std::uniform_int_distribution<> die6{ 1, 6 };

    for (int count{ 1 }; count <= 10; ++count)
    {
        std::cout << die6(Random::mt) << '\t';
    }

    std::cout << '\n';

    return 0;


}
