int five()
{
	return 5;
}

int main()
{

	int a{ 2 };

	int b{ 2 + 3 };

	// Each one of these variables gets evaluated
	int c{ (2 * 3) + 4 }; 

	int d{ b };
	
	// Can call function five
	int e{ five() }; 

	return 0;

}

