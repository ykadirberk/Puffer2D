#include "TextFactory.h"

TextFactory::TextFactory(string input, sf::Font* fnt) {
    total_string = input;
    p_font = fnt;

    colormap.insert(pair<string ,sf::Color>(RED,COLOR_RED));
    colormap.insert(pair<string ,sf::Color>(ORANGE,COLOR_ORANGE));
    colormap.insert(pair<string ,sf::Color>(YELLOW,COLOR_YELLOW));
    colormap.insert(pair<string ,sf::Color>(LIGHT_GREEN,COLOR_LIGHT_GREEN));
    colormap.insert(pair<string ,sf::Color>(GREEN,COLOR_GREEN));
    colormap.insert(pair<string ,sf::Color>(DARK_GREEN,COLOR_DARK_GREEN));
    colormap.insert(pair<string ,sf::Color>(LIGHT_BLUE,COLOR_LIGHT_BLUE));
    colormap.insert(pair<string ,sf::Color>(BLUE,COLOR_BLUE));
    colormap.insert(pair<string ,sf::Color>(DARK_BLUE,COLOR_DARK_BLUE));
    colormap.insert(pair<string ,sf::Color>(PINK,COLOR_PINK));
    colormap.insert(pair<string ,sf::Color>(MAGENTA,COLOR_MAGENTA));
    colormap.insert(pair<string ,sf::Color>(PURPLE,COLOR_PURPLE));
    colormap.insert(pair<string ,sf::Color>(BLACK,COLOR_BLACK));
    colormap.insert(pair<string ,sf::Color>(WHITE,COLOR_WHITE));
}

TextFactory::~TextFactory() {

}

void TextFactory::PrepareTexts() {
    colortype = sf::Color(0,128,255);
    size_t tbeg = 0;
    size_t tend = 0;
    while(1) {
        tend = total_string.find("§");
        if (tend == string::npos) {
            break;
        }
    }
}

inline int TextFactory::GetCharLength(char &letter, sf::Font &font, int font_size) {
    return font.getGlyph(int(letter), font_size, false).advance;
}