#include "Character.h"


Character::Character(sf::RenderWindow* window, string path, double sX, double sY, double width, double height, string datapath) {
    anima = new Animator(path,datapath);
    w = window;
    
    iWidth = width;
    iHeight = height;
    iX = sX;
    iY = sY;
    anima->GetSprite()->setScale(iWidth/anima->GetScaleRule().x, iHeight/anima->GetScaleRule().y);
    anima->GetSprite()->setPosition(sX, sY);
}

Character::~Character() {

}

void Character::SetPosition(double x, double y) {
    anima->GetSprite()->setPosition(x, y);
    iX = x;
    iY = y;
}

void Character::Move(double x, double y){
    anima->GetSprite()->move(x, y);
    iX += x;
    iY += y;
}

sf::Sprite* Character::GetSprite() {
    return anima->GetSprite();
}

double Character::GetX(){
    return iX;
}

double Character::GetY(){
    return iY;
}


void Character::Draw(){
    w->draw(*anima->GetSprite());
}

void Character::Calculate(double delta) {
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up) || sf::Keyboard::isKeyPressed( sf::Keyboard::W) ) {
        anima->CalculateSprite("[UP]",delta);
        anima->GetSprite()->move(0.f,-0.2f);

    } else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down) || sf::Keyboard::isKeyPressed( sf::Keyboard::S) ) {
        anima->CalculateSprite("[DOWN]",delta);
        anima->GetSprite()->move(0.f,0.2f);
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right) || sf::Keyboard::isKeyPressed( sf::Keyboard::D) ) {
        anima->CalculateSprite("[RIGHT]",delta);
        anima->GetSprite()->move(0.2f,0.f);
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left) || sf::Keyboard::isKeyPressed( sf::Keyboard::A) ) {
        anima->CalculateSprite("[LEFT]",delta);
        anima->GetSprite()->move(-0.2f,0.f);
    } else {
        anima->CalculateSprite("[IDLE]",delta);
    }
}