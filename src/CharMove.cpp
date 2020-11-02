#include "CharMove.h"
#include "Character.h"

  while( window.isOpen() )
    {

if( sf::KeyBoard::isKeyPressed( sf::Keyboard::Up) || sf::Keyboard::isKeyPressed( sf::Keyboard::W) )
    {
    character.move(0.f,-1.f);
    }
if( sf::KeyBoard::isKeyPressed( sf::Keyboard::Down) || sf::Keyboard::isKeyPressed( sf::Keyboard::S) )
    {
    character.move(0.f,1.f);
    }
if( sf::KeyBoard::isKeyPressed( sf::Keyboard::Right) || sf::Keyboard::isKeyPressed( sf::Keyboard::D) )
    {
    character.move(1.f,0.f);
    }
if( sf::KeyBoard::isKeyPressed( sf::Keyboard::Left) || sf::Keyboard::isKeyPressed( sf::Keyboard::A) )
    {
    character.move(-1.f,0.f);
    }

    }    