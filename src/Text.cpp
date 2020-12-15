#include "Text.h"

Text::Text(sf::RenderTexture* rtext, sf::Font* font,string text, int size, sf::Color color) {
    stringofthis = text;
    dafont = font;
    txt = new sf::Text();
    r = rtext;
    txt->setFont(*font);
    txt->setCharacterSize(size);
    txt->setFillColor(color);
    txt->setStyle(sf::Text::Regular);
    
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

void Text::SetText(string* t) {
    txt->setString(*t);
}

void Text::SetBoldness(bool b) {
    if (b) {
        txt->setStyle(sf::Text::Bold);
    } else {
        txt->setStyle(sf::Text::Regular);
    }
}

sf::Text* Text::GetTextObject() {
    return txt;
}

bool Text::Draw() {
    if (visibility) {
        if (!d_draw) {
            txt->setString(stringofthis.substr(0,counter+1));
        }
        r->draw(*txt);
    } 
    return d_draw;
}

void Text::Calc(double delt) {
    timer += delt;
    if (!d_draw) {
        if (timer >= animation_const) {
            counter++;
            timer = 0;
        }
    } else {
        timer = 0;
    }
    if (counter >= stringofthis.length()) {
        d_draw = true;
    }
}