#include "PlainField.h"

Puffer::PlainField::PlainField(sf::RenderTexture* rtext) {
    r = rtext;
    position = new v2d();
    size = new v2d();
}
Puffer::PlainField::~PlainField() {
    printf("[DECONSTRUCT-LOG] PlainField class released.\n");
}

void Puffer::PlainField::SetPosition(double x, double y) {
    position->x = x;
    position->y = y;
}
void Puffer::PlainField::SetFieldLength(double x, double y) {
    size->x = x;
    size->y = y;
}
v2d Puffer::PlainField::GetPosition() {
    return *size;
}
v2d Puffer::PlainField::GetPosition() {
    return *position;
}

void Puffer::PlainField::Draw() {

}
