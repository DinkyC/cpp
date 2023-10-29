#include <iostream>

double speed(double t)
{
    double acceleration{ 9.8 };

    double final_velocity{ acceleration * t };

    return final_velocity;

};

double height()
{
    std::cout << "Please enter a distance: ";
    int h;
    std::cin >> h;
    
    return h;
};

double falling(double &h, double &t)
{
    while (t > 0)
    {
        for (double i = 1; i <= t; i++){
            
            double v = speed(i);

            if (h <= 0){
                std::cout << "The current height is: " << h << std::endl;
                h -= v;
                t--;
            }
            else{
                break;
            }
        }
    }
    
    return h;
};

double time()
{
    std::cout << "Please enter a time: ";
    int t;
    std::cin >> t;
    
    return t;

};

int main()
{
    double h{ height() };

    double t{ time() };
    h = falling(h, t);

    return 0;

};
