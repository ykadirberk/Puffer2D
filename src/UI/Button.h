#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
using std::string;

class Button {
    public:
        Button(sf::RenderWindow* window, double sX, double sY, double width, double height);
        ~Button();

        void SetPosition(double x, double y);
        void SetSize(double w, double h);
        void Move(double x, double y);
        double GetX();
        double GetY();

        void Calculations();
        void Draw();
    private:
        sf::RenderWindow* w = NULL;
        sf::Texture* texture0 = NULL;
        sf::Texture* texture1 = NULL;
        sf::Texture* texture2 = NULL;
        sf::Sprite* sprite = NULL;
        double oW = 0, oH = 0; //Texture'un yüklendiği haldeki büyüklüğü
        double iWidth = 0, iHeight = 0; //Sprite'ın olmasını istediğimiz büyüklüğü
        double iX = 0, iY = 0; //Sprite'ın olmasını istediğimiz konumu
        double mX = 0, mY = 0; //Mouse pozisyonu kaydediliyor.
        bool mousePressed = false;
};