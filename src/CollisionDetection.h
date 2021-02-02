#pragma once
#include <string>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "wVector2D.h"

namespace Puffer {
    
    struct rectangle{
        double posX;
        double posY;
        double sizeX;
        double sizeY;
    };
            
    class CollisionDetection{
        public:
            CollisionDetection(double sX, double sY, double width, double height);
            ~CollisionDetection();
            
            bool RectsColl(rectangle* r1,rectangle* r2);

    };
}