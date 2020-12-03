#include "TextFactory.h"

TextFactory::TextFactory(sf::RenderWindow* window, PlainField* field, string input, sf::Font* fnt) {
    total_string = input;
    total_string_backup = input;
    p_font = fnt;
    w = window;
    fieldbox = field;
    fontsize = 16;
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
            if (textwidth < fieldbox->GetWidth()) { //endline durumunu kontrol ediyor
                textwidth += GetCharLength(total_string[i], *p_font, fontsize, boldness);
            } else { //endline durumunda stringi çekiyor
                string _sub = total_string.substr(0, lastbreak);
                total_string = total_string.substr(lastbreak + 1);
                Text* back_ = new Text(w, p_font, _sub, fontsize, colortype); printf("[DEBUGLOG]%s\n", _sub.c_str());
                back_->SetPosition(10 + fieldbox->GetX(), 10 + fieldbox->GetY()  + (((6.0 / 18.0) + 1) * fontsize)*linecounter); 
                texts.push_back(back_);
                lastbreak = 0; 
                textwidth = 0;
                i = 0; 
                linecounter++; 
            }
            if (i == total_string.length() - 1) { //endline olmadan string biterse ekrana yazdırabilmek için
                Text* back_ = new Text(w, p_font, total_string, fontsize, colortype); 
                back_->SetPosition(10 + fieldbox->GetX(), 10 + fieldbox->GetY()  + (((6.0 / 18.0) + 1) * fontsize)*linecounter);  
                texts.push_back(back_);
                linecounter = 0;  printf("[DEBUGLOG]%s\n", total_string.c_str());
            }
            if (total_string[i] == ' ') { //kelimeleri ayırmamak için boşlukların konumunu tutuyor
                lastbreak = i;
            }
        }
        
    } else {
        int lastbreak = 0;
        int textwidth = 0;
        int lastextwidth = 0;
        sf::Color tempColor = colortype;
        bool tempBold = boldness;
        vector<string> lines;
        for (int i = 0; i < total_string.length(); i++) {
            if (textwidth < fieldbox->GetWidth()) { //endline durumunu kontrol ediyor
                if (total_string[i] == '&' && total_string.length() < i + 2) {
                    i += 2;
                }
                textwidth += GetCharLength(total_string[i], *p_font, fontsize, boldness);
            } else {
                string firsts = total_string.substr(0, lastbreak);
                total_string = total_string.substr(lastbreak + 1);
                i = 0;
                lastbreak = 0;
                textwidth = 0;
                lines.push_back(firsts); printf("[DEBUGLOG-C]%s\n", firsts.c_str());
            }
            if (i == total_string.length() - 1) {
                lines.push_back(total_string); printf("[DEBUGLOG-C]%s\n", total_string.c_str());
            }
            if (total_string[i] == ' ') {
                lastbreak = i;
            } 
        }

        for (int i = 0; i < lines.size(); i++) {
            size_t ptfound = lines[i].find_first_of('&');
            if (ptfound != string::npos) {
                while (ptfound != string::npos) {
                    if (lines[i][ptfound + 1] == 'e') {
                        tempColor = COLOR_WHITE;
                        tempBold = false;
                    } else if (lines[i][ptfound + 1] == 'f') {
                        tempBold = true;
                    } else {
                        tempColor = colormap.at(lines[i][ptfound + 1]);
                    }

                    string tempStr = lines[i].substr(0,ptfound);
                    if (lines[i].length() >= ptfound +2) {
                        lines[i] = lines[i].substr(ptfound + 2);
                    }
                    Text* tempTx = new Text(w, p_font, tempStr, fontsize, colortype); 
                    tempTx->SetPosition(10 + fieldbox->GetX() + lastextwidth, 10 + fieldbox->GetY()  + (((6.0 / 18.0) + 1) * fontsize)*i);
                    tempTx->SetBoldness(boldness);
                    texts.push_back(tempTx);
                    for(int j = 0; j < tempStr.length(); j++) {
                        lastextwidth += GetCharLength(tempStr[j], *p_font, fontsize, boldness);
                    }
                    boldness = tempBold;
                    colortype = tempColor;
                    ptfound = lines[i].find_first_of('&');
                }
                Text* tempTx = new Text(w, p_font, lines[i], fontsize, colortype);
                tempTx->SetPosition(10 + fieldbox->GetX() + lastextwidth, 10 + fieldbox->GetY()  + (((6.0 / 18.0) + 1) * fontsize)*i);
                tempTx->SetBoldness(boldness);
                texts.push_back(tempTx);
            } else {
                Text* tempTx = new Text(w, p_font, lines[i], fontsize, colortype);
                tempTx->SetPosition(10 + fieldbox->GetX() + lastextwidth, 10 + fieldbox->GetY()  + (((6.0 / 18.0) + 1) * fontsize)*i);
                tempTx->SetBoldness(boldness);
                texts.push_back(tempTx);
            }
            lastextwidth = 0;
        }
    }
}

void TextFactory::DrawTexts(double deltas) {
    for (int i = 0; i < texts.size(); i++) {
        texts[i]->Calc(deltas);
        if(!texts[i]->Draw()) break;
    }
}

inline int TextFactory::GetCharLength(char &letter, sf::Font &font, int font_size, bool boldnesss) {
    return font.getGlyph(int(letter), font_size, boldness).advance;
}