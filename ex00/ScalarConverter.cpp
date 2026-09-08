#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) { (void)copy; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
    (void)copy;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal){
    if (literal.empty()){
        std::cout << "Error: empty literal" << std::endl;
        return;
    }

    double value;

    if (isPseudoLiteral(literal)){
        std::string s = literal;
        if (s[s.length() - 1] == 'f' && s[s.length() - 2] != 'n')
            s.erase(s.length() - 1);
        value = std::strtod(s.c_str(), NULL);
    }
    else if (literal.length() == 1 && !std::isdigit(literal[0])){
        value = static_cast<double>(literal[0]);
    }
    else{
        errno = 0;
        char *end = NULL;
        value = std::strtod(literal.c_str(), &end);

        if (*end == 'f' && *(end + 1) == '\0')
            end++;
        if (*end != '\0' || end == literal.c_str()){
            std::cout << "Error: invalid literal" << std::endl;
            return;
        }
        if (errno == ERANGE){
            std::cout << "Error: out of range" << std::endl;
            return;
        }
    }
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}


bool ScalarConverter::isPseudoLiteral(const std::string& literal){
    if (literal == "nan" || literal == "nanf" || literal == "inf" || literal == "inff"
        || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff")
        return true;
    return false;
}

void ScalarConverter::printChar(double value){
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value))
        std::cout << "impossible" << std::endl;
    else if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "impossible" << std::endl;
    else if (!(std::isprint(static_cast<unsigned char>(value))))
            std::cout << "Non displayable" <<std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value){
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value)
        || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else{
        std::cout << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::printFloat(double value){
    std::cout <<"float: ";
    float f = static_cast<float>(value);
    if (std::isnan(f) || std::isinf(f))
        std::cout << f << "f" << std::endl;
    else if (std::floor(f) == f)
        std::cout << std::fixed << std::setprecision(1) << f << "f" <<  std::endl;
    else
        std::cout << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double value){
    std::cout << "double: ";
    if (std::isnan(value) || std::isinf(value))
        std::cout << value << std::endl;
    else if (std::floor(value) == value)
        std::cout << std::fixed << std::setprecision(1) << value <<  std::endl;
    else
        std::cout << value << std::endl;
}
