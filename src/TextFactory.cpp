#include "TextFactory.h"

TextFactory::TextFactory(sf::RenderWindow* window, PlainField* field, string input, sf::Font* fnt) {
    total_string = input;
    total_string_backup = input;
    p_font = fnt;
    w = window;
    fieldbox = field;
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

void TextFactory::PrepareTexts(double* delta) {
    colortype = COLOR_WHITE; /* debug kodu */printf("TextFactory.cpp:32\n");
    int linecounter = 0;/* debug kodu */printf("TextFactory.cpp:33\n"); /* debug kodu */ // kaç satır olduğunu tutuyorum (render için gerekli) 
    int posYhandler = 0;/* debug kodu */printf("TextFactory.cpp:34\n"); //satır değişimleri için y'yi tutuyorum
    int posXhandler = 0;/* debug kodu */printf("TextFactory.cpp:35\n"); //renk değişimi durumlarında x konumu tutmak
    size_t tend = 0; /* debug kodu */printf("TextFactory.cpp:36\n"); //format değiştirici karakteri tutuyorum
    while(1) { /* debug kodu */printf("TextFactory.cpp:37\n");
        tend = total_string.find('&'); /* debug kodu */printf("TextFactory.cpp:38\n");
        if (tend == string::npos) { /* debug kodu */printf("TextFactory.cpp:39\n");
            int lastbreak = 0; /* debug kodu */printf("TextFactory.cpp:40\n");
            int textwidth; /* debug kodu */printf("TextFactory.cpp:41\n");
            for (int i = 0; i < total_string.length(); i++) { /* debug kodu */printf("TextFactory.cpp:42\n");
                if (total_string[i] == '\0') { /* debug kodu */printf("TextFactory.cpp:43\n"); //Eğer string bitmişse 
                    Text* back = new Text(w, p_font, total_string, 18, colortype); /* debug kodu */printf("TextFactory.cpp:44\n");
                    back->SetDeltaTimer(delta); /* debug kodu */printf("TextFactory.cpp:45\n");
                    back->SetPosition(
                            10 + fieldbox->GetX(),
                            10 +  fieldbox->GetY() + ((back->GetTextObject()->getCharacterSize() + 10)*linecounter)
                    ); /* debug kodu */printf("TextFactory.cpp:49\n");
                    if (boldness) { /* debug kodu */ printf("TextFactory.cpp:50\n");
                        back->GetTextObject()->setStyle(sf::Text::Bold); /* debug kodu */ printf("TextFactory.cpp:51\n");
                    } /* debug kodu */ printf("TextFactory.cpp:52\n");
                    texts.push_back(back); /* debug kodu */ printf("TextFactory.cpp:53\n");
                    break; /* debug kodu */ printf("TextFactory.cpp:54\n");
                } /* debug kodu */ printf("TextFactory.cpp:55\n");
                if (textwidth + GetCharLength(total_string[i], *p_font, fontsize) < fieldbox->GetWidth()) { /* debug kodu */ printf("TextFactory.cpp:56\n");
                    textwidth += GetCharLength(total_string[i], *p_font, fontsize); /* debug kodu */ printf("TextFactory.cpp:57\n");
                } else { /* debug kodu */ printf("TextFactory.cpp:58\n");
                    string firsts = total_string.substr(0,lastbreak); /* debug kodu */ printf("TextFactory.cpp:59\n");
                    total_string = total_string.substr(lastbreak + 1); /* debug kodu */ printf("TextFactory.cpp:60\n");
                    lastbreak = 0; /* debug kodu */ printf("TextFactory.cpp:61\n");
                    Text* back = new Text(w, p_font, firsts, 18, colortype); /* debug kodu */ printf("TextFactory.cpp:62\n");
                    back->SetDeltaTimer(delta); /* debug kodu */ printf("TextFactory.cpp:63\n");
                    back->SetPosition(
                            10 + fieldbox->GetX(),
                            10 + fieldbox->GetY() + (28*linecounter)
                    ); /* debug kodu */ printf("TextFactory.cpp:67\n");
                    if (boldness) { /* debug kodu */ printf("TextFactory.cpp:68\n");
                        back->GetTextObject()->setStyle(sf::Text::Bold); /* debug kodu */ printf("TextFactory.cpp:69\n");
                    } /* debug kodu */ printf("TextFactory.cpp:70\n");
                    texts.push_back(back); /* debug kodu */ printf("TextFactory.cpp:71\n");
                    linecounter++; /* debug kodu */ printf("TextFactory.cpp:72\n");
                } /* debug kodu */ printf("TextFactory.cpp:73\n");
                if (total_string[i] == ' ') { /* debug kodu */ printf("TextFactory.cpp:74\n");
                    lastbreak = i; /* debug kodu */ printf("TextFactory.cpp:75\n");
                } /* debug kodu */ printf("TextFactory.cpp:76\n");
                /* debug kodu */ printf("TextFactory.cpp:77\n");
            }
        } else {
            int lastbreak = 0;
            int textwidth = 0;
            int lastextwidth = 0;
            string sub_ = total_string.substr(0, tend);
            for (int i = 0; i < sub_.length(); i++) { // this for loop has the exact same code with string::npos state described above
               if (total_string[i] == '\0') { //Eğer string bitmişse
                    Text* back = new Text(w, p_font, sub_, 18, colortype);
                    back->SetDeltaTimer(delta);
                    back->SetPosition(
                            10 + fieldbox->GetX() + textwidth,
                            10 +  fieldbox->GetY() + ((back->GetTextObject()->getCharacterSize() + 10)*linecounter)
                    );
                    if (boldness) {
                        back->GetTextObject()->setStyle(sf::Text::Bold);
                    }
                    texts.push_back(back);
                    break;
                }
                if (textwidth + GetCharLength(sub_[i], *p_font, fontsize) < fieldbox->GetWidth()) {
                    textwidth += GetCharLength(sub_[i], *p_font, fontsize);
                } else {
                    string firsts = sub_.substr(0,lastbreak);
                    sub_ = sub_.substr(lastbreak + 1);
                    lastbreak = 0;
                    Text* back = new Text(w, p_font, firsts, 18, colortype);
                    back->SetDeltaTimer(delta);
                    back->SetPosition(
                            10 + fieldbox->GetX() + textwidth,
                            10 +  fieldbox->GetY() + ((back->GetTextObject()->getCharacterSize() + 10)*linecounter)
                    );
                    if (boldness) {
                        back->GetTextObject()->setStyle(sf::Text::Bold);
                    }
                    texts.push_back(back);
                    linecounter++;
                    textwidth = 0;
                }
                if (total_string[i] == ' ') {
                    lastbreak = i;
                }
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
}

void TextFactory::DrawTexts() {
    for (int i = 0; i < texts.size(); i++) {
        texts[i]->Calc();
        if(!texts[i]->Draw()) {

            break;
        }
    }
}

inline int TextFactory::GetCharLength(char &letter, sf::Font &font, int font_size) {
    return font.getGlyph(int(letter), font_size, false).advance;
}