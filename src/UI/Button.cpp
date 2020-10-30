#include "Button.h"

Button::Button(sf::RenderWindow* window, string path, double sX, double sY, double width, double height) {
    texture = new sf::Texture();
    sprite = new sf::Sprite();
    if (!texture->loadFromFile(path)) { //! Texture dosyadan yüklenir. Bu kod daha sonra değiştirilecek.
    	std::cout << "[LOG] Couldn't load button texture." << std::endl; //texture yüklenemezse hata mesajı
	} else {
		std::cout << "[LOG] Button texture loaded." << std::endl; //texture yüklendi mesajı
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

Button::~Button() {

}

void Button::SetPosition(double x, double y) {
    sprite->setPosition(x, y);
    iX = x;
    iY = y;
}

void Button::Move(double x, double y){
    sprite->move(x, y);
    iX += x;
    iY += y;
}

double Button::GetX(){
    return iX;
}

double Button::GetY(){
    return iY;
}


void Button::Draw(){
    w->draw(*sprite);
}
