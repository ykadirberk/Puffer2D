#include "TextFactory.h"

TextFactory::TextFactory(string input, sf::Font* fnt) {
    total_string = input;
    p_font = fnt;
}

TextFactory::~TextFactory() {

}



inline int TextFactory::GetCharLength(char &letter, sf::Font &font, int font_size) {
    return font.getGlyph(int(letter), font_size, false).advance;
}