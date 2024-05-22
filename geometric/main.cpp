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


    //std::cout << Point(1, 1).rotate(M_PI / 2) << "\n";
    Circle b(1, Point(2, 2));
    b.scale(2);
    //b.translate(Point(1, 1));
    b.rotate(M_PI / 2, Point(1, 1));
    std::cout << b << "\n";
    std::cout << "major_semi_axis: " << b.major_semi_axis() << "\n";
    std::cout << "minor_semi_axis: " << b.minor_semi_axis() << "\n";


    Square c(Point(-1, -1), Point(1, 1));
    std::cout << c.second_side() << "\n";
    std::cout << c.area() << "\n";
    std::cout << c << "\n";
    //c.rotate(M_PI / 2);
    //c.scale(2);
    std::cout << c << "\n";



    Rectangle d(Point(-2, 0), Point(2, 0), 2);

    //std::cout << d.second_side() << "\n";
    //std::cout << d.first_side() << "\n";
    //std::cout << d.area() << "\n";
    //d.rotate(M_PI / 2);
    //d.scale(2);
    std::cout << d << "\n";
    d.translate(Point(1, 1));
    std::cout << d.center() << "\n";

    std::cout << d << "\n";
    */
    /*
    */

    Triangle e(Point(0, 2), Point(2, 0), Point(0, -2));

    //e.rotate(M_PI / 2);
    //e.scale(2);
    //e.translate(Point(1, 1));
    //std::cout << e.area() << "\n" << e.center() << "\n" << e.orthocenter();
    //Circle t = e.circumscribed_circle();
    //Circle t2 = e.inscribed_circle();
    //Circle t3 = e.nine_points_circle();
    //std::cout << t3;
    std::cout << e.nine_points_circle();

    std::cout << e << "\n";
    return 0;
}