#include "Camera.h"

Puffer::Camera::Camera(wVector2D* center_pos, wVector2D* size , wVector2D* border){
    cam_center = center_pos;
    camsize = size;
    borders = border;
}

Puffer::Camera::~Camera(){}

void Puffer::Camera::followc(Puffer::Character* object_to_follow){
    cam_center->x = object_to_follow->GetPosition()->x + (object_to_follow->GetSize()->x / 2);
    cam_center->y = object_to_follow->GetPosition()->y + (object_to_follow->GetSize()->y / 2);
    cam->setCenter(cam_center->x, cam_center->y);
}

void Puffer::Camera::followc_in_borders(Puffer::Character* object_to_follow){
    cam_center->x = object_to_follow->GetPosition()->x + (object_to_follow->GetSize()->x / 2);
    cam_center->y = object_to_follow->GetPosition()->y + (object_to_follow->GetSize()->y / 2);

    if(cam->getCenter().x - (cam->getSize().x/2) > 0 && cam->getCenter().x + (cam->getSize().x / 2) < borders->x
    && cam->getCenter().y - (cam->getSize().x/2) > 0 && cam->getCenter().y + (cam->getSize().y / 2) < borders->y)
    {
        cam->setCenter(cam_center->x, cam_center->y);
    }
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