#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "CharMoveTemp.h"
using std::string;

class Character {
    public:
        Character(sf::RenderWindow* window, string path, double sX, double sY, double width, double height);
        ~Character();

        void SetPosition(double x, double y);
        void SetSize(double w, double h);
        void Move(double x, double y);
        sf::Sprite* GetSprite();
        double GetX();
        double GetY();

        void Draw();
        void Calculate();
        void SetMovementClass(CharMoveTemp* temp);

    private:
        CharMoveTemp* movement = NULL;
        sf::RenderWindow* w = NULL;
        sf::Texture* texture = NULL;
        sf::Sprite* sprite = NULL;
        double oW = 0, oH = 0; //Texture'un yüklendiği haldeki büyüklüğü
        double iWidth = 0, iHeight = 0; //Sprite'ın olmasını istediğimiz büyüklüğü
        double iX = 0, iY = 0; //Sprite'ın olmasını istediğimiz konumu
};