#include<iostream>
#include<vector>
#include "CustomFunctions.h"
#include<fstream>
#include<sstream>
#include<cmath>

int main(){
    
    // read data from file
    std::string filename = "input2D_float.txt";
    std::vector<std::vector<float>> data = read_data(filename);
    
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
    
    return 0;
}







// std::vector<std::vector<float>> read_data(std::string filename){
//     // INPUT: filename - file name as string
//     // OUTPUT: raw_data - vector of vectors containing coordinate pairs as floats
//     //         from data, first line skipped
    
//     // **OPEN INPUT FILE**
//     std::ifstream fileReader;
//     fileReader.open(filename);

//     //check for success
//     if (fileReader.fail()){

//         // if fail, print error in terminal and exit
//         std::cout << "File Opening Failed" << std::endl;
//         exit(1);
//     }
//     else {

//         // if success, print message to terminal
//         std::cout << "File Opened Successfully" << std::endl;
//     }
    
//     // **READ DATA**

//     // prepare string for parsing each line of file
//     std::string line;
//     //prepare data structure for storage
//     std::vector<std::vector<float>> raw_data;

//     // skip the first line (more efficient than checking the data type each call)
//     std::getline(fileReader, line);

//     // extract each line of CSV as string (mapped to 'line')
//     while(std::getline(fileReader, line)){

//         // create vector to store coordinate pairs
//         std::vector<float> row;
        
//         // treat line as stream
//         std::stringstream ss(line);
//         std::string cell;

//         // convert cell data from string to float and add to row to give [x,y] data pairs
//         while(std::getline(ss,cell,',')){

//             // add each coordinate to intermediate vector
//             row.push_back(std::stof(cell));
//         }

//         // add each coordinate pair to full vector storing coordinate pairs as subvectors
//         raw_data.push_back(row);
//     }

//     fileReader.close();
//     return raw_data;
// }

// void print_data(std::vector<std::vector<float>> data){
//     // INPUTS:
//     //  *   data - data in the form of a vector of vectors containing coordinate pairs 
//     //      as floats from data, first line skipped

//     // OUTPUT: first n coordinate pairs printed to terminal
    
//     int n;
//     std::cout << "Number of lines to print = ";
//     std:: cin >> n;
    
//     if (n > data.size()){
//         std::cout << "Invalid Number of Lines: Number of lines is larger than data file" << std::endl;
//         n = 5;
//     }

//     // Title data:
//     std::cout << std::endl << "x,y Data:" << std::endl << std::endl;

//     for (int i=0; i<n; ++i){

//         for (int j=0; j<data[i].size(); ++j){

//             std::cout << data[i][j] << " ";
//         }
        
//         std::cout << std::endl;
//     }
// }

// float get_magnitude(std::vector<float> coords){
//     double x,y;
//     x = coords[0];
//     y = coords[1];

//     return sqrt(pow(x,2)+pow(y,2));
// }

// std::vector<float> get_all_data_magnitudes(std::vector<std::vector<float>> data){
    
//     std::cout << "Magnitudes: " << std::endl << std::endl;
//     std::vector<float> all_magnitudes;
//     for (int i=0; i<data.size(); ++i){

//         std::vector<float> coords = data[i];
//         double magnitude = get_magnitude(coords);
//         all_magnitudes.push_back(magnitude);
//         std::cout << magnitude << std::endl;
//     }

//     return all_magnitudes;
// }

// std::vector<float> least_squares_linear_fit(std::vector<std::vector<float>> data){

//     // extract x and y data into separate arrays
//     double x_sum, y_sum, x_sq_sum, xy_sum = 0;

//     for (int i=0; i < data.size(); ++i){
//         x_sum += data[i][0];
//         x_sq_sum += pow(data[i][0],2);
//         y_sum += data[i][1];
//         xy_sum += data[i][0]*data[i][1];
//     }

//     double N = data.size();

//     double ls_denominator = N*x_sq_sum-x_sum*x_sum;
//     double p = (N*xy_sum - x_sum*y_sum)/ls_denominator;
//     double q = (x_sq_sum*y_sum - xy_sum*x_sum)/ls_denominator;
//     std::cout<<std::endl<<"Linear Fit:  "<<"y = "<< printf("%.5f", p) <<"x + "<< printf("%.5f", q) <<std::endl;

//     std::vector<float> lin_params;
//     lin_params.push_back(p);
//     lin_params.push_back(q);
//     return lin_params;
// }