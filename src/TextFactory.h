#pragma once

#define RED "0"
#define ORANGE "1"
#define YELLOW "2"
#define LIGHT_GREEN "3"
#define GREEN "4"
#define DARK_GREEN "5"
#define LIGHT_BLUE "6"
#define BLUE "7"
#define DARK_BLUE "8"
#define PINK "9"
#define MAGENTA "a"
#define PURPLE "b"
#define BLACK "c"
#define WHITE "d"
#define ObO "e"
#define RESET "f"
#define BOLD "g"

#define COLOR_RED sf::Color(255,0,0)
#define COLOR_ORANGE sf::Color(255,128,0)
#define COLOR_YELLOW sf::Color(255,255,0)
#define COLOR_LIGHT_GREEN sf::Color(153,255,51)
#define COLOR_GREEN sf::Color(0,255,0)
#define COLOR_DARK_GREEN sf::Color(0,204,0)
#define COLOR_LIGHT_BLUE sf::Color(0,255,255)
#define COLOR_BLUE sf::Color(0,128,255)
#define COLOR_DARK_BLUE sf::Color(0,0,204)
#define COLOR_PINK sf::Color(255,102,255)
#define COLOR_MAGENTA sf::Color(255,0,255)
#define COLOR_PURPLE sf::Color(128,0,128)
#define COLOR_BLACK sf::Color(0,0,0)
#define COLOR_WHITE sf::Color(255,255,255)

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include "UI/Text.h"
using namespace std;

class TextFactory {
    public:
        TextFactory(string input, sf::Font* fnt);
        ~TextFactory();

        void PrepareTexts();
    private:

        inline int GetCharLength(char &letter, sf::Font &font, int font_size);

        bool obotime = false;
        bool boldness = false;
        map<string, sf::Color> colormap;
        sf::Color colortype;
        vector<string> parted_strings;
        vector<Text> texts;
        sf::Font* p_font;
        string total_string;

};