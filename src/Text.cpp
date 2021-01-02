#include "Text.h"

Puffer::Text::Text(sf::RenderTexture* rtext, sf::Font* font,string text, int size, sf::Color color) {
    stringofthis = text;
    dafont = font;
    txt = new sf::Text();
    r = rtext;
    txt->setFont(*font);
    txt->setCharacterSize(size);
    txt->setFillColor(color);
    txt->setStyle(sf::Text::Regular);
    
}

Puffer::Text::~Text() {
    delete txt;
    printf("[DECONSTRUCT-LOG] Text class released.\n");
}

void Puffer::Text::SetPosition(double x, double y) {
    txt->setPosition(x, y);
}

void Puffer::Text::Move(double x, double y) {
    txt->move(x, y);
}

double Puffer::Text::GetX() {
    return txt->getPosition().x;
}

double Puffer::Text::GetY() {
    return txt->getPosition().y;
}

void Puffer::Text::SetText(string* t) {
    txt->setString(*t);
}

void Puffer::Text::SetBoldness(bool b) {
    if (b) {
        txt->setStyle(sf::Text::Bold);
    } else {
        txt->setStyle(sf::Text::Regular);
    }
}

sf::Text* Puffer::Text::GetTextObject() {
    return txt;
}

bool Puffer::Text::Draw() {
    if (visibility) {
        if (!d_draw) {
            txt->setString(stringofthis.substr(0,counter+1));
        }
        r->draw(*txt);
    } 
    return d_draw;
}

void Puffer::Text::Calc(double delt) {
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