int add(int x, int y)
{ // start block
    return x + y;
} // end block (no semicolon)

int main()
{ // start block
    
    // multiple statements
    int value { 3 }; // this is initialiation, not a block
    add(value, 4);

    { // inner/nested block
        add(5, 5);
    } // end inner/nested block

    return 0;
} // end block (no semicolo)
