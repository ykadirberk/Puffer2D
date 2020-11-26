#include "TextFactory.h"

TextFactory::TextFactory(sf::RenderWindow* window, PlainField* field, string input, sf::Font* fnt) {
    total_string = input;
    total_string_backup = input;
    p_font = fnt;
    w = window;
    fieldbox = field;
    fontsize = 18;
    // color implementation
    // u can add new colors or delete them.
    colormap.insert(pair<char ,sf::Color>(RED,COLOR_RED));
    colormap.insert(pair<char ,sf::Color>(ORANGE,COLOR_ORANGE));
    colormap.insert(pair<char ,sf::Color>(YELLOW,COLOR_YELLOW));
    colormap.insert(pair<char ,sf::Color>(LIGHT_GREEN,COLOR_LIGHT_GREEN));
    colormap.insert(pair<char ,sf::Color>(GREEN,COLOR_GREEN));
    colormap.insert(pair<char ,sf::Color>(DARK_GREEN,COLOR_DARK_GREEN));
    colormap.insert(pair<char ,sf::Color>(LIGHT_BLUE,COLOR_LIGHT_BLUE));
    colormap.insert(pair<char ,sf::Color>(BLUE,COLOR_BLUE));
    colormap.insert(pair<char ,sf::Color>(DARK_BLUE,COLOR_DARK_BLUE));
    colormap.insert(pair<char ,sf::Color>(PINK,COLOR_PINK));
    colormap.insert(pair<char ,sf::Color>(MAGENTA,COLOR_MAGENTA));
    colormap.insert(pair<char ,sf::Color>(PURPLE,COLOR_PURPLE));
    colormap.insert(pair<char ,sf::Color>(BLACK,COLOR_BLACK));
    colormap.insert(pair<char ,sf::Color>(WHITE,COLOR_WHITE));
}

TextFactory::~TextFactory() {

}

void TextFactory::SetDeltaTimer(double* delt) {
    delta = delt;
}

void TextFactory::PrepareTexts() {
    colortype = COLOR_WHITE;
    int linecounter = 0; // kaç satır olduğunu tutuyorum (render için gerekli) 
    int posYhandler = 0; //satır değişimleri için y'yi tutuyorum
    int posXhandler = 0; //renk değişimi durumlarında x konumu tutmak
    size_t tend = 0; //format değiştirici karakteri tutuyorum
    tend = total_string.find('&'); 
    if (tend == string::npos) { 
        int lastbreak = 0;
        int textwidth;
        for (int i = 0; i < total_string.length(); i++) {
            if (textwidth < fieldbox->GetWidth()) {/* debug kodu */printf("TextFactory.cpp:43\n"); //endline durumunu kontrol ediyor
                textwidth += GetCharLength(total_string[i], *p_font, fontsize); /* debug kodu */printf("TextFactory.cpp:44\n");
            } else { //endline durumunda stringi çekiyor
                string _sub = total_string.substr(0, lastbreak); /* debug kodu */printf("TextFactory.cpp:46\n");
                total_string = total_string.substr(lastbreak); /* debug kodu */printf("TextFactory.cpp:47\n");
                Text back_(w, p_font, _sub, fontsize, colortype); /* debug kodu */printf("TextFactory.cpp:48\n");
                back_.SetDeltaTimer(delta); /* debug kodu */printf("TextFactory.cpp:49\n");
                back_.SetPosition(10 + fieldbox->GetX(), 10 + fieldbox->GetY()  + (10 + fontsize)*linecounter); /* debug kodu */printf("TextFactory.cpp:50\n");
                texts.push_back(&back_); /* debug kodu */printf("TextFactory.cpp:51\n");
                lastbreak = 0; /* debug kodu */printf("TextFactory.cpp:52\n");
                textwidth = 0;
                i = 0; /* debug kodu */printf("TextFactory.cpp:53\n");
                linecounter++; /* debug kodu */printf("TextFactory.cpp:54\n");
            }
            if (total_string[i] == '\0') { //endline olmadan string biterse ekrana yazdırabilmek için
                Text back_(w, p_font, total_string, fontsize, colortype); /* debug kodu */printf("TextFactory.cpp:57\n");
                back_.SetDeltaTimer(delta); /* debug kodu */printf("TextFactory.cpp:58\n");
                back_.SetPosition(10 + fieldbox->GetX(), 10 + fieldbox->GetY()  + (10 + fontsize)*linecounter); /* debug kodu */printf("TextFactory.cpp:59\n");
                texts.push_back(&back_); /* debug kodu */printf("TextFactory.cpp:60\n");
                linecounter = 0; /* debug kodu */printf("TextFactory.cpp:61\n");
            }
            if (total_string[i] == ' ') { //kelimeleri ayırmamak için boşlukların konumunu tutuyor
                lastbreak = i;
            }
        }
        
    } else {
        int lastbreak = 0;
        int textwidth = 0;
        int lastextwidth = 0;
        string sub_ = total_string.substr(0, tend);
        for (int i = 0; i < sub_.length(); i++) { // this for loop has the exact same code with string::npos state described above

        }
        if (total_string[tend + 1] == 'e') {
            colortype = COLOR_WHITE;
            boldness = false;
        } else if (total_string[tend + 1] == 'f') {
            boldness = true;
        } else {
            colortype = colormap.at(total_string[tend + 1]);
            total_string = total_string.substr(tend + 2);
        }
    }
}

void TextFactory::DrawTexts() {
    for (int i = 0; i < texts.size(); i++) {
        texts[i]->Calc();
        bool state = texts[i]->Draw();
        texts[i]->Draw();
        if(!state) break;
    }
}

inline int TextFactory::GetCharLength(char &letter, sf::Font &font, int font_size) {
    return font.getGlyph(int(letter), font_size, false).advance;
}