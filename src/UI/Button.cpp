#include "Button.h"

Button::Button(sf::RenderWindow* window, double sX, double sY, double width, double height) {
    texture0 = new sf::Texture();
    texture1 = new sf::Texture();
    texture2 = new sf::Texture();
    sprite = new sf::Sprite();
    if (!texture0->loadFromFile("GUI/BUTTON/button0.png")) { //! Texture dosyadan yüklenir. Bu kod daha sonra değiştirilecek.
    	std::cout << "[LOG] Couldn't load button texture0." << std::endl; //texture yüklenemezse hata mesajı
	} else {
		std::cout << "[LOG] Button texture0 loaded." << std::endl; //texture yüklendi mesajı
	}

    if (!texture1->loadFromFile("GUI/BUTTON/button1.png")) { //! Texture dosyadan yüklenir. Bu kod daha sonra değiştirilecek.
    	std::cout << "[LOG] Couldn't load button texture1." << std::endl; //texture yüklenemezse hata mesajı
	} else {
		std::cout << "[LOG] Button texture1 loaded." << std::endl; //texture yüklendi mesajı
	}

    if (!texture2->loadFromFile("GUI/BUTTON/button2.png")) { //! Texture dosyadan yüklenir. Bu kod daha sonra değiştirilecek.
    	std::cout << "[LOG] Couldn't load button texture2." << std::endl; //texture yüklenemezse hata mesajı
	} else {
		std::cout << "[LOG] Button texture2 loaded." << std::endl; //texture yüklendi mesajı
	}

    w = window;
    
    //Yüklenen Texture'un gerçek büyüklükleri kaydediliyor.
    oW = texture0->getSize().x; 
    oH = texture0->getSize().y;
    
    //Ekrana çizilmesi istenen büyüklükler kaydediliyor.
    iWidth = width;
    iHeight = height;

    //Ekrana çizilmesi istenen konum kaydediliyor.
    iX = sX;
    iY = sY;
    
    sprite->setTexture(*texture0);
    //Sprite elle girilen büyüklük desteklemediği için scale cinsine çevirerek istenen boyuta getiriliyor.
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

void Button::Calculations() {
    mX = sf::Mouse::getPosition(*w).x;
    mY = sf::Mouse::getPosition(*w).y;
    //std::cout << mX << " " << mY << std::endl;

    if (mX >= iX 
        && mX <= iX + iWidth 
        && mY >= iY
        && mY <= iY + iHeight) {
            //Mouse butonun üstüne
            sprite->setTexture(*texture1);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sprite->setTexture(*texture2);
                mousePressed = true;
            } else {
                if (mousePressed) {
                    //execution
                    std::cout << "[LOG] Button function executed.\n";
                    mousePressed = false;
                }
            }
    } else {
        mousePressed = false;
        sprite->setTexture(*texture0);
    }
}


void Button::Draw(){
    w->draw(*sprite);
}
