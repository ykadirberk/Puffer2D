#pragma once
#include <string>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Animator.h"
#include "wVector2D.h"
using std::string;

class Character : public Object {
    public:
        Character(sf::RenderTexture* rtext, string path, double sX, double sY, double width, double height, string datapath);
        ~Character();

        void SetPosition(double x, double y);
        void SetSize(double w, double h);
        void Move(double x, double y);
        sf::Sprite* GetSprite();
        wVector2D GetPosition();

        void Draw();
        void Calculate(double delta);

    private:
        wVector2D* position = NULL;
        wVector2D* speed = NULL;
        Animator* anima = NULL;
        sf::RenderTexture* r = NULL;
        double iWidth = 0, iHeight = 0; //Sprite'ın olmasını istediğimiz büyüklüğü
};