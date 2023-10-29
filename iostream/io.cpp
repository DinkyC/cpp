#include <iostream>

using namespace std;

// Function declation 

namespace A 
{
	int testin()
	{
		std::cout << "Hi" << std::endl;

		// This clears the cache
		std::cout << "This is the beginning of the end motherfucker" << std::endl;

		// This just jumps to the next line
		std::cout << "This is some other memory shit" << "\n";

		return 0;
	}
}


namespace B
{
	int outin()
	{

		std::cout << "Enter a number: ";  

		int x{ };
		int y{ };

		std::cin >> x >> y;

		// Can enter multiple values 
		std::cout << "You entered " << x << " and "<< y << "\n";

		return 0;

	}
}


int main()
{
   A::testin() ;
   B::outin();
   
   return 0;
}
