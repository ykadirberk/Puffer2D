#include <math.h>
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