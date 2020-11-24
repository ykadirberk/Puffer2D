#include <string>
#include <stdio.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "wVector2D.h"
#include "Button.h"
#include "Text.h"
#include "Character.h"
#include "SheetAnimator.h"
#include "PlayerMovement.h"
using namespace std;



int main() {
	cout << "[LOG] Engine starting" << endl;
	//pencereyi ekrana verir, özelliklerini tanımlar
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Hello, world!");

	sf::Clock clock; //zaman kavramını tanımlar
	sf::Clock clock2;
	double deltaTime = 0; //Zamandaki değişimi tanımladım

	sf::Font font; //font tanımlanır
	if (!font.loadFromFile("kongtext.ttf")) { //! Font dosyadan yüklenir. Bu kod daha sonra değiştirilecek.
    	printf("[LOG] Couldn't load font. \n"); //font yüklenemezse hata mesajı
	} else {
		printf("[LOG] Font (kongtext) loaded. \n"); //font yüklendi mesajı
	}
	//Ekrana yazılması istenen bir yazının tanımlanması
	Text* writeatext = new Text(window, &font, "Bu bir oyundur.", 18, sf::Color::Yellow);
	writeatext->SetDeltaTimer(&deltaTime);
	SheetAnimator* sa = new SheetAnimator("GUI/BUTTON/button.data");

	//Ekrana çizilmesi istenen buton tanımlaması
	//!Şu an işlevsiz
	Button* but = new Button(window, "GUI/BUTTON/button.png",100, 300, 196, 88, 48, 22);

	//Ekrana çizilmesi istenen karakter tanımlaması
	//!Şu an işlevsiz
	Character* cha = new Character(window, "character-tiles.png", 600, 100, 180, 160);
	PlayerMovement* mov = new PlayerMovement(cha->GetSprite());
	cha->SetMovementClass(mov);
	
	while(window->isOpen()) {
		deltaTime = clock.getElapsedTime().asSeconds(); //zamandaki değişimi buldum
		clock.restart();  //zamandaki değişimi bulabilmek için renderdan önce ve son kayıttan sonra zaman değişkenini sıfırladım

		//input denetleyicisi
		sf::Event event;
		while(window->pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window->close();

		}

		//but->Move(100*deltaTime, 100*deltaTime);
		//? CALCULATIONS
		but->Calculations();
		cha->Calculate();
		writeatext->Calc();

		window->clear(); //görüntüyü temizler (yoksa önceki frame'den görüntü kalır)
		//? GAME DRAWINGS

		
		//? GUI DRAWINGS
		writeatext->Draw(); //yazılması istenen görüntüyü yazdıran fonksiyon
		but->Draw();
		window->display(); //pencereyi çizer
	}
	return 0;
}