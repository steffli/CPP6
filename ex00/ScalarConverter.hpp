#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <cerrno>
#include <climits>

class ScalarConverter{
    public:
        static void convert(const std::string& literal);
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& copy);
        ~ScalarConverter();
    private:
        static bool isPseudoLiteral(const std::string& literal);
        static void printChar(double value);
        static void printInt(double value);
        static void printFloat(double value);
        static void printDouble(double value);
};

#endif
