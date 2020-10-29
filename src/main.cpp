#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "MessageHandler.h"
#include "wVector2D.h"
#include "UI/Button.h"
#include "UI/Text.h"

using namespace std;

int main() {
	
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Hello, world!");

	sf::Clock clock; //zaman kavramını tanımlar
	double deltaTime = 0; //Zamandaki değişimi tanımladım

	sf::Font font;
	if (!font.loadFromFile("retro-gaming.ttf")) {
    	cout << "Couldn't load font.";
	}

	Text* writeatext = new Text(window, &font, "yazi", 50, sf::Color::White, sf::Text::Bold);

	while(window->isOpen()) {
		deltaTime = clock.getElapsedTime().asSeconds(); //zamandaki değişimi buldum
		cout << "deltaTime: " <<deltaTime << endl; /*
			!sonra silinecek. komut istemcisi üstünden zamandaki değişimi gözlemliyoruz. performansa etkisi çok büyük
		*/
		clock.restart(); //zamandaki değişimi bulabilmek için renderdan önce ve son kayıttan sonra zaman değişkenini sıfırladım

		sf::Event event;
		while(window->pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window->close();

		}
		
		window->clear(); //görüntüyü temizler (yoksa önceki frame'den görüntü kalır)
		writeatext->DrawText();
		window->display(); //pencereyi çizer
		
		

	}
	return 0;
}