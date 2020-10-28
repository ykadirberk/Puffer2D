#include <SFML/Graphics.hpp>

int main()
{
	//commit webhook denemesi
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, world!");
	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();

		}
		window.clear();
		window.display();

	}
	return 0;
}