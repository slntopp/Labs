#pragma once
#include <iostream>
#include <cstring>
#include <cmath>

//статическое поле индексирования объектов

class Point {
    public:
        float x;
        float y;
        Point(){
            (*this).x = 0;
            (*this).y = 0;
            // std::cout << "_POINT_OBJ_CREATED" << std::endl;
        }
        Point(int x, int y){
            (*this).x = x; // my faculty   6 
            (*this).y = y;
            // std::cout << "_POINT_OBJ_CREATED" << std::endl;
        }
        Point(const Point& obj){
            (*this).x = obj.x;
            (*this).y = obj.y;
        }
        ~Point(){
            // std::cout << "_POINT_OBJ_DEL" << std::endl;
        }
};
std::ostream& operator<< (std::ostream& out, const Point &obj){
    out << "(" << obj.x << "," << obj.y << ")";
    return out;
}

class Square {
    private:
        Point loc[2];
        float edge;
        float square;
        float diag;
        static int count;
        int id;
    public:
        const std::string name = "Квадрат";
        Square(){
            loc[0] = Point(0,1);
            loc[1] = Point(1,0);
            edge = square = 1;
            diag = edge * std::sqrt(2);
            id = count++;
            OCS();
        }
        Square(float x, float y, float a){
            loc[0] = Point(x,y);
            edge = a;
            loc[1] = Point(x + edge, x - edge);
            square = edge * edge;
            diag = edge * sqrt(2);
            id = count++;
        }
        Square(float x, float y, float x1, float y1, float a){
            if(isSquare(Point(x,y), Point(x1,y1), a)){
                loc[0] = Point(x,y);
                loc[1] = Point(x1,y1);
                edge = a;
                square = edge * edge;
                diag = edge * sqrt(2);
                id = count++;
                OCS();
            } else {
                OCR();
                return;
            }
        }
        Square(Point &A, Point &B, float a){
            if(isSquare(A, B, a)){
                loc[0] = Point(A);
                loc[1] = Point(B);
                edge = a;
                square = edge * edge;
                diag = edge * sqrt(2);
                id = count++;
                OCS();
            } else {
                OCR();
                return;
            }
        }
        ~Square(){
            GCM();
        }

        bool isSquare(Point &A, Point &B){
            if(A.x == (B.x - (A.y - B.y))) return true;
            else return false;
        }
        bool isSquare(Point &A, Point &B, float a){
            if(A.x == (B.x - a)) return true;
            else return false;
        }
        void OCR(){
            std::cout << "_ERR_OBJ_SQUARE_CR" << std::endl;
        }
        void OCS(){
            std::cout << "_SUCCSS_OBJ_SQUARE_CR" << std::endl;            
        }
        void GCM(){
            std::cout << "_SQUARE_OBJ" << id << "_SUCCSS_DEL" << std::endl;
        }

        void MoveTo(Point &A){
            loc[0] = Point(A);
            loc[1] = Point(A.x + edge, A.y - edge);
        }
        void MoveToY(){
            if(loc[0].x > 0 && loc[1].x > 0){
                (*this).MoveTo(Point(0, loc[0].y));
            } else {
                (*this).MoveTo(Point(0 - edge, loc[0].y));
            }
        }   
        const Point GetLoc(unsigned int i) const { return Point(loc[i]); }
        const float GetEdge() const { return edge; }
        const float GetDiag() const { return diag; }
        const float GetSq() const { return square; }
        const int GetID() const { return id; }
};

int toZeroIncrement(int a){
    return a > 0 ? --a : a != 0 ? ++a : 0;
}

std::ostream& operator<< (std::ostream& out, const Square &obj){
    out << obj.name.c_str() << obj.GetID() << std::endl;
    out << "A" << obj.GetLoc(0) << "\n _____\n";
    out << "|\\    | Сторона: " << obj.GetEdge() << std::endl;
    out << "| \\   | Диагональ: " << obj.GetDiag() << std::endl;
    out << "|  \\  | Площадь: " << obj.GetSq() << std::endl;
    out << "|   \\ |" << std::endl;
    out << "|____\\| B" << obj.GetLoc(1) << std::endl;
    return out;
}

int Square::count = 0;