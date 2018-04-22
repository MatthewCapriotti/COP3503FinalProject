#pragma once
#include <SFML\Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	//Menu(int width, int height);
	Menu(int options, std::string str1, std::string str2, std::string str3);
	~Menu();

	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	int getPressedItem() { return selectedItemIndex; }
	void setOptions(int opt) { this->numberOfOptions = opt; }
	int getOptions() { return numberOfOptions; }
	bool loginMenu();
private:
	int selectedItemIndex;
	int numberOfOptions;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

