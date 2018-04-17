#include <SFML\Graphics.hpp>
#include "Menu.h"
int main() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML TEST");

	//Menu menu(window.getSize().x, window.getSize().y);
	Menu menu(3, "Login", "Options", "Exit");

	while (window.isOpen()) {
		//handle events

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.moveUp();
					break;
				case sf::Keyboard::Down:
					menu.moveDown();
					break;
				case sf::Keyboard::Return:
					switch(menu.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						window.close();
						break;
					}
					break;
						//implement more options
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();

		menu.draw(window);
		//draw, implement stuff
		window.display();

	}
	return 0;
}