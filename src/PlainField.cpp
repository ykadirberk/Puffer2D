#include "PlainField.h"

Puffer::PlainField::PlainField(sf::RenderTexture* rtext) {
    r = rtext;
}
Puffer::PlainField::~PlainField() {
    printf("[DECONSTRUCT-LOG] PlainField class released.\n");
}

void Puffer::PlainField::SetPosition(double x, double y) {
    dx = x;
    dy = y;
}
void Puffer::PlainField::SetFieldLength(double x, double y) {
    dwidth = x;
    dheight = y;
}
double Puffer::PlainField::GetWidth() {
    return dwidth;
}
double Puffer::PlainField::GetHeight() {
    return dheight;
}
double Puffer::PlainField::GetX() {
    return dx;
}
double Puffer::PlainField::GetY() {
    return dy;
}

void Puffer::PlainField::Draw() {

}
