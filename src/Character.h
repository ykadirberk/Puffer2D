#pragma once
#include <string>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Animator.h"
using std::string;

class Character : public Object {
    public:
        Character(sf::RenderWindow* window, string path, double sX, double sY, double width, double height, string datapath);
        ~Character();

        void SetPosition(double x, double y);
        void SetSize(double w, double h);
        void Move(double x, double y);
        sf::Sprite* GetSprite();
        double GetX();
        double GetY();

        void Draw();
        void Calculate(double delta);

    private:
        Animator* anima = NULL;
        sf::RenderWindow* w = NULL;
        double iWidth = 0, iHeight = 0; //Sprite'ın olmasını istediğimiz büyüklüğü
        double iX = 0, iY = 0; //Sprite'ın olmasını istediğimiz konumu
};