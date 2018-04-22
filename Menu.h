#pragma once
#include <SFML\Graphics.hpp>
#include "Info\Info.h"
#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu(int options, std::string str1, std::string str2, std::string str3, std::string str4, std::string str5);
	Menu(int options, std::string str1, std::string str2, std::string str3, std::string str4);
	Menu(int options, std::string str1, std::string str2, std::string str3);
	Menu(int options, std::string str1, std::string str2);
	Menu(int options, std::string str1);
	~Menu();

	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	int getPressedItem() { return selectedItemIndex; }
	void setOptions(int opt) { this->numberOfOptions = opt; }
	int getOptions() { return numberOfOptions; }
	void customPosition(bool shrink);
	int loginMenu();
	int registerNewUser();
private:
	int selectedItemIndex;
	int numberOfOptions;
	int options;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

