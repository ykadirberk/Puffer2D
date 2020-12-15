#pragma once
#include <SFML/Graphics.hpp>
#include "wVector2D.h"
#include "Button.h"
#include "Text.h"
#include "Character.h"
#include "AnimationData.h"
#include "PlainField.h"
#include "TextFactory.h"

class Level0 {
    public:
        Level0(sf::RenderTexture* guih, sf::RenderTexture* ingameh, sf::Font* fnt);
        ~Level0();

        void draw(double deltaTime, sf::RenderWindow* wind, sf::View* ingame);

    private:
        sf::RenderTexture* gui_handler = NULL;
        sf::RenderTexture* ingame_handler = NULL;
        sf::Font* font = NULL;

        Text* writeatext = NULL;
        PlainField* field = NULL;
        TextFactory* factory = NULL;
        Button* but = NULL;
        Character* cha = NULL;
};