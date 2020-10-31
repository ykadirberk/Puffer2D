#include "Button.h"

Button::Button(sf::RenderWindow* window,string path ,double sX, double sY, double width, double height, double xOffset, double yOffset) {
    w = window;
    texture = new sf::Texture();
    if (!texture->loadFromFile(path)) { //! Texture dosyadan yüklenir. Bu kod daha sonra değiştirilecek.
    	std::cout << "[LOG] Couldn't load button texture." << std::endl; //texture yüklenemezse hata mesajı
	} else {
		std::cout << "[LOG] Button texture loaded." << std::endl; //texture yüklendi mesajı
	}

    //Yüklenen Texture'un gerçek büyüklükleri kaydediliyor.
    oW = xOffset; 
    oH = yOffset;
    
    //Ekrana çizilmesi istenen büyüklükler kaydediliyor.
    iWidth = width;
    iHeight = height;

    //Ekrana çizilmesi istenen konum kaydediliyor.
    iX = sX;
    iY = sY;

    sprite = new sf::Sprite(*texture, sf::IntRect(0,0,48,22));
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
            sprite->setTextureRect(sf::IntRect(0, 22, 48, 22));
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                //sprite->setTexture(*texture2);
                sprite->setTextureRect(sf::IntRect(0, 44, 48, 22));
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
        sprite->setTextureRect(sf::IntRect(0, 0, 48, 22));
    }
}


void Button::Draw(){
    w->draw(*sprite);
}
