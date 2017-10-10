using namespace std;

class Point {
    private:
        double x, y;
    public:
        Point(double _x = 0, double _y = 0): x(_x), y(_y) {}
        Point(const Point &obj){ x = obj.x; y = obj.y; }
        double GetX() const { return x; }
        double GetY() const { return y; }
        double* GetXY() { double *result = new double[2]; result[0] = x, result[1] = y; return result; }
        void Set(double _x, double _y) { x = _x, y = _y; }
        double distance(const Point &a, const Point &b){
            return sqrt(pow(a.GetX() - b.GetX(), 2) + pow(a.GetY() - b.GetY(), 2));
        }
        void OXSymmetry(){
            y += (y > 0 ? -1 : 1) * y * 2;
        }
};
double distance(const Point &a, const Point &b){
    return sqrt(pow(a.GetX() - b.GetX(), 2) + pow(a.GetY() - b.GetY(), 2));
}
istream& operator>> (istream& in, Point &obj){
    double x, y;
    in >> x >> y;
    obj.Set(x, y);
    return in;
}
ostream& operator<< (ostream& out, const Point &obj){
    out << "(" << obj.GetX() << "," << obj.GetY() << ")";
    return out;
}
istream& operator>> (istream& in, Point* parr){
    in >> parr[0] >> parr[1] >> parr[2] >> parr[3];
    return in;
}
ostream& operator<< (ostream& out, const Point* parr){
    out << parr[0] << " - " << parr[1] << " - " << parr[2] << " - " << parr[3];
    return out;
}