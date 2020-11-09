#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class TextField {
    public:
        TextField(sf::RenderWindow* window, sf::Font* font, string text);
        ~TextField();

        void SetPosition(double x, double y);
        void SetFieldSize(double x, double y);
        void SetFontSize(double a);
        double GetX();
        double GetY();
        void Draw();

    private:
        string msg;
        vector<sf::Text*> texts;
        sf::Font* fnt;
        sf::RenderWindow* w = NULL;
        double dx = 0, dy = 0, dwidth = 0, dheight = 0, dfontsize;


};