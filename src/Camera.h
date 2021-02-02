#pragma once
#include <SFML/Graphics.hpp>
#include "wVector2D.h"
#include "Character.h"
using namespace std;

namespace Puffer{
    class Camera{
        public:
            Camera(wVector2D* center_pos, wVector2D* size , wVector2D* border);
            ~Camera();

            void Shake();
            void followc(Puffer::Character* object_to_follow);
            void followc_in_borders(Puffer::Character* object_to_follow);


            void move();

            sf::View* getCam();
            wVector2D* getCenter();
            void setCenter(wVector2D center);
            void setCenter(double x, double y);

            void setBorder(wVector2D border);
            void setBorder(double x,double y);

            void setCamSize(wVector2D size);
            void setCamSize(double x, double y);
        
        private:
            sf::View* cam = NULL;
            wVector2D* cam_center = NULL;
            wVector2D* camsize = NULL;
            wVector2D* borders = NULL;
    };
}