#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "MessageHandler.h"

MessageHandler* msg = new MessageHandler();

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, world!");

	
	sf::Clock clock; //zaman kavramını tanımlar
	int deltaTime = 0; //Zamandaki değişimi tanımladım

	while(window.isOpen()) {
		deltaTime = clock.getElapsedTime().asMilliseconds(); //zamandaki değişimi buldum
		clock.restart(); //zamandaki değişimi bulabilmek için renderdan önce ve son kayıttan sonra zaman değişkenini sıfırladım

		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window.close();

		}
		window.clear(); //görüntüyü temizler (yoksa önceki frame'den görüntü kalır)
		window.display(); //pencereyi çizer
		
		

	}
	return 0;
}