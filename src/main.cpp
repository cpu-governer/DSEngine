#include <iostream>

#include "vec.h"

int main(int argc, char** argv)
{
        Vector2 vec(1.0, 2.0);
        Vector2 vec2(2.0, 2.0);

        vec *= vec2;
        
        std::cout << vec.x << ", " << vec.y << std::endl;
        return 0;
}
