#include <cmath>
#include <vector>

struct Point {
    double x;
    double y;

    Point(){}
    Point(double p_x, double p_y) { this->x = p_x; this->y = p_y; }

    Point add(double p_x, double p_y) { return Point(this->x + p_x, this->y + p_y); }

    Point substract(double p_x, double p_y) { return Point(this->x - p_x, this->y - p_y); }

    Point multiply(double k) { return Point(this->x * k, this->y * k); }

    Point divide(double k) { return Point(this->x / k, this->y / k); }

    Point rotate(double a) {
        int n = pow(10, 5);
        return Point(this->x * round(cos(a) * n)/n - y * round(sin(a) * n)/n, 
                     this->x * round(sin(a) * n)/n + y * round(cos(a) * n)/n);
    }

    static double length(Point p) { return sqrt(pow(p.x, 2) + pow(p.y, 2)); }

    double dotProduct(Point p) { return (this->x * p.x + this->y * p.y); }

    double distance(Point p) { return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2)); }

    static std::string to_string(Point p) {
        std::string res = "(" + std::to_string(p.x) + ";" + std::to_string(p.y) + ")";
        return res;
    }

    Point operator * (double k) { return multiply(k); }
    Point operator + (Point p) { return add(p.x, p.y); }
    Point operator - (Point p) { return substract(p.x, p.y); }
    void operator += (Point p) { this->x += p.x; this->y += p.y; }
    friend std::ostream& operator <<(std::ostream& os, const Point& p);
};

std::ostream& operator <<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ";" << p.y << ")";
    return os;
}