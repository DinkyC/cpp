#include <iostream>
#define MAX_STUDENTS_PER_CLASS 30 // This is not good practice; This is not defined at compile

int main()
{
    std::cout << "The class has " << MAX_STUDENTS_PER_CLASS << " students.\n";

    return 0;
}
