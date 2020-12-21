#pragma once
#include "essentials.cpp"

class wVector2D {
    public: 
        wVector2D() { x = 0; y = 0;}
        wVector2D(float angle, double length);
        wVector2D(double x, double y);
        ~wVector2D();

        double GetAngle();
        double GetLength();
        void AddAngle(double a);
        void AddLength(double b);

        double x, y;
};