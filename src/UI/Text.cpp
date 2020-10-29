#include "Text.h"

Text::Text(sf::RenderWindow* window, sf::Font* font,string text, int size, sf::Color color, uint32_t style) {
    txt = new sf::Text();
    w = window;
    txt->setFont(*font);
    txt->setString(text);
    txt->setCharacterSize(size);
    txt->setFillColor(color);
    txt->setStyle(style);
}

Text::~Text() {
    
}

void Text::SetPosition(double x, double y) {
    txt->setPosition(x, y);
}

void Text::Move(double x, double y) {
    txt->move(x, y);
}

double Text::GetX() {
    return txt->getPosition().x;
}

double Text::GetY() {
    return txt->getPosition().y;
}

void Text::DrawText() {
    w->draw(*txt);
}
