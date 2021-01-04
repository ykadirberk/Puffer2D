#include "Character.h"


Puffer::Character::Character(sf::RenderTexture* rtext, string path, double sX, double sY, double width, double height, string datapath) {
    anima = new Animator(path,datapath);
    r = rtext;
    
    position = new wVector2D(sX,sY);
    //Movespeed.
    speed = new wVector2D(200.0, 200.0);
    //Storing sizes of character.
    rect_sizes = new wVector2D(width, height);

    //sf::Sprite uses Scale as a size paramater. This statement manipulates it to act like size.
    anima->GetSprite()->setScale(rect_sizes->x/anima->GetScaleRule().x, rect_sizes->y/anima->GetScaleRule().y);
    //Provided position implemented to sprite object.
    anima->GetSprite()->setPosition(sX, sY);
}

Puffer::Character::~Character() {
    delete position;
    delete speed;
    delete anima;
    printf("[DECONSTRUCT-LOG] Character class released.\n");
}

void Puffer::Character::SetPosition(double x, double y) {
    anima->GetSprite()->setPosition(x, y);
}

void Puffer::Character::Move(double x, double y){
    anima->GetSprite()->move(x, y);
}

sf::Sprite* Puffer::Character::GetSprite() {
    return anima->GetSprite();
}

wVector2D Puffer::Character::GetPosition() {
    wVector2D ret = *position;
    return ret;
}


void Puffer::Character::Draw(){
    r->draw(*anima->GetSprite());
}

void Puffer::Character::Calculate(double delta) {
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