#include "wVector2D.h"

wVector2D::wVector2D(double x, double y, double angle, double length) {
    dx = x;
    dy = y;
    w = CosAngleF(angle) * length;
    h = SinAngleF(angle) * length;
}

wVector2D::wVector2D(double x, double y, double width, double height) {
    dx = x;
    dy = y;
    w = width;
    h = height;
}

wVector2D::~wVector2D() {
    delete& dx, dy, w, h;
}

double wVector2D::GetAngle(){
    return ASinAngleF(h/GetLength());
}

double wVector2D::GetLength(){
    return sqrt(w*w + h*h);
}

double wVector2D::GetWidth(){
    return w;
}

double wVector2D::GetHeight(){
    return h;
}

double wVector2D::GetXPos(){
    return dx;
}

double wVector2D::GetYPos(){
    return dy;
} 

void wVector2D::AddAngle(double a) {
    double ex_length = GetLength();
    double s_a = GetAngle() + a;
    h = SinAngleF(s_a) * ex_length;
    w = CosAngleF(s_a) * ex_length;
    delete& s_a, ex_length;
}

void wVector2D::AddLength(double b) {
    double ang = GetAngle();
    double lng = GetLength();
    double newlength = lng + b;
    h = SinAngleF(ang) * newlength;
    w = CosAngleF(ang) * newlength;
    delete& lng, ang, newlength;
}

