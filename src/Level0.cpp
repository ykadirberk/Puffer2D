#include "Level0.h"

Level0::Level0(sf::RenderTexture* guih, sf::RenderTexture* ingameh, sf::Font* fnt) {
    ingame_handler = ingameh;
    gui_handler = guih;
    font = fnt;

	writeatext = new Puffer::Text(ingame_handler, font, "Press ESC to exit.", 18, sf::Color::Yellow);
	writeatext->SetPosition(0,0);

	//Trying PlainField
	field = new Puffer::PlainField(ingame_handler);
	field->SetPosition(200,400);
	field->SetFieldLength(500,500);
	factory = new Puffer::TextFactory(ingame_handler, field, "Merhaba arkadaslar &7bugunku &evideomuzda &1&fben &4arda&eyla birlikte &0bu mal &fprogrami calistirmaya &ecalisiyorum.", font);
	factory->PrepareTexts();

    //Defining button object
	//! Doesn't perform good enough 4now
	but = new Puffer::Button(ingame_handler, "GUI/BUTTON/button.png",50, 50, 196, 88, "GUI/BUTTON/button.data");

	//Defining player
	cha = new Puffer::Character(ingame_handler, "INGAME/PLAYER/character-tiles.png", 600, 100, 90, 80, "INGAME/PLAYER/player.data");
	printf("[LEVEL-0] LOADED.\n");


    //Defining a text
	/*writeatext = new Puffer::Text(gui_handler, font, "Press ESC to exit.", 18, sf::Color::Yellow);
	writeatext->SetPosition(0,0);

	//Trying PlainField
	field = new Puffer::PlainField(gui_handler);
	field->SetPosition(200,400);
	field->SetFieldLength(500,500);
	factory = new Puffer::TextFactory(gui_handler, field, "Merhaba arkadaslar &7bugunku &evideomuzda &1&fben &4arda&eyla birlikte &0bu mal &fprogrami calistirmaya &ecalisiyorum.", font);
	factory->PrepareTexts();

    //Defining button object
	//! Doesn't perform good enough 4now
	but = new Puffer::Button(gui_handler, "GUI/BUTTON/button.png",50, 50, 196, 88, "GUI/BUTTON/button.data");

	//Defining player
	cha = new Puffer::Character(ingame_handler, "INGAME/PLAYER/character-tiles.png", 600, 100, 90, 80, "INGAME/PLAYER/player.data");
	printf("[LEVEL-0] LOADED.\n"); //Load message.*/
}

Level0::~Level0() {
	delete writeatext;
	delete field; 
	delete factory; 
	delete but; 
	delete cha; 
	delete gui_handler;
	delete ingame_handler;
	printf("[DECONSTRUCT-LOG] Level0 class released.\n");
}

void Level0::draw(double deltaTime, sf::RenderWindow* wind, Puffer::Camera* ingame) {
    //? CALCULATIONS
	but->Calculations(deltaTime, wind);
	cha->Calculate(deltaTime); 
    //ingame->setCenter(cha->GetPosition().x, cha->GetPosition().y); //! NOT WORKING FOR NOW //Centers to the character. 
	writeatext->Calc(deltaTime);
	//? GAME DRAWINGS
	cha->Draw();
	ingame->followc_in_borders(cha);	
	//? GUI DRAWINGS
	factory->DrawTexts(deltaTime);
	writeatext->Draw();
	but->Draw();
	ingame_handler->setView(*ingame->getCam());//To center to the character
}
