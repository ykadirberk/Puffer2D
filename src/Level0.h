#pragma once
#include <SFML/Graphics.hpp>
#include "wVector2D.h"
#include "Button.h"
#include "Text.h"
#include "Character.h"
#include "AnimationData.h"
#include "PlainField.h"
#include "TextFactory.h"
#include "Camera.h"

class Level0 {
    public:
        Level0(sf::RenderTexture* guih, sf::RenderTexture* ingameh, sf::Font* fnt);
        ~Level0();

        void draw(double deltaTime, sf::RenderWindow* wind, Puffer::Camera* ingame);

    private:
        sf::RenderTexture* gui_handler = NULL;
        sf::RenderTexture* ingame_handler = NULL;
        sf::Font* font = NULL;

        Puffer::Text* writeatext = NULL;
        Puffer::PlainField* field = NULL;
        Puffer::TextFactory* factory = NULL;
        Puffer::Button* but = NULL;
        Puffer::Character* cha = NULL;
};