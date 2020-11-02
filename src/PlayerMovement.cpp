#include "PlayerMovement.h"

PlayerMovement::PlayerMovement(sf::Sprite* sprite) {
    nsprite = sprite;
}

PlayerMovement::~PlayerMovement() {

}

void PlayerMovement::calculate() {
    
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up) || sf::Keyboard::isKeyPressed( sf::Keyboard::W) )
    {
        nsprite->move(0.f,-1.f);
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down) || sf::Keyboard::isKeyPressed( sf::Keyboard::S) )
    {
        nsprite->move(0.f,1.f);
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right) || sf::Keyboard::isKeyPressed( sf::Keyboard::D) )
    {
        nsprite->move(1.f,0.f);
    }
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left) || sf::Keyboard::isKeyPressed( sf::Keyboard::A) )
    {
        nsprite->move(-1.f,0.f);
    }
}