#include "Scalar.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "./convert <literal>" << std::endl;
        return 1;
    }
    Scalar::convert(argv[1]);
    return 0;
}
