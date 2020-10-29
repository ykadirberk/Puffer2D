#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "MessageHandler.h"
#include "wVector2D.h"

MessageHandler* msg = new MessageHandler();

int main() {
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, world!");

	sf::Clock clock; //zaman kavramını tanımlar
	double deltaTime = 0; //Zamandaki değişimi tanımladım

	while(window.isOpen()) {
		deltaTime = clock.getElapsedTime().asSeconds(); //zamandaki değişimi buldum
		std::cout << "deltaTime: " <<deltaTime << std::endl; //!sonra silinecek. komut istemcisi üstünden zamandaki değişimi gözlemliyoruz.
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