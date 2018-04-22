#include "Menu.h"
#include <iostream> //for testing

Menu::Menu(int options, std::string str1, std::string str2, std::string str3, std::string str4, std::string str5) :options(options)//5 options
{

	if (!font.loadFromFile("arial.ttf")) {}//need to add error handle
	setOptions(options);
	std::string strArr[5] = { str1, str2, str3, str4, str5 };

	for (int i = 0; i < options; i++) {
		menu[i].setFont(font);
		menu[i].setFillColor(sf::Color::White);
		if (i == 0)
			menu[i].setFillColor(sf::Color::Blue);
		menu[i].setString(strArr[i]);
		menu[i].setPosition(sf::Vector2f(1300 / 2, 900 / (options + 1)* (i + 1)));
		//not dynamic window sizing here, may need to fix, but all windows should be same size
	}
	selectedItemIndex = 0;
}

Menu::Menu(int options, std::string str1, std::string str2, std::string str3, std::string str4) :options(options)//4 options
{

	if (!font.loadFromFile("arial.ttf")) {}//need to add error handle
	setOptions(options);
	std::string strArr[4] = { str1, str2, str3, str4 };

	for (int i = 0; i < options; i++) {
		menu[i].setFont(font);
		menu[i].setFillColor(sf::Color::White);
		if (i == 0)
			menu[i].setFillColor(sf::Color::Blue);
		menu[i].setString(strArr[i]);
		menu[i].setPosition(sf::Vector2f(1300 / 2, 900 / (options + 1)* (i + 1)));
		//not dynamic window sizing here, may need to fix, but all windows should be same size
	}
	selectedItemIndex = 0;
}

Menu::Menu(int options, std::string str1, std::string str2, std::string str3) :options(options)//3 options
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
		menu[i].setPosition(sf::Vector2f(1300 / 2, 900 / (options + 1)* (i + 1)));
		//not dynamic window sizing here, may need to fix, but all windows should be same size
	}
	selectedItemIndex = 0;
}

Menu::Menu(int options, std::string str1, std::string str2) :options(options)//2 options
{

	if (!font.loadFromFile("arial.ttf")) {}//need to add error handle
	setOptions(options);
	std::string strArr[2] = { str1, str2 };

	for (int i = 0; i < options; i++) {
		menu[i].setFont(font);
		menu[i].setFillColor(sf::Color::White);
		if (i == 0)
			menu[i].setFillColor(sf::Color::Blue);
		menu[i].setString(strArr[i]);
		menu[i].setPosition(sf::Vector2f(1300 / 2, 900 / (options + 1)* (i + 1)));
		//not dynamic window sizing here, may need to fix, but all windows should be same size
	}
	selectedItemIndex = 0;
}

Menu::Menu(int options, std::string str1) :options(options)//1 option
{

	if (!font.loadFromFile("arial.ttf")) {}//need to add error handle
	setOptions(options);
	std::string strArr[1] = { str1 };

	for (int i = 0; i < options; i++) {
		menu[i].setFont(font);
		menu[i].setFillColor(sf::Color::White);
		if (i == 0)
			menu[i].setFillColor(sf::Color::Blue);
		menu[i].setString(strArr[i]);
		menu[i].setPosition(sf::Vector2f(1300 / 2, 900 / (options + 1)* (i + 1)));
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

void Menu::customPosition(bool shrink)
{
	if (shrink)
	{
		for (int i = 0; i < options; i++) {
			menu[i].setPosition(sf::Vector2f(1300 / 2, (250 / (options + 1)* (i + 1)) + 580));
			//not dynamic window sizing here, may need to fix, but all windows should be same size
		}
		selectedItemIndex = 0;
	}
	else
	{
		for (int i = 0; i < options; i++) {
			menu[i].setPosition(sf::Vector2f(1300 / 2, (450 / (options + 1)* (i + 1)) + 470));
			//not dynamic window sizing here, may need to fix, but all windows should be same size
		}
		selectedItemIndex = 0;
	}
}

int Menu::loginMenu()//needs to be able to check if valid user still
{
	sf::RenderWindow logWindow(sf::VideoMode(500, 400), "LOGIN");
	//sf::Event event;
	sf::Font font; font.loadFromFile("arial.ttf"); //should have error handling if font cant load
	std::string userName;
	std::string passWord;
	bool userExists = false;
	bool userAndPassCorrect = false;
	sf::Text usr("Username: ", font, 20); usr.setPosition(sf::Vector2f(5, 75));
	sf::Text pswrd("Password: ", font, 20); pswrd.setPosition(sf::Vector2f(5, 125));
	sf::Text wrong("", font, 30);
	sf::Text nameText("", font, 20);
	nameText.setPosition(sf::Vector2f(105, 75));
	sf::Text passText("", font, 20); //will need to make this display ***** for privacy purposes
	passText.setPosition(sf::Vector2f(105, 125));
	selectedItemIndex = 0;
	while (logWindow.isOpen()) {
		sf::Event event;
		while (!userExists || !userAndPassCorrect) {

			while (logWindow.pollEvent(event)) {//need to be able to switch with arrow keys

				if (event.type == sf::Event::TextEntered) {
					/*if (event.text.unicode == 40)
						std::cout << "Down!!!!!";
					else if (event.text.unicode == 38)
						std::cout << "UPPPPPP";
					else
						std::cout << "nothing";*/
					switch (selectedItemIndex) {
					case 0:
						if (event.text.unicode < 128 && event.text.unicode != 13 && (event.text.unicode != 38 ||
							event.text.unicode != 40)) {//needs to have backspace functionality
							if (event.text.unicode == 8 && userName.length() > 0) {
								userName.pop_back();
								nameText.setString(userName);
							}
							else {
								userName += static_cast<char>(event.text.unicode);
								nameText.setString(userName);
								//std::string testOutput = userName;
								//std::cout << testOutput << std::endl;
							}
						}
						else if (event.text.unicode == 40)
							selectedItemIndex = 1;
						else if (event.text.unicode == 13)
							selectedItemIndex = 1;
						break;
					case 1://this takes in the password
						if (event.text.unicode < 128 && event.text.unicode != 13 && (event.text.unicode != 38 ||
							event.text.unicode != 40)) {
							if (event.text.unicode == 8 && passWord.length() > 0) {
								passWord.pop_back();
								passText.setString(passWord);
							}
							else {
								passWord += static_cast<char>(event.text.unicode);
								passText.setString(passWord);
								//std::string testOutput = passWord;
								//std::cout << testOutput << std::endl;
							}
						}
						else if (event.text.unicode == 38)
							selectedItemIndex = 0;
						else if (event.text.unicode == 13) {
							userExists = Info::checkUserExists(userName);
							Info::loadUser(userName, passWord);
							userAndPassCorrect = Info::isAuthenticated;

							if (!userExists || !userAndPassCorrect) {
								wrong.setString("Incorrect Username or Password!");
								wrong.setPosition(sf::Vector2f(5, 5));
								userName = "";
								passWord = "";
								selectedItemIndex = 0;
							}
							else
								return 1;
						}

					}
				}
				else if (event.type == sf::Event::Closed)
					logWindow.close();
			}


			logWindow.clear();
			logWindow.draw(usr);
			logWindow.draw(pswrd);
			logWindow.draw(nameText);
			logWindow.draw(passText);
			logWindow.draw(wrong);

			logWindow.display();
		}
	}
	
}

int Menu::registerNewUser()
{
	std::string fields[10] = { "Username:", "Password:", "Name:", "Age:", "Gender:", "Email:",
		"Phone:", "City:", "State:","Zipcode:" };
	bool fieldsFilled[10] = { false };
	bool validInput = false;
	sf::RenderWindow regWindow(sf::VideoMode(500, 400), "Register");
	//sf::Event event;
	sf::Font font; font.loadFromFile("arial.ttf");
	sf::Text field("", font, 30); field.setPosition(sf::Vector2f(5, 75));
	std::string input; 
	sf::Text userIn("", font, 30); userIn.setPosition(sf::Vector2f(105, 75)); //may need to adjust positioning
	sf::Text error("", font, 30); error.setPosition(sf::Vector2f(105, 5)); //generic error message
	while (regWindow.isOpen()) {
		sf::Event event;
		while (!validInput) {//username
			bool notAlNum = false;
			Info::userExists = false;
			field.setString(fields[0]);
			while (regWindow.pollEvent(event)) {
				if (event.type == sf::Event::TextEntered) {
					if (event.text.unicode < 128 && event.text.unicode != 13 && (event.text.unicode != 38 ||//takes in typing to window
						event.text.unicode != 40)) {
						if (event.text.unicode == 8 && input.length() > 0) {
							input.pop_back();
							userIn.setString(input);
						}
						else {
							input += static_cast<char>(event.text.unicode);
							userIn.setString(input);
							std::cout << input;
						}
					}
					else if (event.text.unicode == 13) {//enter key: check if input is good
						for (char c : input)
						{
							if (!isalnum(c))
								notAlNum = true;
						}
						Info::userExists = Info::checkUserExists(input);
						if (!notAlNum || Info::userExists) {
							error.setString("ERROR, try again.");
						}
						else
							validInput = true; //break out of username display loop
					}
				}
			}
			regWindow.clear();
			regWindow.draw(field);
			regWindow.draw(userIn);
			regWindow.draw(error);
			regWindow.display();


		}







	}
	return 1;
}
