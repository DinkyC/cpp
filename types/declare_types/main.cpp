#include <iostream>

int main() {
    char d[2] = "h"; // An array of characters with a size of 2 bits
    decltype(d) another_d; // declare the type for more predictable results

    int c = 1;
    decltype(c) another_c;

    int *e = &c;
    decltype(e) another_e;

    const int i = 24;
    decltype(i) another_i = i;

    auto j = i;
    decltype(j) another_j = i;

    std::cout << "Type of d: " << typeid(d).name() << std::endl; // type should be of size 2 and type char (c)
    std::cout << "Type of another_d: " << typeid(another_d).name() << "\n" << std::endl; // same as above 

    std::cout << "Type of c: " << typeid(c).name() << std::endl; // type should be an int
    std::cout << "Type of another_c: " << typeid(another_c).name() << "\n" << std::endl; 

    std::cout << "Type of e: " << typeid(e).name() << std::endl; // type is a pointer to an integer (Pi)
    std::cout << "Type of another_e: " << typeid(another_e).name() << "\n" << std::endl; // same as above 

    std::cout << "Type of i: " << typeid(i).name() << std::endl; // type is an integer (i)
    std::cout << "Type of another_i: " << typeid(another_i).name() << "\n" << std::endl; // same as above

    std::cout << "Type of i: " << typeid(j).name() << std::endl; // type is an integer (i)
    std::cout << "Type of another_i: " << typeid(another_j).name() << "\n" << std::endl; // same as above


    return 0;
}

