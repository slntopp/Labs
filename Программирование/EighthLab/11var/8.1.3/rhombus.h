#pragma once
#include <cstdio>
#include "point.h"

class Rhombus {
    private:
        const char* name = "Ромба ";
        char* obj_name;
        static int count;
        Point position[4];
    public:
        Rhombus(){
            obj_name = new char[7+count];
            sprintf(obj_name, "%s%d", name, count++);
        }
        Rhombus(Point* _position){
            obj_name = new char[5+count];
            sprintf(obj_name, "%s%d", name, count++);
            for(int i = 0; i < 4; ++i) position[i] = _position[i];
            if(notRh(position)) exit(1);   
        }
        bool notRh(Point* parr){
            double side0, side1, side2, side3;
            side0 = distance(parr[0], parr[1]);
            side1 = distance(parr[1], parr[2]);
            side2 = distance(parr[2], parr[3]);
            side3 = distance(parr[3], parr[0]);
            bool result = ((side0 == side1) && (side2 == side3));
            if(!result) cout << "Введенные точки не могут составить ромб!" << endl;
            return !result;
        }
        bool notRh(){
            Point* parr = position;
            double side0, side1, side2, side3;
            side0 = distance(parr[0], parr[1]);
            side1 = distance(parr[1], parr[2]);
            side2 = distance(parr[2], parr[3]);
            side3 = distance(parr[3], parr[0]);
            bool result = ((side0 == side1) && (side2 == side3));
            if(!result) cout << "Введенные точки не могут составить ромб!" << endl;
            return !result;
        }
        Point* GetPos() { return position; }
        char* GetName() { return obj_name; }
        void OXSymmetry() {
            for(int i = 0; i < 4; ++i) position[i].OXSymmetry();
        }
        double GetSD(){
            double diag0 = distance(position[0], position[2]);
            double diag1 = distance(position[1], position[3]);
            return (diag0 > diag1 ? diag1 : diag0);
        }
};
int Rhombus::count = 0;

istream& operator>>(istream& in, Rhombus &obj){
    cout << "Вводить координаты требуется строго в одном порядке обхода!!!" << endl;
    in >> obj.GetPos();
    if(obj.notRh()) exit(1);
    return in;
}
ostream& operator<<(ostream& out, Rhombus &obj){
    out << obj.GetPos();
    return out;
}