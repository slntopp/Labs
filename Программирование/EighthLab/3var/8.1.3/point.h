class Point {
    public:
        double x, y;
        Point(double _x = 0, double _y = 0): x(_x), y(_y) {}
        Point(const Point &obj): x(obj.x), y(obj.y) {}
};