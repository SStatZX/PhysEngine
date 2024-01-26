#include <iostream>
#include "Vector2.h"


int main() 
{
    Vector2 banana(2.0F, 3.0F);
    Vector2 apple(3.0F, 1.0F);
    std::cout << apple.toString() << std::endl;
    apple.normalize();
    std::cout << apple.toString() << std::endl;
    std::cout << banana.length() << std::endl;
    std::cout << banana.dot(apple) << std::endl;
}

