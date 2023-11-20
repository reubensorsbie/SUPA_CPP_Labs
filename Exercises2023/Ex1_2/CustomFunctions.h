#include<vector>
#include<iostream>
#include<string>

#pragma once

// function to read coordinate data CSV file and output data as a vector of vectors
// containing corresponding pairs of x and y values
std::vector<std::vector<float>> read_data(std::string filename);

// function to print as many lines of the data stored in the input vector of vectors
// as the user requests up to the maximum
void print_data(std::vector<std::vector<float>> data);

// function to output the magnitude of the inputted 2D vector
float get_magnitude(std::vector<float> coords);

// function to print and store all the magnitudes of the 2D vectors in the input
// vector
std::vector<float> get_all_data_magnitudes(std::vector<std::vector<float>> data);