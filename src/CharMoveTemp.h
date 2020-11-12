#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <stdio.h>
#include <SFML/Window.hpp>

class CharMoveTemp{
    public:
        virtual void calculate() {
            printf("Player movement is not defined.");
        }
};