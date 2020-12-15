#include "Character.h"


Character::Character(sf::RenderTexture* rtext, string path, double sX, double sY, double width, double height, string datapath) {
    anima = new Animator(path,datapath);
    r = rtext;
    
    //Movespeed.
    speed = 200.0f;

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

double Character::GetX(){
    return anima->GetSprite()->getPosition().x;
}

double Character::GetY(){
    return anima->GetSprite()->getPosition().y;
}


void Character::Draw(){
    r->draw(*anima->GetSprite());
}

void Character::Calculate(double delta) {
    //Defining move of character
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up) || sf::Keyboard::isKeyPressed( sf::Keyboard::W) ) {
        anima->CalculateSprite("[UP]",delta);
        anima->GetSprite()->move(0.f,(-1)*speed*delta);

    } else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down) || sf::Keyboard::isKeyPressed( sf::Keyboard::S) ) {
        anima->CalculateSprite("[DOWN]",delta);
        anima->GetSprite()->move(0.f,speed*delta);
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right) || sf::Keyboard::isKeyPressed( sf::Keyboard::D) ) {
        anima->CalculateSprite("[RIGHT]",delta);
        anima->GetSprite()->move(speed*delta,0.f);
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left) || sf::Keyboard::isKeyPressed( sf::Keyboard::A) ) {
        anima->CalculateSprite("[LEFT]",delta);
        anima->GetSprite()->move((-1)*speed*delta,0.f);
    } else {
        anima->CalculateSprite("[IDLE]",delta);
    }
}