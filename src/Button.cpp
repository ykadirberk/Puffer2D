#include "Button.h"

Button::Button(sf::RenderWindow* window,string path ,double sX, double sY, double width, double height, string datapath) {
    w = window;
    //Ekrana çizilmesi istenen büyüklükler kaydediliyor.
    iWidth = width;
    iHeight = height;
    //Ekrana çizilmesi istenen konum kaydediliyor.
    iX = sX;
    iY = sY;

    animator = new Animator(path, datapath);
    //Sprite elle girilen büyüklük desteklemediği için scale cinsine çevirerek istenen boyuta getiriliyor.
    animator->GetSprite()->setScale(iWidth/animator->GetScaleRule().x, iHeight/animator->GetScaleRule().y);
    animator->GetSprite()->setPosition(sX, sY);
}

Button::~Button() {

}

void Button::SetPosition(double x, double y) {
    animator->GetSprite()->setPosition(x, y);
    iX = x;
    iY = y;
}

void Button::Move(double x, double y){
    animator->GetSprite()->move(x, y);
    iX += x;
    iY += y;
}

double Button::GetX(){
    return iX;
}

double Button::GetY(){
    return iY;
}

void Button::Calculations(double delta) {
    mX = sf::Mouse::getPosition(*w).x;
    mY = sf::Mouse::getPosition(*w).y;

    if (mX >= iX 
        && mX <= iX + iWidth 
        && mY >= iY
        && mY <= iY + iHeight
        && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        //Mouse Butona tıkladı
        animator->CalculateSprite("[PRESSED]",delta);
        mousePressed = true;
    } else if (mX >= iX 
        && mX <= iX + iWidth 
        && mY >= iY
        && mY <= iY + iHeight){
        //Mouse Butonun üstünde
        animator->CalculateSprite("[HOVER]", delta);
        if (mousePressed) {
            //execution
            printf("[LOG] Button function executed.\n");
            mousePressed = false;
        }
    } else {
        //Mouse Butonun üstünde değil ve tıklanmıyor.
        mousePressed = false;
        animator->CalculateSprite("[REGULAR]", delta);
    }
}


void Button::Draw(){
    w->draw(*animator->GetSprite());
}
