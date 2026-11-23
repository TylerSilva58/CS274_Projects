#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "shape.h"

static bool nearlyEqual(float a, float b) {
    return std::fabs(a - b) <= 1e-5f * std::fmax(std::fabs(a), std::fabs(b));
}

int main(int argc, char *argv[]) {
    std::vector<Shape *> shapes;

    for (int i = 1; i < argc;) {
        std::string arg{argv[i]};

        if (arg == "c" && i + 1 < argc) {
            shapes.push_back(new Circle{std::stof(argv[i + 1])});
            i += 2;
        } else if (arg == "r" && i + 2 < argc) {
            shapes.push_back(new Rectangle{std::stof(argv[i + 1]), std::stof(argv[i + 2])});
            i += 3;
        } else if (arg == "rp" && i + 2 < argc) {
            shapes.push_back(new RegularPolygon{std::stoi(argv[i + 1]), std::stof(argv[i + 2])});
            i += 3;
        } else if (arg == "rt" && i + 2 < argc) {
            shapes.push_back(new RightTriangle{std::stof(argv[i + 1]), std::stof(argv[i + 2])});
            i += 3;
        } else if (arg == "s" && i + 1 < argc) {
            shapes.push_back(new Square{std::stof(argv[i + 1])});
            i += 2;
        } else {
            std::cerr << "Bad argument: " << arg << '\n';
            for (Shape *s : shapes) delete s;
            return 1;
        }
    }

    float maxArea = 0;
    float maxCirc = 0;
    for (const Shape *s : shapes) {
        std::cout << s->name() << '\n'
                  << "area: " << s->area() << '\n'
                  << "circ: " << s->circumference() << "\n\n";
        if (s->area() > maxArea) maxArea = s->area();
        if (s->circumference() > maxCirc) maxCirc = s->circumference();
    }

    std::cout << "Shapes with max area " << maxArea << '\n';
    for (const Shape *s : shapes)
        if (nearlyEqual(s->area(), maxArea)) std::cout << s->name() << '\n';

    std::cout << "\nShapes with max circumference " << maxCirc << '\n';
    for (const Shape *s : shapes)
        if (nearlyEqual(s->circumference(), maxCirc)) std::cout << s->name() << '\n';

    // Clean up.
    for (Shape *s : shapes) delete s;

    return 0;
}
