#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<cmath>

// overloaded print functions
void print_result(std::string result){

    std::printf("'%s'\n", result.c_str());
}


void print_result(double result){

    std::printf("%f", result);
}


void print_result(std::vector<double> result){
    
    for (int i=0; i < result.size(); ++i){
        std::printf("%f\n", result[i]);
    }
}


void print_result(std::vector<std::vector<double>> result){

    for (int i = 0; i < result.size(); ++i){
        for (int j = 0; j < result[i].size(); ++j){

            std::printf("%f ", result[i][j]);
        }
        std::cout << std::endl;
    }
}


std::vector<std::vector<double>> read_data(std::string filename){
    // INPUT: filename - file name as string
    // OUTPUT: raw_data - vector of vectors containing coordinate pairs as floats
    //         from data, first line skipped
    
    // **OPEN INPUT FILE**
    std::ifstream fileReader;
    fileReader.open(filename);

    //check for success
    if (fileReader.fail()){

        // if fail, print error in terminal and exit
        print_result("File Opening Failed");
        exit(1);
    }
    else {

        // if success, print message to terminal
        print_result("File Opened Successfully");
    }
    
    // **READ DATA**

    // prepare string for parsing each line of file
    std::string line;
    //prepare data structure for storage
    std::vector<std::vector<double>> raw_data;

    // skip the first line (more efficient than checking the data type each call)
    std::getline(fileReader, line);

    // extract each line of CSV as string (mapped to 'line')
    while(std::getline(fileReader, line)){

        // create vector to store coordinate pairs
        std::vector<double> row;
        
        // treat line as stream
        std::stringstream ss(line);
        std::string cell;

        // convert cell data from string to double and add to row to give [x,y] data pairs
        while(std::getline(ss,cell,',')){

            // add each coordinate to intermediate vector
            row.push_back(std::stof(cell));
        }

        // add each coordinate pair to full vector storing coordinate pairs as subvectors
        raw_data.push_back(row);
    }

    fileReader.close();
    return raw_data;
}


void print_data(std::vector<std::vector<double>> data){
    // INPUTS:
    //  *   data - data in the form of a vector of vectors containing coordinate pairs 
    //      as floats from data, first line skipped

    // OUTPUT: first n coordinate pairs printed to terminal
    
    int n;
    std::cout << "Number of lines to print = ";
    std:: cin >> n;
    
    if (n > data.size()){
        print_result("Invalid Number of Lines: Number of lines is larger than data file");
        n = 5;
    }

    // Title data:
    std::cout << std::endl << "x,y Data:" << std::endl << std::endl;

    // define subset of data to print (the first n lines)
    std::vector<std::vector<double>> subset = {data.begin(), data.begin() + n};
    print_result(subset);

    // for (int i=0; i<n; ++i){

    //     for (int j=0; j<data[i].size(); ++j){

    //         std::cout << data[i][j] << " ";
    //     }
        
    //     std::cout << std::endl << std::endl;
    // }
}


double get_magnitude(std::vector<double> coords){
    double x,y;
    x = coords[0];
    y = coords[1];

    return sqrt(pow(x,2)+pow(y,2));
}


std::vector<double> get_all_data_magnitudes(std::vector<std::vector<double>> data){
    
    std::cout << std::endl << "Magnitudes: " << std::endl << std::endl;
    std::vector<double> all_magnitudes;
    for (int i=0; i<data.size(); ++i){

        std::vector<double> coords = data[i];
        double magnitude = get_magnitude(coords);
        all_magnitudes.push_back(magnitude);
    }

    print_result(all_magnitudes);

    return all_magnitudes;
}


double fit_function(double x, double p, double q){
    return p*x +q;
}


double get_chi_sqrd(std::vector<std::vector<double>> data, double p, double q){

    std::vector<std::vector<double>> err_data = read_data("error2D_float.txt");
}


std::vector<double> least_squares_linear_fit(std::vector<std::vector<double>> data){

    // extract x and y data into separate arrays
    double x_sum, y_sum, x_sq_sum, xy_sum = 0;

    for (int i=0; i < data.size(); ++i){
        x_sum += data[i][0];
        x_sq_sum += pow(data[i][0],2);
        y_sum += data[i][1];
        xy_sum += data[i][0]*data[i][1];
    }

    double N = data.size();

    double ls_denominator = N*x_sq_sum-x_sum*x_sum;
    double p = (N*xy_sum - x_sum*y_sum)/ls_denominator;
    double q = (x_sq_sum*y_sum - xy_sum*x_sum)/ls_denominator;

    // this is how I interpreted instruction 7 in the assignment, literally just print the linear equation as a string
    std::string fit_line_equation = "y = " + std::to_string(p) + "x + " + std::to_string(q);

    // **save output to .txt file**

    std::ofstream linearFitOuput;
    // open file
    linearFitOuput.open("linearFitFunction.txt");
    // check
    if (linearFitOuput.fail()){
        print_result("Failed to open linear fit output file");
        exit(1);
    }

    // write in data
    linearFitOuput << fit_line_equation << std::endl;

    // close file
    linearFitOuput.close();

    //print output to terminal
    print_result("Fitted function:");
    print_result(fit_line_equation);

    std::vector<double> lin_params;
    lin_params.push_back(p);
    lin_params.push_back(q);

    return lin_params;
}