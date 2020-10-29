#include "essentials.hpp"


class wVector2D {
    public: 
        wVector2D(double x, double y, double angle, double length);
        wVector2D(double x, double y, double width, double height);
        ~wVector2D();

        double GetAngle();
        double GetLength();
        double GetWidth();
        double GetHeight();
        double GetXPos();
        double GetYPos();

        void AddAngle(double a);
        void AddLength(double a);

    private:
        double w, h, dx, dy;
        
};