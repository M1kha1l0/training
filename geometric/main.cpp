#include <iostream>
#include "Shape.hpp"

int main() {
    /*
    Elipse a(Point(-1, 0), Point(1, 0), 1);
    //a.rotate(Pi / 2);
    //a.scale(2);
    a.translate(Point(1, 1));
    std::cout << a << "\n";
    std::cout << "focal dist: " << a.focal_distance() << "\n";
    std::cout << "major_semi_axis: " << a.major_semi_axis() << "\n";
    std::cout << "minor_semi_axis: " << a.minor_semi_axis() << "\n";
    std::cout << "center: " << a.center() << "\n";
    */
    Circle b(2, Point(1, 1));
    //b.scale(2);
    //b.translate(Point(1, 1));
    //b.rotate(Pi / 2);
    std::cout << b << "\n";
    std::cout << "major_semi_axis: " << b.major_semi_axis() << "\n";
    std::cout << "minor_semi_axis: " << b.minor_semi_axis() << "\n";

    /*
    Square c(Point(-2, 0), Point(2, 0), 4);
    std::cout << c << "\n";

    Rectangle d(Point(0, 3), Point(0, -3), 2);
    std::cout << d << "\n";

    Triangle e(Point(0, 2), Point(2, 0), Point(0, -2));
    std::cout << e << "\n";
    */
    return 0;
}