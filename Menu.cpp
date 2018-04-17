#include "Menu.h"


//this first constructor is default from the tutorial
/*Menu::Menu(int width, int height)
{
if(!font.loadFromFile("arial.ttf")){//handle error??
}

menu[0].setFont(font);
menu[0].setFillColor(sf::Color::Blue);
menu[0].setString("Login"); //dummy strings
menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

menu[1].setFont(font);
menu[1].setFillColor(sf::Color::White);
menu[1].setString("Options"); //dummy strings
menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

menu[2].setFont(font);
menu[2].setFillColor(sf::Color::White);
menu[2].setString("Exit"); //dummy strings
menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

selectedItemIndex = 0;
}*/
//this constructor is my attempt at creating a generalized menu constructor for all possible menus
Menu::Menu(int options, std::string str1, std::string str2, std::string str3)//3 options
{
	if (!font.loadFromFile("arial.ttf")) {}//need to add error handle
	setOptions(options);
	std::string strArr[3] = { str1, str2, str3 };

	for (int i = 0; i < options; i++) {
		menu[i].setFont(font);
		menu[i].setFillColor(sf::Color::White);
		if (i == 0)
			menu[i].setFillColor(sf::Color::Blue);
		menu[i].setString(strArr[i]);
		menu[i].setPosition(sf::Vector2f(600 / 2, 600 / (MAX_NUMBER_OF_ITEMS + 1)* (i + 1)));
		//not dynamic window sizing here, may need to fix, but all windows should be same size
	}
	selectedItemIndex = 0;


}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)//this makes the menu appear in the window I think
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
//use up arrow key to change option
void Menu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}

}
//down arrow to change selection
void Menu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}

}