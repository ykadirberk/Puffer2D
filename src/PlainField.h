#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "wVector2D.h"

using namespace std;

namespace Puffer {
    class PlainField {
        public:
            PlainField(sf::RenderTexture* rtext);
            ~PlainField();

            void SetPosition(double x, double y);
            void SetFieldLength(double x, double y);
            v2d GetSize();
            v2d GetPosition();
            void Draw();

        private:
            sf::RenderTexture* r = NULL;
            v2d* position = NULL;
            v2d* size = NULL;
    };
}

