#include "Text.h"

Text::Text(sf::RenderWindow* window, sf::Font* font,string text, int size, sf::Color color) {
    stringofthis = text;
    dafont = font;
    txt = new sf::Text();
    /*for (int i = 0; i < text.length(); i++) {
        sf::Text *_temp_ = new sf::Text(text[i], *font, size);
        _temp_->setFillColor(color);
        _temp_->setPosition(0,0);
        spec_chara.push_back(_temp_);
    }*/
    w = window;
    txt->setFont(*font);
    //txt->setString(text);
    txt->setCharacterSize(size);
    txt->setFillColor(color);
    txt->setStyle(sf::Text::Regular);
}

Text::~Text() {
    
}

void Text::SetPosition(double x, double y) {
    txt->setPosition(x, y);
    /*int width_calc = 0;
    for (int i = 0; i < spec_chara.size(); i++) { 
        spec_chara[i]->move(x,y);
        if (i + 1 == spec_chara.size()) {
            break;
        }
        width_calc += dafont->getGlyph(stringofthis[i + 1], txt->getCharacterSize(), false).advance;
        spec_chara[i + 1]->setPosition(x + width_calc, y); 
    } */
}

void Text::Move(double x, double y) {
    txt->move(x, y);
    /*int width_calc = 0;
    spec_chara[0]->setPosition(x,y);
    for (int i = 1; i < spec_chara.size(); i++) {
        width_calc += dafont->getGlyph(spec_chara[i - 1]->getString().getData()[0], txt->getCharacterSize(), false).advance;
        spec_chara[i]->move(x, y);
    }*/
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
        if (!d_draw) {
            txt->setString(stringofthis.substr(0,counter+1));
            
        } else {
            
            /*for (int i = 0; i < counter; i++) {
                w->draw(*spec_chara[i]);
            }*/
        }
        w->draw(*txt);
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
