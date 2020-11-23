#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using namespace std;

class PlainField {
    public:
        PlainField(sf::RenderWindow* window);
        ~PlainField();

        void SetPosition(double x, double y);
        void SetFieldLength(double x, double y);
        double GetWidth();
        double GetHeight();
        double GetX();
        double GetY();
        void Draw();

    private:
        sf::RenderWindow* w = NULL;
        double dx = 0, dy = 0, dwidth = 0, dheight = 0;
};