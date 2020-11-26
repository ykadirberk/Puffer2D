#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class Text {
    public:
        Text(sf::RenderWindow* window, sf::Font* font, string text, int size, sf::Color color);
        ~Text();

        void SetPosition(double x, double y);
        void Move(double x, double y);
        double GetX();
        double GetY();
        void SetText(string* t);
        void SetMode(bool n);
        sf::Text* GetTextObject();

        void Calc(double delt);
        bool Draw();

    private:
        sf::Font* dafont = NULL;
        string stringofthis;
        double timer = 0;
        double animation_const = 0.06;
        int counter = 0;
        bool visibility = true;
        bool slowmode = false;
        bool d_draw = false;
        vector<sf::Text*> spec_chara;
        sf::Text* txt = NULL;
        sf::RenderWindow* w = NULL;
};