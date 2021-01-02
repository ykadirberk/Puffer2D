#include "wVector2D.h"

wVector2D::wVector2D(float angle, double length) {
    x = ess::CosAngleF(angle) * length;
    y = ess::SinAngleF(angle) * length;
}

wVector2D::wVector2D(double dx, double dy) {
    x = dx;
    y = dy;
}

wVector2D::~wVector2D() {
    printf("[DECONSTRUCT-LOG] wVector2D class released.\n");
}

double wVector2D::GetAngle(){
    return ess::ASinAngleF(y/GetLength());
}

double wVector2D::GetLength(){
    return sqrt(x*x + y*y);
}

void wVector2D::AddAngle(double a) {
    double ex_length = GetLength();
    double s_a = GetAngle() + a;
    y = ess::SinAngleF(s_a) * ex_length;
    x = ess::CosAngleF(s_a) * ex_length;
    delete& s_a, ex_length;
}

void wVector2D::AddLength(double b) {
    double ang = GetAngle();
    double lng = GetLength();
    double newlength = lng + b;
    y = ess::SinAngleF(ang) * newlength;
    x = ess::CosAngleF(ang) * newlength;
    delete& lng, ang, newlength;
}

