#include <string>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "MessageHandler.h"
#include "wVector2D.h"
#include "UI/Button.h"
#include "UI/Text.h"
#include "Character.h"
using namespace std;



int main() {
	cout << "[LOG] Engine starting" << endl;
	//pencereyi ekrana verir, özelliklerini tanımlar
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Hello, world!");

	sf::Clock clock; //zaman kavramını tanımlar
	double deltaTime = 0; //Zamandaki değişimi tanımladım

	sf::Font font; //font tanımlanır
	if (!font.loadFromFile("retro-gaming.ttf")) { //! Font dosyadan yüklenir. Bu kod daha sonra değiştirilecek.
    	cout << "[LOG] Couldn't load font." << endl; //font yüklenemezse hata mesajı
	} else {
		cout << "[LOG] Font (Retro-Gaming) loaded." <<endl; //font yüklendi mesajı
	}
	//Ekrana yazılması istenen bir yazının tanımlanması
	Text* writeatext = new Text(window, &font, "Bu bir oyundur.", 18, sf::Color::Yellow, sf::Text::Regular);

	//Ekrana çizilmesi istenen buton tanımlaması
	//!Şu an işlevsiz
	Button* but = new Button(window, "texture.png", 100, 100, 300, 300);

	//Ekrana çizilmesi istenen karakter tanımlaması
	//!Şu an işlevsiz
	Character* cha = new Character(window, "character-tiles.png", 600, 100, 180, 160);

	while(window->isOpen()) {
		deltaTime = clock.getElapsedTime().asSeconds(); //zamandaki değişimi buldum
		clock.restart(); //zamandaki değişimi bulabilmek için renderdan önce ve son kayıttan sonra zaman değişkenini sıfırladım

		//input denetleyicisi
		sf::Event event;
		while(window->pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window->close();

		}

		but->Move(100*deltaTime, 100*deltaTime);

		window->clear(); //görüntüyü temizler (yoksa önceki frame'den görüntü kalır)
		//? GAME DRAWINGS

		but->Draw();

		//? GUI DRAWINGS
		writeatext->Draw(); //yazılması istenen görüntüyü yazdıran fonksiyon
		window->display(); //pencereyi çizer
	}
	return 0;
}