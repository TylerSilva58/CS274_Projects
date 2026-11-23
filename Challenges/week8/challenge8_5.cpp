/* Challenge8_5 Inheritance */

#include <iostream>
#include <cmath>

class Vector2d {
public:
    float x, y;
    Vector2d(float x_val, float y_val) : x(x_val), y(y_val) {}
    virtual ~Vector2d() = default;
    virtual float magnitude() const {
        return std::sqrt(x*x + y*y);
    }
} ; 
class Vector3d : public Vector2d { 
public:
    float z;
    Vector3d(float x_val, float y_val, float z_val) : Vector2d(x_val, y_val), z(z_val) {}
    float magnitude() const override { 
        return std::sqrt(x*x + y*y + z*z);
    }
};

int main() {
    Vector2d v1(3.0f, 4.0f);
    std::cout << "2D Mag: " << v1.magnitude() << '\n';

    Vector3d v2(1.0f, 2.0f, 2.0f);
    std::cout << "3D Mag: " << v2.magnitude() << '\n';

    return 0;
}


   
