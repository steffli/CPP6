#include "Scalar.hpp"


Scalar::Scalar() {}

Scalar::Scalar(const Scalar& copy) { (void)copy; }

Scalar& Scalar::operator=(const Scalar& copy) {
    (void)copy;
    return *this;
}

Scalar::~Scalar() {}

void Scalar::convert(const std::string& literal){
    (void)literal;
}


bool Scalar::isPseudoLiteral(const std::string& literal){
    if (literal == "nan" || literal == "nanf" || literal == "inf" || literal == "inff"
        || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff")
        return true;
    return false;
}

void Scalar::printChar(double value){
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

void Scalar::printInt(double value){
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min()
        || value > std::numeric_limits<int>::max())
        std::cout << "imposssible" << std::endl;
    else{
        std::cout << static_cast<int>(value) << std::endl;
    }
}

void Scalar::printFloat(double value){
    (void)value;
}

void Scalar::printDouble(double value){
    (void)value;
}
