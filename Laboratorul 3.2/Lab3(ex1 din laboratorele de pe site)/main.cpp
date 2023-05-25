#include "Math.h"
#include<iostream>

int main()
{
    std::cout << "Add(2, 3) = " << Math::Add(2, 3) << std::endl;
    std::cout << "Add(2, 3, 4) = " << Math::Add(2, 3, 4) << std::endl;
    std::cout << "Add(2.5, 3.5) = " << Math::Add(2.5, 3.5) << std::endl;
    std::cout << "Add(2.5, 3.5, 4.5) = " << Math::Add(2.5, 3.5, 4.5) << std::endl;
    std::cout << "Mul(2, 3) = " << Math::Mul(2, 3) << std::endl;
    std::cout << "Mul(2, 3, 4) = " << Math::Mul(2, 3, 4) << std::endl;
    std::cout << "Mul(2.5, 3.5) = " << Math::Mul(2.5, 3.5) << std::endl;
    std::cout << "Mul(2.5, 3.5, 4.5) = " << Math::Mul(2.5, 3.5, 4.5) << std::endl;
    std::cout << "Add(5, 1, 3, 2) = " << Math::Add(4, 5, 1, 3, 2) << std::endl;
    std::cout << "Add(\"Hello \", \"world!\") = " << Math::Add("Hello ", "world!") << std::endl;
}