#include "PlainField.h"

PlainField::PlainField(sf::RenderWindow* window) {
    w = window;
}
PlainField::~PlainField() {

}

void PlainField::SetPosition(double x, double y) {
    dx = x;
    dy = y;
}
void PlainField::SetFieldLength(double x, double y) {
    dwidth = x;
    dheight = y;
}
double PlainField::GetWidth() {
    return dwidth;
}
double PlainField::GetHeight() {
    return dheight;
}
double PlainField::GetX() {
    return dx;
}
double PlainField::GetY() {
    return dy;
}

void PlainField::Draw() {

}
