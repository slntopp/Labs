#include "cone.h"

class TruncatedCone : public Cone {
    public:
        TruncatedCone(Materials _material = PLASTIC, double _h = 1, double _R = 2, double _r = 1){
            h = _h, r = _r, R = _R;
            a = sqrt(h * h + r * r);
            side_square = SideSquare();
            full_square = FullSquare();
            base_square = BaseSquare();
            volume = Volume();
            shape = TRUNCATEDCONE;
            material = _material;
            weight = Weight();
        }
        double SideSquare(){return PI * a * (r + R); }
        double FullSquare(){ return PI * (a*R + a*r + R*R + r*r); }
        double Volume(){ return 1./3 * PI * h * (R*R + R*r + r*r); }
        void Deform(double k){
            h *= k, r *= k, R *= k;
            a = sqrt(h * h + r * r);
            side_square = SideSquare();
            full_square = FullSquare();
            base_square = BaseSquare();
            volume = Volume();
        }
        void Draw(){ cout << "Рисую Усеченный Конус" << endl; }
};