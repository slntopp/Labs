#pragma once
#include <iostream>
#include <cmath>

const double PI_2 = 1.57079632679489661923;


class Point {
    private:
        class Polar {
            private:
                float r;
                float fi;
            public:
                Polar();
                Polar(float, float);
                Polar(const Polar&);
                float GetR() const;
                float GetFi() const;
                // ~Polar() { std::cout << "_OBJ_POLAR_DEL_SUCCSS" << std::endl; }
        };
        float x;
        float y;
        Polar polcor;
    public:
        Point(){
            x = y = 0;
            polcor = Polar(x, y);
        }
        Point(float x0, float y0){
            x = x0, y = y0;
            polcor = Polar(x,y);
        }
        Point(const Point& obj){
            x = obj.x, y = obj.y, polcor = obj.polcor;
        }
        const Point MoveX(float dx) const {
            return Point(x + dx, y);
        }
        const Point MoveY(float dy) const {
            return Point(x, y + dy);
        }
        const Point MoveXY(float dx, float dy) const {
            return Point(x + dx, y + dy);
        }
        void SetX(float nx){ x = nx, polcor = Polar(x, y); }
        void SetY(float ny){ y = ny, polcor = Polar(x, y); }
        void SetXY(float nx, float ny){ x = nx, y = ny, polcor = Polar(x, y); }
        float GetX() const { return x; }
        float GetY() const { return y; }
        const Polar GetPolar() const { return Polar(polcor); }
        float Radius() const { return sqrt(x * x + y * y); }
        bool operator== (const Point &obj) const { return x == obj.x && y == obj.y; }
        const Point operator+ (const Point &obj) const { return Point(x + obj.x, y + obj.y); }
        const Point operator* (const float num) const { return Point(x * num, y * num); }
        const Point operator/ (const float num) const { return Point(x / num, y / num); }
        friend bool OneLine(const Point &obj, const Point &obj1, const Point &obj2);
};

bool OneLine(const Point &obj, const Point &obj1, const Point &obj2){
    return (obj.x - obj2.x)*(obj1.y - obj2.y) - (obj1.x - obj2.x)*(obj.y - obj2.y) == 0;
}

class Triangle {
    private:
        Point corners[3], center;
        float distance;
    public:
        Triangle(){ distance = 0; }
        Triangle(Point a, Point b, Point c){          
            if(OneLine(a, b, c)){ ERRMSG(); return; }
            else if (a == b || b == c){ ERRMSG(); return; }
            corners[0] = Point(a), corners[1] = Point(b), corners[2] = Point(c);
            center = (a + b + c) / 3;
            distance = center.Radius();
            std::cout << "_TRIANGLE_OBJ_SUCCSS_CR" << std::endl;
        }
        ~Triangle(){
            std::cout << "_TRIANGLE_OBJ_SUCCSS_DEL" << std::endl;
        }
        const Point GetCorner(int i) const { return corners[i]; }
        const Point GetCenter() const { return center; }
        float GetDistance() const { return distance; }
        void ERRMSG(){ std::cout << "_ERR_TRIANGLE_OBJ_CR" << std::endl; }
        bool operator== (const Triangle &obj) const {
            Point a = corners[0], b = corners[1], c = corners[2], d = obj.corners[0], e = obj.corners[1], f = obj.corners[2];
            return ((a == d && b == e && c == f) || (a == e && b == f && c == d) || (a == f && b == d && c == e));
        }
        const Triangle MoveX(float dx) const {
            return Triangle(corners[0].MoveX(dx), corners[1].MoveX(dx), corners[2].MoveX(dx));
        }
        const Triangle MoveY(float dy) const {
            return Triangle(corners[0].MoveY(dy), corners[1].MoveY(dy), corners[2].MoveY(dy));
        }
        const Triangle MoveXY(float dx, float dy) const {
            return Triangle(corners[0].MoveXY(dx, dy), corners[1].MoveXY(dx, dy), corners[2].MoveXY(dx, dy));
        }
};

Point::Polar::Polar(){ r = fi = 0; }
Point::Polar::Polar(float x, float y){
    r = sqrt(x*x + y*y);
    fi = x != 0 ? atan(y / x) : (y == 0 ? 0 : (y < 0 ? -PI_2 : PI_2));
}
Point::Polar::Polar(const Polar &obj){
    r = obj.r, fi = obj.fi;
}
float Point::Polar::GetR() const { return r; }
float Point::Polar::GetFi() const { return fi; }
std::ostream& operator<< (std::ostream &out, const Point &obj){
    out << "(" << obj.GetX() << "," << obj.GetY() << ")";
    return out;
}
std::ostream& operator<< (std::ostream &out, const Triangle &obj){
    out << "A" << obj.GetCorner(0) << ", B" << obj.GetCorner(1) << ", C" << obj.GetCorner(2);
    return out;
}
void PolePrint(const Triangle &obj, char dots[3]){
    for(int i = 0; i < 3; ++i){
        Point tmp = obj.GetCorner(i);
        std::cout << dots[i] << "  {\n";
        std::cout << "\tx = " << tmp.GetPolar().GetR() << " + cos(" << tmp.GetPolar().GetFi() * 2 / PI_2 << "*Pi)\n";
        std::cout << "\ty = " << tmp.GetPolar().GetR() << " + sin(" << tmp.GetPolar().GetFi() * 2 / PI_2 << "*Pi)\n";
        std::cout << "}\n";
    }
}