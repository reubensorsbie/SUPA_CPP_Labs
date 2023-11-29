#include<vector>
#include<iostream>
#include<string>

#pragma once

// overloaded functions to print various objects
void print_result(std::string result);
void print_result(double result);
void print_result(std::vector<double> result);
void print_result(std::vector<std::vector<double>> result);

// function to read coordinate data CSV file and output data as a vector of vectors
// containing corresponding pairs of x and y values
std::vector<std::vector<double>> read_data(std::string filename);

// function to print as many lines of the data stored in the input vector of vectors
// as the user requests up to the maximum
void print_data(std::vector<std::vector<double>> data);

// function to output the magnitude of the inputted 2D vector
double get_magnitude(std::vector<double> coords);

// function to print and store all the magnitudes of the 2D vectors in the input
// vector
void get_all_data_magnitudes(std::vector<std::vector<double>> data);

// function to find chi^2 value
double get_chi_sqrd(std::vector<std::vector<double>> data, std::vector<std::vector<double>> err_data, double p, double q);

// function to calculate expected y for given x using linear model
double fit_function(double x, double p, double q);

// function to produce a linear fit of the x,y data using the least squares method
void least_squares_linear_fit(std::vector<std::vector<double>> data, std::vector<std::vector<double>> err_data);

// recursive function to exponentiate x to the power y
double recursive_multiplier(double x, int y, double& result);

// function to exponentiate all coordinate pairs
void exponentiate_all_coords(std::vector<std::vector<double>> data);