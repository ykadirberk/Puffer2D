#pragma once

#define COLOR_RED "&r"
#define COLOR_YELLOW "&y"
#define COLOR_BLUE "&b"

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class TextFactory {
    public:
        TextFactory(string input, sf::Font* fnt);
        ~TextFactory();

        void PrepareTexts();
    private:

        inline int GetCharLength(char &letter, sf::Font &font, int font_size);

        vector<sf::Text*> texts;
        sf::Font* p_font;
        string total_string;

};