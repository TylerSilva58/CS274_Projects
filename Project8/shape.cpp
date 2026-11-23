#include "shape.h"

#include <cmath>

namespace {
const float PI = 3.14159265358979f;
}

Circle::Circle(float radius) : radius{radius} {}
float Circle::area() const { return PI * radius * radius; }
float Circle::circumference() const { return 2 * PI * radius; }
std::string Circle::name() const { return "Circle"; }

Rectangle::Rectangle(float width, float height) : width{width}, height{height} {}
float Rectangle::area() const { return width * height; }
float Rectangle::circumference() const { return 2 * (width + height); }
std::string Rectangle::name() const { return "Rectangle"; }

RightTriangle::RightTriangle(float base, float height) : base{base}, height{height} {}
float RightTriangle::area() const { return 0.5f * base * height; }
float RightTriangle::circumference() const {
    return base + height + std::sqrt(base * base + height * height);
}
std::string RightTriangle::name() const { return "Right Triangle"; }

RegularPolygon::RegularPolygon(int sides, float length) : sides{sides}, length{length} {}
float RegularPolygon::area() const {
    return (sides * length * length) / (4 * std::tan(PI / sides));
}
float RegularPolygon::circumference() const { return sides * length; }
std::string RegularPolygon::name() const { return "Regular Polygon"; }

Square::Square(float length) : RegularPolygon{4, length} {}

float Square::area() const { return length * length; }
std::string Square::name() const { return "Square"; }
