#include <iostream>
// #include "Vector2.h"
// #include "Vector3.h"
// #include "Matrix2x2.h"
#include "MathPhys.h"

int main() 
{
    Vector2 banana(2.0F, 3.0F);
    Vector2 apple(3.0F, 1.0F);


    std::cout << apple.to_string() << std::endl;
    apple.normalize();
    std::cout << apple.to_string() << std::endl;
    std::cout << banana.length() << std::endl;
    std::cout << banana.dot(apple) << std::endl;

    Vector3 cheese(2.0F, 1.0F, 4.0F);
    Vector3 carrot(1.0F, 1.0F, 9.0F);
    std::cout << cheese.to_string() << std::endl;
    cheese.normalize();
    std::cout << cheese.to_string() << std::endl;
    std::cout << carrot.dot(cheese) << std::endl;
    std::cout << carrot.length() << std::endl;

    Matrix2x2 toast(1.0, 2.0, 3.0, 4.0);
    std::cout << toast.to_string() << std::endl;
}

