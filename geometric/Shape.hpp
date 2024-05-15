#include "Point.hpp"
#include <string>

#define Pi 3.1415926535897932

class Shape {
    public:
        virtual Point center() {}
        virtual double perimetr() {}
        virtual double area() {}

        virtual void translate() {}
        virtual void rotate() {}
        virtual void scale() {}

        virtual void print() {}
        virtual std::string to_string() {}
};

class Elipse : public Shape {
    protected:
        Point f1;
        Point f2;
        double r;
    
    public:
        Elipse() {}
        Elipse(Point p_f1, Point p_f2, double p_r) { 
            this->f1 = p_f1; 
            this->f2 = p_f2; 
            this->r = p_r; 
            //std::cout << f1 << " " << f2 << " " << r << "\n";    
        }

        std::vector<Point> focuses() {
            std::vector<Point> result = {this->f1, this->f2};
            return result;
        }

        double focal_distance() { return this->f1.distance(f2); }

        double major_semi_axis() { return focal_distance() / 2 + this->r; }

        double minor_semi_axis() { return sqrt(pow(major_semi_axis(), 2) - pow(focal_distance() / 2, 2)); }

        double eccentricity() { return (this->f1.distance(f2) / 2) / (this->f1.distance(f2) / 2 + this->r); }

        Point center() { return Point(0.5 * (f1.x + f2.x), 0.5 * (f1.y + f2.y)); }

        double perimetr() {
            double a = major_semi_axis(), b = minor_semi_axis(); 
            return 4 * (Pi * a * b + pow(a - b, 2)) / (a + b);
        }
        
        double area() { return Pi * major_semi_axis() * minor_semi_axis(); }

        void translate(Point new_center) {
            this->f1 = this->f1.add(new_center.x, new_center.y);
            this->f2 = this->f2.add(new_center.x, new_center.y);
        }
        
        void rotate(double a, Point o = Point(0, 0)) {
            Point p_f1 = Point(this->f1.x - o.x, this->f1.y - o.y),
                  p_f2 = Point(this->f2.x - o.x, this->f2.y - o.y);

            this->f1 = p_f1.rotate(a);
            this->f2 = p_f2.rotate(a); 
        }
        
        void scale(double k) {
            Point p_f1 = Point(this->f1.x - center().x, this->f1.y - center().y) * (k / 2),
                  p_f2 = Point(this->f2.x - center().x, this->f2.y - center().y) * (k / 2);
                
            this->r *= k;
            this->f1 = f1 + p_f1;
            this->f2 = f2 + p_f2;
        }

        void print() { std::cout << "Elipse:\n    f1: " << this->f1 << "    f2: " << this->f2 << std::endl << "    Radius: " << this->r << std::endl; }

        std::string to_string() {
            std::string res = "Elipse:\n    f1: " + Point::to_string(this->f1) + "    f2: " + Point::to_string(this->f2) + "\n    Radius: " + std::to_string(this->r) + "\n";
            return res;
        }

        friend std::ostream& operator <<(std::ostream& os, Shape& p);
};

class Rectangle : public Shape {
    private:
        Point A;
        Point B;
        double p;

    public:
        Rectangle() {}
        Rectangle(Point p_A, Point p_B, double p_p) {
            this->A = p_A;
            this->B = p_B;
            this->p = p_p;
        }

        double first_side() { return std::max(p, sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2))); }

        double second_side() { return std::min(p, sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2))); }

        double diagonal() { return sqrt(pow(first_side(), 2) + pow(second_side(), 2)); }

        std::vector<Point> vertice () {
            double alpha = acos((Pi/2) - (abs(A.x - B.x) / diagonal()));
            std::vector<Point> result = { Point(A.x + (p/2) * cos(alpha), A.y + (p/2) * sin(alpha)), 
                                          Point(A.x - (p/2) * cos(alpha), A.y - (p/2) * sin(alpha)),
                                          Point(B.x + (p/2) * cos(alpha), B.y + (p/2) * sin(alpha)), 
                                          Point(B.x - (p/2) * cos(alpha), B.y - (p/2) * sin(alpha)) };
            return result;
        }

        Point center() { return Point((A.x + B.x) / 2, (A.y + B.y) / 2); }

        double perimetr() { return (first_side() + second_side()) * 2; }

        double area() { return first_side() * second_side(); }

        void translate(Point n_center) { this->A += Point(n_center.x - this->A.x, n_center.y - this->A.y); }

        void rotate(double a, Point o = Point(0, 0)) {
            Point n_A = Point(this->A.x - o.x, this->A.y - o.y),
                  n_B = Point(this->B.x - o.x, this->B.y - o.y);

            this->A = n_A.rotate(a);
            this->B = n_B.rotate(a);
        }

        void scale(double k) {
            Point n_A = Point(this->A.x - center().x, this->A.y - center().y) * k,
                  n_B = Point(this->B.x - center().x, this->B.y - center().y) * k;
                
            this->p *= k;
            this->A += n_A;
            this->B += n_B;
        }

        void print() { std::cout << "Rectangle:\n    A: " << this->A << "    B: " << this->B << std::endl << "    Side: " << this->p << std::endl; }

        std::string to_string() {
            std::string res = "Rectangle:\n    A: " + Point::to_string(this->A) + "    B: " + Point::to_string(this->B) + "\n    Side: " + std::to_string(this->p) + "\n"; 
            return res;
        }

        friend std::ostream& operator <<(std::ostream& os, Shape& p);

};

class Circle : public Elipse {
    private:
        Point o;
        double r;

    public:
        Circle() {}
        Circle(double p_r, Point p_o = Point(0, 0)): Elipse(p_o, p_o, p_r), o(p_o), r(p_r) {}

        double radius() { return this->r; }

        Point center() { return this->o; }
        double perimetr() { return 2 * Pi * this->r; }
        double area() { return Pi * pow(this->r, 2); }

        void translate(Point new_center) { this->o += new_center; }

        void rotate(double a, Point p_o = Point(0, 0)) { this->o += Point(p_o.x - this->o.x, p_o.y - this->o.y).rotate(a); }

        void scale(double k) { this->r *= k; }

        void print() { std::cout << "Circle:\n    O: " << this->o << std::endl << "    Radius: " << this->r << std::endl; }

        std::string to_string() {
            std::string res = "Circle:\n    O: " + Point::to_string(this->o) + "\n    Radius: " + std::to_string(this->r) + "\n"; 
            return res;
        }

        friend std::ostream& operator <<(std::ostream& os, Shape& p);
};

class Triangle : public Shape {
    private:
        Point A;
        Point B;
        Point C;

        void Kramer(double a1, double b1, double c1, double a2, double b2, double c2, double &x, double &y) {
            double prost, prost_x, prost_y;
            prost = a1 * b2 - a2 * b1;
            prost_x = c1 * b2 - c2 * b1;
            prost_y = a1 * c2 - a2 * c1;
            x = prost_x / prost; 
            y = prost_y / prost;
        }

    public:
        Triangle() {}
        Triangle(Point p_a, Point p_b, Point p_c) {
            this->A = p_a;
            this->B = p_b;
            this->C = p_c;
        }

        std::vector<Point> vertices() { return std::vector<Point>{ this->A, this->B, this->C }; }

        Circle circumscribed_circle() {
            double AB = this->A.distance(this->B),
                   AC = this->A.distance(this->C),
                   BC = this->B.distance(this->C);
            
            double alpha = acos((AB*AB + AC*AC - BC*BC) / (2 * AB * AC));
            double r = (BC / sin(alpha)) / 2;

            double z1 = pow(this->A.x, 2) + pow(this->A.y, 2),
                   z2 = pow(this->B.x, 2) + pow(this->B.y, 2),
                   z3 = pow(this->C.x, 2) + pow(this->C.y, 2);
            
             Point O((this->A.y - this->B.y) * z3 + (this->B.y - this->C.y) * z1 + (this->C.y - this->A.y) * z2,
                     (this->A.y - this->B.x) * z3 + (this->B.x - this->C.x) * z1 + (this->C.x - this->A.x) * z2);

            return Circle(r, O);
        }

        Circle inscribed_circle() {
            double a = this->A.distance(this->B),
                   b = this->B.distance(this->C),
                   c = this->A.distance(this->C);
            double p = (a+b+c)/2;
            double S = 0.5 * abs(((this->B.x - this->A.x)*(this->C.y - this->A.y) - (this->C.x - this->A.x)*(this->B.y - this->A.y)));

            double x0 = ((this->A.x + this->B.x - 2*this->C.x)*((this->C.y - this->A.y)*(this->B.x + this->C.x - 2*this->A.x) + this->A.x*(this->B.y + this->C.y - 2*this->A.y)) - this->C.x*(this->B.x + this->C.x - 2*this->A.x)*(this->A.y + this->B.y - 2*this->C.y))/((this->B.y + this->C.y - 2*this->A.y)*(this->A.x + this->B.x - 2*this->C.x) - (this->B.x + this->C.x - 2*this->A.x)*(this->A.y + this->B.y - 2*this->C.y));
            double y0 = ((x0 - this->A.x)*(this->B.y + this->C.y - 2*this->A.y)/(this->B.x + this->C.x - 2*this->A.x)) + this->A.y;

            return Circle(S/p, Point(x0, y0));
        }

        Circle nine_points_circle() {
            Point o((orthocenter().x + (inscribed_circle().center()).x) / 2, (orthocenter().x + (inscribed_circle().center()).y) / 2);
            return Circle(this->A.distance(o), o);
        }

        Point orthocenter() {
            double Ox, Oy;
            Kramer(this->C.x - this->B.x, this->C.y - this->B.y, this->A.x * (this->C.x - this->B.x) + this->A.y * (this->C.y - this->B.y), this->C.x - this->A.x, this->C.y - this->A.y, this->B.x * (this->C.x - this->A.x) + this->B.y * (this->C.y - this->A.y), Ox, Oy);

            return Point(Ox, Oy);
        }

        Point center() { return Point((this->A.x + this->B.x + this->C.x) / 3, (this->A.y + this->B.y + this->C.y) / 3); }

        double perimetr() { return this->A.distance(this->B) + this->A.distance(this->C) + this->B.distance(this->C); }

        double area() { return 0.5 * abs(((this->B.x - this->A.x)*(this->C.y - this->A.y) - (this->C.x - this->A.x)*(this->B.y - this->A.y))); }

        void translate(Point new_center) {
            this->A = this->A.add(new_center.x - center().x, new_center.y - center().y);
            this->B = this->A.add(new_center.x - center().x, new_center.y - center().y);
            this->C = this->C.add(new_center.x - center().x, new_center.y - center().y);
        }

        void rotate(double a, Point o = Point(0, 0)) {
            Point p_A = Point(this->A.x - o.x, this->A.y - o.y),
                  p_B = Point(this->B.x - o.x, this->B.y - o.y),
                  p_C = Point(this->C.x - o.x, this->C.y - o.y);

            this->A = p_A.rotate(a);
            this->B = p_B.rotate(a); 
            this->C = p_C.rotate(a); 
        }

        void scale(double k) {
            this->B = Point(this->B.x - this->A.x, this->B.y - this->A.y) * k;
            this->C = Point(this->C.x - this->A.x, this->C.y - this->A.y) * k;
        }

        std::string to_string() {
            std::string res = "Trinangle:\n    A: " + Point::to_string(this->A) + "    B: " + Point::to_string(this->B) + "    C: " + Point::to_string(this->C) + "\n"; 
            return res;
        }

        friend std::ostream& operator <<(std::ostream& os, Shape& p);

        void print() { std::cout << "Trinangle:\n    A: " << this->A << "    B: " << this->B << "    C: " << this->C << std::endl; }
};

class Square : public Rectangle {
    private:
        Point A;
        Point B;
        double p;

    public:
        Square() {}
        Square(Point p_A, Point p_B, double p_p) {
            this->A = p_A;
            this->B = p_B;
            this->p = p_p;
        }

        double Side() { return p; }

        Circle circumscribed_circle() { return Circle(this->p/2, center()); }

        Circle inscribed_circle() {return Circle(diagonal() / 2, center()); }

        Point center() { return Point((this->A.x + this->B.x) / 2, (this->A.y + this->B.y) / 2); }

        double perimetr() { return 4 * this->p; }

        double area() { return this->p * this->p; }

        void translate(Point n_center) { this->A += Point(n_center.x - this->A.x, n_center.y - this->A.y); }

        void rotate(double a, Point o = Point(0, 0)) {
            Point n_A = Point(this->A.x - o.x, this->A.y - o.y),
                  n_B = Point(this->B.x - o.x, this->B.y - o.y);

            this->A = n_A.rotate(a);
            this->B = n_B.rotate(a);
        }

        void scale(double k) {
            Point n_A = Point(this->A.x - center().x, this->A.y - center().y) * k,
                  n_B = Point(this->B.x - center().x, this->B.y - center().y) * k;
                
            this->p *= k;
            this->A += n_A;
            this->B += n_B;
        }

        std::string to_string() {
            std::string res = "Square:\n    A: " + Point::to_string(this->A) + "    B: " + Point::to_string(this->B) + "\n    Side: " + std::to_string(this->p) + "\n"; 
            return res;
        }

        friend std::ostream& operator <<(std::ostream& os, Shape& p);

        void print() { std::cout << "Square:\n    A: " << this->A << "    B: " << this->B << std::endl << "    Side: " << this->p << std::endl; }
};

std::ostream& operator <<(std::ostream& os, Shape& p) {
    os << p.to_string();
    return os;
}