#include "Character.h"

Character::Character(sf::RenderWindow* window, string path, double sX, double sY, double width, double height) {
    texture = new sf::Texture();
    sprite = new sf::Sprite();
    if (!texture->loadFromFile(path)) { //! Texture dosyadan yüklenir. Bu kod daha sonra değiştirilecek.
    	std::cout << "[LOG] Couldn't load Character texture." << std::endl; //texture yüklenemezse hata mesajı
	} else {
		std::cout << "[LOG] Character texture loaded." << std::endl; //texture yüklendi mesajı
	}
    w = window;
    
    oW = texture->getSize().x;
    oH = texture->getSize().y;
    
    iWidth = width;
    iHeight = height;
    iX = sX;
    iY = sY;
    
    sprite->setTexture(*texture);
    sprite->setScale(iWidth/oW, iHeight/oH);
    sprite->setPosition(sX, sY);
}

Character::~Character() {

}

void Character::SetPosition(double x, double y) {
    sprite->setPosition(x, y);
    iX = x;
    iY = y;
}

void Character::Move(double x, double y){
    sprite->move(x, y);
    iX += x;
    iY += y;
}

sf::Sprite* Character::GetSprite() {
    return sprite;
}

double Character::GetX(){
    return iX;
}

double Character::GetY(){
    return iY;
}


void Character::Draw(){
    w->draw(*sprite);
}

void Character::Calculate() {
    movement->calculate();
}
void Character::SetMovementClass(CharMoveTemp* temp) {
    movement = temp;
}