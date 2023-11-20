#include <iostream>
#include <cmath>
// #include <vector>

// Functions
double vector_mag(double, double);


int main() {

    // I
    std::cout << "I:" << std::endl;
    std::cout << "Hello World!!" << std::endl;
    
    // II
    
    double x,y, mag;
    x = 2.3;
    y = 4.5;
    mag = sqrt(pow(x,2)+pow(y,2));
    
    std::cout << std::endl;
    std::cout << "II:" << std::endl;
    std::cout << "vector magnitude  = " << mag <<std::endl;

    //III
    std::cout << std::endl;
    std::cout << "III:" << std::endl;
    // Get x input
    std::cout << "x = ";
    std::cin >> x;

    // Get y input
    std::cout << "y = ";
    std::cin >> y;

    // Output Length
    std::cout << "2D magnitude = " << vector_mag(x,y) << std::endl;
    std::cout << std::endl;
    return 0;
}

// Defining 2D Vector Length Operator
double vector_mag(double x, double y) {
    return sqrt(pow(x,2) + pow(y,2));
}