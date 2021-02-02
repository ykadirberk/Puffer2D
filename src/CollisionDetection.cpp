#include "CollisionDetection.h"
    
bool Puffer::CollisionDetection::RectsColl(rectangle* r1,rectangle* r2){
    return (r1->posX < r2->posX + r2->sizeX && r1->posY < r2->posY + r2->sizeY &&
    r1->posX + r1->sizeX > r2->posX && r1->posY + r1->sizeY > r2->posY);
}