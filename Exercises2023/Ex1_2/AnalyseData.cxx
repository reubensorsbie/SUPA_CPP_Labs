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

    // read error file
    std::string error_filename = "error2D_float.txt";
    std::vector<std::vector<double>> err_data = read_data(error_filename);
    
    // ask user whether to print or read magnitudes
    int user_input1;
    bool user_interacting = true;
    std::cout << "Would you like to print (1), find the magnitudes (2), perform linear fit(3) or exponentiate coordinates(4)?\nType (0) to exit\n";
    std::cin >> user_input1;

    while(user_interacting) {

        switch (user_input1)
        {
        case 0:
            std::cout << "Exiting Loop." << std::endl;
            user_interacting = false;
            break;

        case 1:
            print_data(data);
            break;
        case 2:
            get_all_data_magnitudes(data);
            break;
        
        case 3:
            least_squares_linear_fit(data, err_data);
            break;

        case 4:
            exponentiate_all_coords(data);
            break;
        
        default:
            std::cout << "Invalid Input" << std::endl;
            break;
        }
    }

    return 0;
}
