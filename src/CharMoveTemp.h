#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/Window.hpp>

class CharMoveTemp{
    public:
        virtual void calculate() {
            std::cout << "Player movement is not defined.";
        }
};