#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

namespace Puffer {
    class PlainField {
        public:
            PlainField(sf::RenderTexture* rtext);
            ~PlainField();

            void SetPosition(double x, double y);
            void SetFieldLength(double x, double y);
            double GetWidth();
            double GetHeight();
            double GetX();
            double GetY();
            void Draw();

        private:
            sf::RenderTexture* r = NULL;
            double dx = 0, dy = 0, dwidth = 0, dheight = 0;
    };
}

