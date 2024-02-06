#include <iostream>
#include "Vector2.h"
#include "Vector3.h"


int main() 
{
    Vector2 banana(2.0F, 3.0F);
    Vector2 apple(3.0F, 1.0F);
    std::cout << apple.toString() << std::endl;
    apple.normalize();
    std::cout << apple.toString() << std::endl;
    std::cout << banana.length() << std::endl;
    std::cout << banana.dot(apple) << std::endl;

    Vector3 cheese(2.0F, 1.0F, 4.0F);
    Vector3 carrot(1.0F, 1.0F, 9.0F);
    std::cout << cheese.toString() << std::endl;
    cheese.normalize();
    std::cout << cheese.toString() << std::endl;
    std::cout << carrot.dot(cheese) << std::endl;
    std::cout << carrot.length() << std::endl;
}

