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

void TextField::SetFieldLength(double x) {
    dwidth = x;
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


int TextField::GetCharLength(char &letter, sf::Font &font, int font_size) {
    return font.getGlyph(int(letter), font_size, false).advance;
}

void TextField::CalculateLineLength() {
    int last_word = 0;
    for(int i = 0; i <= msg.size(); i++) {
        if(cLength < dwidth) {
            cLength += GetCharLength(msg[i], *fnt, _dpfontsize);
        } else {
            msg.replace(last_word, 1, "\n");
            i = last_word;
            cLength = 0;
        }
        if(msg[i] == ' ') {
            last_word = i;
        }
    }
    //msg complete
}

void TextField::CalculateText() {

}