#include "Camera.h"

Puffer::Camera::Camera(double posx, double posy, double sizex, double sizey , double borderx, double bordery){
    cam_center = new v2d();
    camsize = new v2d();
    borders = new v2d();

    camsize->x = sizex; camsize->y = sizey;
    borders->x = borderx; borders->y = bordery;
    cam_center->x = sizex/2 + 1; cam_center->y = sizey/2 + 1;

    cam = new sf::View(sf::FloatRect(0.f,0.f,camsize->x,camsize->y));
}

Puffer::Camera::~Camera(){}

void Puffer::Camera::followc(Puffer::Object* object_to_follow){
    cam_center->x = object_to_follow->GetPosition()->x + (object_to_follow->GetSize()->x / 2);
    cam_center->y = object_to_follow->GetPosition()->y + (object_to_follow->GetSize()->y / 2);

    cam->setCenter(cam_center->x, cam_center->y);
}

void Puffer::Camera::followc_in_borders(Puffer::Object* object_to_follow){
    cam_center->x = object_to_follow->GetPosition()->x + (object_to_follow->GetSize()->x / 2);
    cam_center->y = object_to_follow->GetPosition()->y + (object_to_follow->GetSize()->y / 2);

    if (!(cam_center->x + (camsize->x/2) <= borders->x)) {
        cam_center->x = borders->x - (camsize->x/2);
    }

    if (!(cam_center->y + (camsize->y/2) <= borders->y)) {
        cam_center->y = borders->y - (camsize->y/2);
    }

    if(!(cam_center->y - (camsize->y/2) >= 0)) {
        cam_center->y = camsize->y/2;
    }

    if(!(cam_center->x - (camsize->x/2) >= 0)) {
        cam_center->x = camsize->x/2;
    }

    cam->setCenter(cam_center->x, cam_center->y);
}

sf::View* Puffer::Camera::getCam(){
    return cam;
}

wVector2D* Puffer::Camera::getCenter(){
    return cam_center;
}

void Puffer::Camera::setCenter(wVector2D center){
    cam_center = &center;
    cam->setCenter(cam_center->x, cam_center->y);
}

void Puffer::Camera::setCenter(double x, double y){
    cam_center->x = x;
    cam_center->y = y;
    cam->setCenter(cam_center->x, cam_center->y);
}

void Puffer::Camera::setBorder(wVector2D border){
    borders = &border;
}

void Puffer::Camera::setBorder(double x, double y){
    borders->x = x;
    borders->y = y;
}

void Puffer::Camera::setCamSize(wVector2D size){
    camsize = &size;
    cam->setSize(size.x, size.y);
}

void Puffer::Camera::setCamSize(double x, double y){
    camsize->x = x;
    camsize->y = y;
    cam->setSize(x, y);
}