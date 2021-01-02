#pragma once
#include <string>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "AnimationData.h"
#include "Animator.h"
using std::string;

namespace Puffer {
    class Button {
        public:
            Button(sf::RenderTexture* rtext,string path ,double sX, double sY, double width, double height, string datapath);
            ~Button();

            void SetPosition(double x, double y);
            void SetSize(double w, double h);
            void Move(double x, double y);
            double GetX();
            double GetY();

            void Calculations(double delta, sf::RenderWindow* wind);
            void Draw();
        private:
            Animator* animator = NULL;
            sf::RenderTexture* w = NULL;
            double iWidth = 0, iHeight = 0; //Sprite'ın olmasını istediğimiz büyüklüğü
            double iX = 0, iY = 0; //Sprite'ın olmasını istediğimiz konumu
            double mX = 0, mY = 0; //Mouse pozisyonu kaydediliyor.
            bool mousePressed = false;
    };
}
