#include "Text.h"

Text::Text(sf::RenderWindow* window, sf::Font* font,string text, int size, sf::Color color) {
    stringofthis = text;
    dafont = font;
    txt = new sf::Text();
    for (int i = 0; i < text.length(); i++) {
        sf::Text *_temp_ = new sf::Text(text[i], *font, size);
        _temp_->setFillColor(color);
        _temp_->setPosition(0,0);
        spec_chara.push_back(_temp_);
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
    txt->setPosition(x, y); /* debug kodu */printf("Text.cpp:25\n");
    int width_calc = 0; /* debug kodu */printf("Text.cpp:26\n");
    for (int i = 0; i < spec_chara.size(); i++) { /* debug kodu */printf("Text.cpp:27\n");
        spec_chara[i]->move(x,y); /* debug kodu */printf("Text.cpp:28\n");
        if (i + 1 == spec_chara.size()) {
            break;
        }
        width_calc += dafont->getGlyph(stringofthis[i + 1], txt->getCharacterSize(), false).advance; /* debug kodu */printf("Text.cpp:29\n");
        spec_chara[i + 1]->setPosition(x + width_calc, y); /* debug kodu */printf("Text.cpp:30\n");
    } /* debug kodu */printf("Text.cpp:31\n");
}

void Text::Move(double x, double y) {
    txt->move(x, y);
    int width_calc = 0;
    spec_chara[0]->setPosition(x,y);
    for (int i = 1; i < spec_chara.size(); i++) {
        width_calc += dafont->getGlyph(spec_chara[i - 1]->getString().getData()[0], txt->getCharacterSize(), false).advance;
        spec_chara[i]->move(x, y);
    }
}

void Text::SetDeltaTimer(double* delt) {
    deltaTime = delt;
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

void Text::Calc(double delt) {
    timer += delt;
    if (!d_draw) {
        if (timer >= animation_const) {
            counter++;
            timer = 0;
        }
        //printf("%lf\n", delt);
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
