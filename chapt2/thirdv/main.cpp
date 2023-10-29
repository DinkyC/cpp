#include <iostream>

// Forward Declarations
int readNumber(); 
int writeAnswer(int, int);

int main(){
	int x { readNumber() };
	int y { readNumber() };

	writeAnswer(x, y);

	return 0;

}
