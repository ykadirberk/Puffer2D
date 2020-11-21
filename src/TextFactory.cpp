#include "TextFactory.h"

TextFactory::TextFactory(sf::RenderWindow* window, string input, sf::Font* fnt) {
    total_string = input;
    total_string_backup = input;
    p_font = fnt;
    w = window;
    // color implementation
    // u can add new colors or delete them.
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
    colortype = COLOR_WHITE;
    int linecounter = 0; // kaç satır olduğunu tutuyorum (render için gerekli)
    int posYhandler = 0; //satır değişimleri için y'yi tutuyorum
    int posXhandler = 0; //renk değişimi durumlarında x konumu tutmak
    size_t tend = 0; //format değiştirici karakteri tutuyorum
    while(1) {
        tend = total_string.find('&');
        if (tend == string::npos) {
            int lastbreak = 0;
            int textwidth;
            for (int i = 0; i < total_string.length(); i++) {
                if (total_string[i] == '\0') { //Eğer string bitmişse
                    Text* back = new Text(w, p_font, total_string, 18, colortype);
                    if (boldness) {
                        back->GetTextObject()->setStyle(sf::Text::Bold);
                    }
                    texts.push_back(back);
                    break;
                }
                if (textwidth + GetCharLength(total_string[i], *p_font, fontsize) < fieldbox->GetWidth()) {
                    textwidth += GetCharLength(total_string[i], *p_font, fontsize);
                } else {
                    string firsts = total_string.substr(0,lastbreak);
                    total_string = total_string.substr(lastbreak + 1);
                    lastbreak = 0;
                    Text* back = new Text(w, p_font, firsts, 18, colortype);
                    if (boldness) {
                        back->GetTextObject()->setStyle(sf::Text::Bold);
                    }
                    texts.push_back(back);
                    linecounter++;
                }
                if (total_string[i] == ' ') {
                    lastbreak = i;
                }
                
            }
        } else {
            
        }

    }
}

inline int TextFactory::GetCharLength(char &letter, sf::Font &font, int font_size) {
    return font.getGlyph(int(letter), font_size, false).advance;
}