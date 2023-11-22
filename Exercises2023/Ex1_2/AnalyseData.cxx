#include<iostream>
#include<vector>
#include "CustomFunctions.h"
#include<fstream>
#include<sstream>
#include<cmath>

int main(){
    
    // read data from file
    std::string filename = "input2D_float.txt";
    std::vector<std::vector<double>> data = read_data(filename);
    
    // ask user whether to print or read magnitudes
    int user_input1;
    std::cout << "Would you like to print (0) or find the magnitudes (1) of the data? ";
    std::cin >> user_input1;

    while (user_input1 != 0 and user_input1 != 1){
            std::cout << "Incorrect input. Please input 0 to print data, 1 to get data magnitudes" << std::endl;
            std::cin >> user_input1;
        }
    
    if (user_input1 == 0){

        print_data(data);
    } else{

        get_all_data_magnitudes(data);
    }

    // least squares fit
    std::vector<double> lin_params = least_squares_linear_fit(data);
    
    return 0;
}
