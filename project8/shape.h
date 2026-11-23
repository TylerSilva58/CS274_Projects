#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    virtual ~Shape() = default;  

    virtual float area() const = 0;
    virtual float circumference() const = 0;
    virtual std::string name() const = 0;
};

class Circle : public Shape {
public:
    explicit Circle(float radius);
    float area() const override;
    float circumference() const override;
    std::string name() const override;

private:
    float radius;
};

class Rectangle : public Shape {
public:
    Rectangle(float width, float height);
    float area() const override;
    float circumference() const override;
    std::string name() const override;

private:
    float width;
    float height;
};

class RightTriangle : public Shape {
public:
    RightTriangle(float base, float height);
    float area() const override;
    float circumference() const override;
    std::string name() const override;

private:
    float base;
    float height;
};

class RegularPolygon : public Shape {
public:
    RegularPolygon(int sides, float length);
    float area() const override;
    float circumference() const override;
    std::string name() const override;

protected:
    int sides;
    float length;
};

class Square : public RegularPolygon {
public:
    explicit Square(float length);
    float area() const override;
    std::string name() const override;
};

#endif
