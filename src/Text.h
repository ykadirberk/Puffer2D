#pragma once

#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

namespace Puffer {
    class Text {
        public:
            Text(sf::RenderTexture* rtext, sf::Font* font, string text, int size, sf::Color color);
            ~Text();

            void SetPosition(double x, double y);
            void Move(double x, double y);
            double GetX();
            double GetY();
            void SetText(string* t);
            void SetBoldness(bool b);
            sf::Text* GetTextObject();

            void Calc(double delt);
            bool Draw();

        private:
            sf::Font* dafont = NULL;
            string stringofthis;
            double timer = 0;
            double animation_const = 0.025;
            int counter = 0;
            bool visibility = true;
            bool d_draw = false;
            sf::Text* txt = NULL;
            sf::RenderTexture* r = NULL;
    };
}