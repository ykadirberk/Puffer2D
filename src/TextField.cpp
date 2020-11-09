#include "TextField.h"

TextField::TextField(sf::RenderWindow* window, sf::Font* font, string text) {
    w = window;
    msg = text;
    fnt = font;
}

TextField::~TextField() {

}

void TextField::SetPosition(double x, double y) {
    dx = x;
    dy = y;
}

void TextField::SetFieldSize(double x, double y) {
    dwidth = x;
    dheight = y;
}

void TextField::SetFontSize(double a) {
    dfontsize = a;
}

double TextField::GetX() {
    return dx;
}

double TextField::GetY() {
    return dy;
}

void TextField::Draw() {
    
}