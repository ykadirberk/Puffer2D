#pragma once
#include "essentials.cpp"

class wVector2D {
    public: 
        wVector2D(double x, double y, float angle, double length);
        wVector2D(double x, double y, double width, double height);
        ~wVector2D();

        double GetAngle();
        double GetLength();
        double GetWidth();
        double GetHeight();
        double GetXPos();
        double GetYPos();

        void AddAngle(double a);
        void AddLength(double b);

    private:
        double w = 0, h = 0, dx = 0, dy = 0;
        
};