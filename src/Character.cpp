#include "Character.h"


Character::Character(sf::RenderTexture* rtext, string path, double sX, double sY, double width, double height, string datapath) {
    position = new wVector2D(sX,sY);;
    anima = new Animator(path,datapath);
    r = rtext;
    
    //Movespeed.
    speed = new wVector2D(200.0, 200.0);

    //Storing sizes of character.
    iWidth = width;
    iHeight = height;
    //sf::Sprite uses Scale as a size paramater. This statement manipulates it to act like size.
    anima->GetSprite()->setScale(iWidth/anima->GetScaleRule().x, iHeight/anima->GetScaleRule().y);
    //Provided position implemented to sprite object.
    anima->GetSprite()->setPosition(sX, sY);
}

Character::~Character() {

}

void Character::SetPosition(double x, double y) {
    anima->GetSprite()->setPosition(x, y);
}

void Character::Move(double x, double y){
    anima->GetSprite()->move(x, y);
}

sf::Sprite* Character::GetSprite() {
    return anima->GetSprite();
}

wVector2D Character::GetPosition() {
    wVector2D ret = *position;
    return ret;
}


void Character::Draw(){
    r->draw(*anima->GetSprite());
}

void Character::Calculate(double delta) {
    //Defining move of character
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up) || sf::Keyboard::isKeyPressed( sf::Keyboard::W) ) {
        anima->CalculateSprite("[UP]",delta);
        position->y += (-1)*speed->y*delta;

    } else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down) || sf::Keyboard::isKeyPressed( sf::Keyboard::S) ) {
        anima->CalculateSprite("[DOWN]",delta);
        position->y += speed->y*delta;
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right) || sf::Keyboard::isKeyPressed( sf::Keyboard::D) ) {
        anima->CalculateSprite("[RIGHT]",delta);
        position->x += speed->x*delta;
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left) || sf::Keyboard::isKeyPressed( sf::Keyboard::A) ) {
        anima->CalculateSprite("[LEFT]",delta);
        position->x += (-1)*speed->x*delta;
    } else {
        anima->CalculateSprite("[IDLE]",delta);
    }

    anima->GetSprite()->setPosition(position->x,position->y);
}