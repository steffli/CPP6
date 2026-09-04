#pragma once

#include <string>
#include <cstdlib>   
#include <cctype>    
#include <cmath>     
#include <iomanip>   
#include <iostream>  
#include <limits>

class Scalar{
    public:
        static void convert(const std::string& literal);
        Scalar();
        Scalar(const Scalar& copy);
        Scalar& operator=(const Scalar& copy);
        ~Scalar();
    private:
        static bool isPseudoLiteral(const std::string& literal);
        static void printChar(double value);
        static void printInt(double value);
        static void printFloat(double value);
        static void printDouble(double value);
};
