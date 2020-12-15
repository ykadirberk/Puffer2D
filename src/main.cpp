#include <string>
#include <stdio.h>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Level0.h"
using namespace std;



int main() {
	cout << "[LOG] Engine starting" << endl;
	//?Creation of window
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1280, 720), "SFML ENGINE"); //Window's size is 1280x720
	window->setFramerateLimit(144);	//Setting framerate limit to 144

	sf::Clock clock; //Defining time
	double deltaTime = 0; //Defining change in time

	//Defining gui camera component
	sf::View* gui_cam = new sf::View(sf::FloatRect(0.f,0.f,1280.f,720.f)); //The part that will be showed on screen
	sf::RenderTexture* gui_handler = new sf::RenderTexture(); //Render object
	gui_handler->create(1280,720);
	gui_handler->setView(*gui_cam);
	const sf::Texture& gui_texture = gui_handler->getTexture(); //Created a reference to renderer's texture
	sf::Sprite gui_comps(gui_texture); //Preparing reference texture to get rendered.
	
	//Defining in-game camera component
	sf::View* ingame_cam = new sf::View(sf::FloatRect(0.f,0.f,1280.f,720.f)); //The part that will be showed on screen
	sf::RenderTexture* ingame_handler = new sf::RenderTexture(); //Render object
	ingame_handler->create(1280,720);
	ingame_handler->setView(*ingame_cam);
	const sf::Texture& ingame_texture = ingame_handler->getTexture(); //Created a reference to renderer's texture
	sf::Sprite ingame_comps(ingame_texture); //Preparing reference texture to get rendered.

	//Defining font
	sf::Font font;
	if (!font.loadFromFile("kongtext.ttf")) { //! Font being read from file. Will be replaced later.
    	printf("[LOG] Couldn't load font. \n"); //Message for load error
	} else {
		printf("[LOG] Font (kongtext) loaded. \n"); //Message if font loaded.
	}

	//Defining levels
	Level0 level0(gui_handler,ingame_handler,&font);

	//?GAME LOOP
	while(window->isOpen()) {
		deltaTime = clock.getElapsedTime().asSeconds(); //Finding the change in time
		clock.restart();  //To calculate the change in time, clock variable will be resetted sa that it can start from zero.

		//Event handler
		sf::Event event;
		while(window->pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window->close();
		}

		//?Clearing renderers
		ingame_handler->clear(sf::Color::Transparent);
		gui_handler->clear(sf::Color::Transparent);
		window->clear(sf::Color::Transparent); 
		
		//?Drawing Levels
		level0.draw(deltaTime,window,ingame_cam);
		
		//? Displaying layers
		ingame_handler->display();
		gui_handler->display();

		window->draw(ingame_comps);
		window->draw(gui_comps);

		window->display(); //Draws final image
	}

	return 0;
}