#pragma once

enum Shapes { BALL, PRISM, CUBE, PARALELLEPIPED, PYRAMIDE, CONE, CYLINDER, TRUNCATEDCONE };
enum Materials { IRON = 7800, PLASTIC = 900, CARDBOARD = 300, CUPRUM = 8940, STEEL = 7856, TITAN = 4500 };

class Body {
    protected:
        Shapes shape;
        Materials material;
        double r, R, h, a, b, full_square, base_square, side_square, volume, weight;
    public:
        virtual double FullSquare() = 0;
        virtual double BaseSquare() = 0;
        virtual double SideSquare() = 0;
        virtual double Volume() = 0;
        virtual void Deform(double k) = 0;
        virtual void Draw() = 0;
        virtual double Weight(){ return material * volume; };
};

const char* Material(Materials material){
    switch(material){
        case IRON:
            return "�� ������";
            break;
        case PLASTIC:
            return "�� ��������";
            break;
        case STEEL:
            return "�� �����";
            break;
        case CUPRUM:
            return "�� ����";
            break;
        case TITAN:
            return "�� ������";
            break;
        default:
            return "�� �������������";
            break;
    }
}