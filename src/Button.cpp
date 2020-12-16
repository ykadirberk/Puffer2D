#include "Button.h"

Button::Button(sf::RenderTexture* rtext,string path ,double sX, double sY, double width, double height, string datapath) {
    w = rtext;
    //Size values are stored. 
    iWidth = width;
    iHeight = height;
    //Position on screen is stored.
    iX = sX;
    iY = sY;

    animator = new Animator(path, datapath);
    //sf::Sprite uses Scale as a size paramater. This statement manipulates it to act like size.
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

void Button::Calculations(double delta, sf::RenderWindow* wind) {
    // get the current mouse position in the window
    sf::Vector2i pixelPos = sf::Mouse::getPosition(*wind);
    // convert it to world coordinates
    sf::Vector2f worldPos = wind->mapPixelToCoords(pixelPos);
    mX = worldPos.x;
    mY = worldPos.y;

    if (mX >= iX 
        && mX <= iX + iWidth 
        && mY >= iY
        && mY <= iY + iHeight
        && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        //Mouse pressed the button
        animator->CalculateSprite("[PRESSED]",delta);
        mousePressed = true;
    } else if (mX >= iX 
        && mX <= iX + iWidth 
        && mY >= iY
        && mY <= iY + iHeight){
        //Mouse is hovering the button
        animator->CalculateSprite("[HOVER]", delta);
        if (mousePressed) {
            //execution
            printf("[LOG] Button function executed.\n");
            mousePressed = false;
        }
    } else {
        //Mouse is not hovering the button nor pressing.
        mousePressed = false;
        animator->CalculateSprite("[REGULAR]", delta);
    }
}


void Button::Draw(){
    w->draw(*animator->GetSprite());
}
