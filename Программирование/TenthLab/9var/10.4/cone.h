#include "body.h"
#define PI 3.14

class Cone : public Body {
    public:
        Cone(Materials _material = PLASTIC, double _h = 1, double _r = 1){
            h = _h, R = r = _r;
            a = sqrt(h * h + R * R);
            side_square = SideSquare();
            full_square = FullSquare();
            base_square = BaseSquare();
            volume = Volume();
            shape = CONE;
            material = _material;
            weight = Weight();
        }
        double SideSquare(){ return PI * r * a; }
        double FullSquare(){ return PI * r * (r + a); }
        double BaseSquare(){ return PI * R * R; }
        double Volume(){ return 1./3 * PI * r * r * h; }
        void Deform(double k){
            h *= k, r *= k;
            a = sqrt(h * h + r * r);
            side_square = SideSquare();
            full_square = FullSquare();
            base_square = BaseSquare();
            volume = Volume();
        }
        void Draw(){ cout << "Рисую Конус" << endl; }
};