#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
using namespace std;

class TextField {
    public:
        TextField(sf::RenderWindow* window, sf::Font* font, string text);
        ~TextField();

        void SetPosition(double x, double y);
        void SetFieldLength(double x);
        void SetFontSize(double a);
        double GetX();
        double GetY();
        void Draw();

    private:

        inline int GetCharLength(char &letter, sf::Font &font, int font_size);
        void CalculateLineLength();
        void CalculateText();

        string msg;
        vector<sf::Text*> texts;
        sf::Font* fnt;
        sf::RenderWindow* w = NULL;
        double dx = 0, dy = 0, dwidth = 0, dheight = 0, dfontsize = 0, _dpfontsize = 0;
        int cLength;

};