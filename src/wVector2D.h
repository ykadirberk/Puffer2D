#pragma once
#include <math.h>
#include <stdio.h>

//an abbreviation for wVector2D
#define v2d wVector2D

namespace ess {
    const double PI = 3.14159265;

    static double SinAngleF(double ang) {
        double f = sin(ang*PI/180);
        return f;
    }

    static double CosAngleF(double ang) {
        double f = cos(ang*PI/180);
        return f;
    }

    static double ASinAngleF(double val) {
        double f = asin(val*180/PI);
        return f;
    }

    static double ACosAngleF(double val) {
        double f = acos(val*180/PI);
        return f;
    }
}

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