#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class Text {
    public:
        Text(sf::RenderWindow* window, sf::Font* font, string text, int size, sf::Color color, sf::Uint32 style);
        ~Text();

        void SetPosition(double x, double y);
        void Move(double x, double y);
        double GetX();
        double GetY();
        void SetText(string* t);

        void Draw();

    private:
        vector<sf::Text*> spec_chara;
        sf::Text* txt = NULL;
        sf::RenderWindow* w = NULL;
};