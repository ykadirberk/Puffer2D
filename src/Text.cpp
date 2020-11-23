#include "Text.h"

Text::Text(sf::RenderWindow* window, sf::Font* font,string text, int size, sf::Color color) {
    stringofthis = text;
    txt = new sf::Text();
    for (int i = 0; i < text.length(); i++) {
        spec_chara.push_back(new sf::Text(text[i], *font, size));
    }
    w = window;
    txt->setFont(*font);
    txt->setString(text);
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

sf::Text* Text::GetTextObject() {
    return txt;
}

bool Text::Draw() {
    if (visibility) {
        if (d_draw) {
            w->draw(*txt);
        } else {
            for (int i = 0; i < counter; i++) {
                w->draw(*spec_chara[i]);
            }
        }
    } 
    return d_draw;
}

void Text::Calc() {
    timer += *deltaTime;
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

void Text::SetMode(bool n) {
    slowmode = n;
}
