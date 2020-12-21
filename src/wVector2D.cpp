#include "wVector2D.h"

wVector2D::wVector2D(float angle, double length) {
    x = CosAngleF(angle) * length;
    y = SinAngleF(angle) * length;
}

wVector2D::wVector2D(double dx, double dy) {
    x = dx;
    y = dy;
}

wVector2D::~wVector2D() {
    delete& x, y;
}

double wVector2D::GetAngle(){
    return ASinAngleF(y/GetLength());
}

double wVector2D::GetLength(){
    return sqrt(x*x + y*y);
}

void wVector2D::AddAngle(double a) {
    double ex_length = GetLength();
    double s_a = GetAngle() + a;
    y = SinAngleF(s_a) * ex_length;
    x = CosAngleF(s_a) * ex_length;
    delete& s_a, ex_length;
}

void wVector2D::AddLength(double b) {
    double ang = GetAngle();
    double lng = GetLength();
    double newlength = lng + b;
    y = SinAngleF(ang) * newlength;
    x = CosAngleF(ang) * newlength;
    delete& lng, ang, newlength;
}

