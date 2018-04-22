#include "Menu.h"
#include "Exercise/Exercise.h"
#include "Exercise/ExerciseAction.h"
#include "Info/Info.h"
#include "User.h"
#include "Workout/Workout.h"
#include "workout/WorkoutHistory.h"
#include "healthInfo.h"

#include <iostream>
#include <SFML\Graphics.hpp>

void addExerciseToWorkout(sf::Sprite &logo)
{
	sf::RenderWindow addWindow(sf::VideoMode(600, 600), "Add Exercise");
	sf::String title = "View Intake Page";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(title, font, 20);
	//text.setColor(sf::Color::Green);
	text.setPosition(650, 10);
	Menu addExerciseToWorkout(1, "Ok");

	while (addWindow.isOpen()) {
		//handle events

		sf::Event event;
		while (addWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					addExerciseToWorkout.moveUp();
					break;
				case sf::Keyboard::Down:
					addExerciseToWorkout.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (addExerciseToWorkout.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						addWindow.close();
					}
					break;
					//implement more options
				}
				break;
			case sf::Event::Closed:
				addWindow.close();
				break;
			}
		}
		addWindow.clear();


		addExerciseToWorkout.draw(addWindow);
		//draw, implement stuff
		addWindow.display();
	}
	return;
}
// page number 17
int viewIntake(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu intake(1, "Back");
	intake.customPosition(true);

	sf::String title = "View Intake Page";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(title, font, 20);
	//text.setColor(sf::Color::Green);
	text.setPosition(650, 10);

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
					intake.moveUp();
					break;
				case sf::Keyboard::Down:
					intake.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (intake.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						return 16;


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


		intake.draw(window);
		window.draw(logo);
		window.draw(text);
		//draw, implement stuff
		window.display();
	}
	return -3;
}

// page number 16
int nutrition(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu nutrition(2, "Calculate", "Back");

	sf::String title = "Nutrition";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(title, font, 20);
	//text.setColor(sf::Color::Green);
	text.setPosition(650, 10);

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
					nutrition.moveUp();
					break;
				case sf::Keyboard::Down:
					nutrition.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (nutrition.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						return 17;
					case 1:
						return 1;
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

		nutrition.draw(window);
		window.draw(logo);
		window.draw(text);
		//draw, implement stuff
		window.display();
	}
	return -3;
}
// page number 5
int addWorkout(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu addWorkout(3, "Add Exercises", "Add Workout", "Back");

	sf::String title = "Add Workout History Page";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(title, font, 20);
	//text.setColor(sf::Color::Green);
	text.setPosition(650, 10);

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
					addWorkout.moveUp();
					break;
				case sf::Keyboard::Down:
					addWorkout.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (addWorkout.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						//for (int i = 0; i < numExercises; i++) {
						addExerciseToWorkout(logo);
						//}
					case 1:
						return 5;
					case 2:
						return 2;
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

		addWorkout.draw(window);
		window.draw(logo);
		window.draw(text);
		//draw, implement stuff
		window.display();
	}
	return -3;
}

// page number 6
int viewWorkoutHistory(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu viewHistory(1, "Back");
	viewHistory.customPosition(true);

	sf::String title = "View Workout History Page";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(title, font, 20);
	//text.setColor(sf::Color::Green);
	text.setPosition(650, 10);

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
					viewHistory.moveUp();
					break;
				case sf::Keyboard::Down:
					viewHistory.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (viewHistory.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						return 2;
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

		viewHistory.draw(window);
		window.draw(logo);
		window.draw(text);
		//draw, implement stuff
		window.display();
	}
	return -3;
}

// page number 8
int UserInfo(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu UserInfo(2, "Edit", "Back");
	UserInfo.customPosition(true);

	sf::String title = "User Info Page";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(title, font, 20);
	//text.setColor(sf::Color::Green);
	text.setPosition(650, 10);

	sf::String userInfo = "";
	userInfo = userInfo + "Username: " + Info::userMember.getUsername() + "\n";
	userInfo = userInfo + "Name: " + Info::userMember.getName() + "\n";
	userInfo = userInfo + "Age: " + to_string(Info::userMember.getAge()) + "\n";
	userInfo = userInfo + "Gender: " + Info::userMember.getGender() + "\n";
	userInfo = userInfo + "Email: " + Info::userMember.getEmail() + "\n";
	userInfo = userInfo + "Phone Number: " + Info::userMember.getPhoneNum() + "\n";
	userInfo = userInfo + "City: " + Info::userMember.getCity() + "\n";
	userInfo = userInfo + "State / Province: " + Info::userMember.getState() + "\n";
	userInfo = userInfo + "Zip-code: " + Info::userMember.getZipCode() + "\n";
	userInfo = userInfo + "Current weight: " + to_string(Info::weight) + " pounds " + "\n";
	userInfo = userInfo + "Current height: " + to_string(Info::height) + " inches " + "\n";
	userInfo = userInfo + "Goal: " + Info::goal + "\n";


	/*
	cout << "           Email: " << Info::userMember.getEmail() << endl;
	cout << "    Phone Number: " << Info::userMember.getPhoneNum() << endl;
	cout << "            City: " << Info::userMember.getCity() << endl;
	cout << "State / Province: " << Info::userMember.getState() << endl;
	cout << "        Zip-code: " << Info::userMember.getZipCode() << endl;
	cout << endl;
	cout << "  Current weight: " << to_string(Info::weight) << " pounds " << endl;
	cout << "  Current height: " << to_string(Info::height) << " inches " << endl;
	cout << "            Goal: " << Info::goal << endl;
	*/

	sf::Text data(userInfo, font, 35);
	//data.setColor(sf::Color::Green);
	data.setPosition(500, 50);

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
					UserInfo.moveUp();
					break;
				case sf::Keyboard::Down:
					UserInfo.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (UserInfo.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						return 9;
					case 1:
						return 1;


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

		UserInfo.draw(window);
		window.draw(logo);
		window.draw(text);
		window.draw(data);
		//draw, implement stuff
		window.display();
	}
	return -3;
}

//page number 9
int changeUserInfo(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu changeUserInfo(2, "Change", "Back");

	sf::String title = "Change User Info Page";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(title, font, 20);
	//text.setColor(sf::Color::Green);
	text.setPosition(650, 10);

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
					changeUserInfo.moveUp();
					break;
				case sf::Keyboard::Down:
					changeUserInfo.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (changeUserInfo.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						return 8;
					case 1:
						return 8;


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

		changeUserInfo.draw(window);
		window.draw(logo);
		window.draw(text);
		//draw, implement stuff
		window.display();
	}
	return -3;
}

// page number 11
int AdminInfo(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu AdminInfo(2, "Edit", "Back");

	sf::String title = "Admin Info Page";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(title, font, 20);
	//text.setColor(sf::Color::Green);
	text.setPosition(650, 10);

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
					AdminInfo.moveUp();
					break;
				case sf::Keyboard::Down:
					AdminInfo.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (AdminInfo.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						return 12;
					case 1:
						return 10;


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

		AdminInfo.draw(window);
		window.draw(logo);
		window.draw(text);
		//draw, implement stuff
		window.display();
	}
	return -3;
}

// page number 12
int changeAdminInfo(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu changeAdminInfo(2, "Change", "Back");

	sf::String title = "Change Admin Info Page";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(title, font, 20);
	//text.setColor(sf::Color::Green);
	text.setPosition(650, 10);

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
					changeAdminInfo.moveUp();
					break;
				case sf::Keyboard::Down:
					changeAdminInfo.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (changeAdminInfo.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						return 11;
					case 1:
						return 11;


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
		changeAdminInfo.draw(window);
		window.draw(logo);
		window.draw(text);
		//draw, implement stuff
		window.display();
	}
	return -3;
}

// page number 14
int deleteUser(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu deleteUser(2, "Delete", "Back");

	sf::String title = "Delete User Page";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(title, font, 20);
	//text.setColor(sf::Color::Green);
	text.setPosition(650, 10);



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
					deleteUser.moveUp();
					break;
				case sf::Keyboard::Down:
					deleteUser.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (deleteUser.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						return 14;
					case 1:
						return 10;


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
		deleteUser.draw(window);
		window.draw(logo);
		window.draw(text);
		//draw, implement stuff
		window.display();
	}
	return -3;
}

// page number 13
int promoteUser(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu promote(2, "Promote", "Back");

	sf::String title = "Promote User Page";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(title, font, 20);
	//text.setColor(sf::Color::Green);
	text.setPosition(650, 10);


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
					promote.moveUp();
					break;
				case sf::Keyboard::Down:
					promote.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (promote.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						return 13;
					case 1:
						return 10;


					}
					break;
					//implement more options
				}
				break;
			}
		}
		promote.draw(window);
		window.draw(logo);
		window.draw(text);
		//draw, implement stuff
		window.display();
	}
	return -3;
}



// page number 4
int viewExercise(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu viewExercise(1, "Back");
	sf::String title = "View Exercises";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(title, font, 20);
	//text.setColor(sf::Color::Green);
	text.setPosition(600, 10);
	viewExercise.customPosition(true);

	//Exercise myExercise = Exercise();
	//sf::String data = myExercise.get;


	int i = 0;
	sf::String myExercises;
	if (Info::exercisePtrVector.size() == 0)
		myExercises = "Error: No exercises!";
	for (Exercise* e : Info::exercisePtrVector)
	{
		i++;

		if (e->getCardio())
			myExercises += to_string(i) + ". " + e->getName() + " - Cardio" + "\n";
		else
			myExercises += to_string(i) + ". " + e->getName() + " - Strength: " + e->getMuscle() + "\n";
	}

	sf::Text data(myExercises, font, 50);
	//data.setColor(sf::Color::Green);
	data.setPosition(650, 50);



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
					viewExercise.moveUp();
					break;
				case sf::Keyboard::Down:
					viewExercise.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (viewExercise.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						return 2;
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


		viewExercise.draw(window);
		window.draw(logo);
		window.draw(text);
		window.draw(data);
		//draw, implement stuff
		window.display();
	}
	return -3;
}

// page number 10
int adminHome(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu adminHome(5, "Admin Info", "Promote User", "Delete User", "Produce File", "Logout");

	sf::String title = "Admin Home Page";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(title, font, 20);
	//text.setColor(sf::Color::Green);
	text.setPosition(650, 10);

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
					adminHome.moveUp();
					break;
				case sf::Keyboard::Down:
					adminHome.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (adminHome.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						return 11;
					case 1:
						return 13;
					case 2:
						return 14;
					case 3:
						return 15;
					case 4:
						return 0;
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

		adminHome.draw(window);
		window.draw(logo);
		window.draw(text);
		//draw, implement stuff
		window.display();
	}
	return -3;
}

// page number 2
int exercise(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu exercise(5, "Add Exercise", "View Exercises", "Add Workout", "View Workout History", "Back");

	sf::String title = "Exercises";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(title, font, 20);
	//text.setColor(sf::Color::Green);
	text.setPosition(650, 10);

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
					exercise.moveUp();
					break;
				case sf::Keyboard::Down:
					exercise.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (exercise.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						return 3;
					case 1:
						return 4;
					case 2:
						return 5;
					case 3:
						return 6;
					case 4:
						return 1;
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

		exercise.draw(window);
		window.draw(logo);
		window.draw(text);
		//draw, implement stuff
		window.display();
	}
	return -3;
}

// page number 0
int start(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu start(2, "Login", "Register");

	sf::String title = "Welcome to GainezVille";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(title, font, 20);
	//text.setColor(sf::Color::Green);
	text.setPosition(650, 10);


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
					start.moveUp();
					break;
				case sf::Keyboard::Down:
					start.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (start.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						return -1;
					case 1:
						return -2;
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


		start.draw(window);
		window.draw(logo);
		window.draw(text);

		//draw, implement stuff
		window.display();
	}
	return -3;
}// page number 3
int addExercise(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu addExercise(2, "Add Exercise", "Back");

	sf::String title = "Add Exercises";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(title, font, 20);
	//text.setColor(sf::Color::Green);
	text.setPosition(650, 10);


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
					addExercise.moveUp();
					break;
				case sf::Keyboard::Down:
					addExercise.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (addExercise.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						return 3;
					case 1:
						return 2;


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


		addExercise.draw(window);
		window.draw(logo);
		window.draw(text);
		//draw, implement stuff
		window.display();
	}
	return -3;
}
int loginMenu()//needs to be able to check if valid user still
{
	int selectedItemIndex = 0;
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


int registerNewUser()
{
	std::string fields[10] = { "Username:", "Password:", "Name:", "Age:", "Gender:", "Email:",
		"Phone:", "City:", "State:","Zipcode:" };
	std::string username;
	std::string password;
	std::string name;
	std::string age;
	std::string gender;
	std::string email;
	std::string phoneNum;
	std::string city;
	std::string state;
	std::string zipcode;

	bool fieldsFilled[10] = { false };
	bool validInput = false;
	sf::RenderWindow regWindow(sf::VideoMode(500, 400), "Register");
	//sf::Event event;
	sf::Font font; font.loadFromFile("arial.ttf");
	sf::Text field("", font, 30); field.setPosition(sf::Vector2f(5, 75));
	std::string input;
	sf::Text userIn("", font, 30); userIn.setPosition(sf::Vector2f(160, 75)); //may need to adjust positioning
	sf::Text error("", font, 30); error.setPosition(sf::Vector2f(105, 5)); //generic error message
	while (regWindow.isOpen()) {
		sf::Event event;
		int i = 0;
		while (!validInput && !fieldsFilled[i]) {//username
			bool notAlNum = false;
			Info::userExists = false;
			field.setString(fields[i]);
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
						if (notAlNum || Info::userExists) {
							error.setString("ERROR, try again.");
						}
						else {
							username = input; //change for each field
							input = "";//reset input
							validInput = true;
							fieldsFilled[i] = true;//break out of username display loop
							userIn.setString(input);
							break;
						}
					}
				}
				else if (event.type == sf::Event::Closed)
					regWindow.close();
			}
			regWindow.clear();
			regWindow.draw(field);
			regWindow.draw(userIn);
			regWindow.draw(error);
			regWindow.display();
		}
		validInput = false;
		i++;
		while (!validInput && !fieldsFilled[i]) {//password
			bool notAlNumOrSymbol = false;

			field.setString(fields[i]);
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
							if (!isalnum(c) && c != '!' && c != '?' && c != '@')
								notAlNumOrSymbol = true;
						}


						if (notAlNumOrSymbol) {
							error.setString("ERROR, try again.");
						}
						else {
							password = input; //change for each field
							input = "";//reset input
							userIn.setString(input);
							fieldsFilled[i] = true;
							validInput = true; //break out of username display loop
							break;
						}
					}
				}
				else if (event.type == sf::Event::Closed)
					regWindow.close();
			}
			regWindow.clear();
			regWindow.draw(field);
			regWindow.draw(userIn);
			regWindow.draw(error);
			regWindow.display();
		}
		validInput = false; i++;
		while (!validInput && !fieldsFilled[i]) {//irl name
			bool invalidName = false;

			field.setString(fields[i]);
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
						for (char c : input) {
							if (!isalpha(c))
								invalidName = true;
						}
						if (invalidName) {
							error.setString("ERROR, try again.");
						}
						else {
							name = input; //change for each field
							input = "";//reset input
							fieldsFilled[i] = true;
							validInput = true; //break out of username display loop
							userIn.setString(input);
							break;
						}
					}
				}
				else if (event.type == sf::Event::Closed)
					regWindow.close();
			}
			regWindow.clear();
			regWindow.draw(field);
			regWindow.draw(userIn);
			regWindow.draw(error);
			regWindow.display();
		}
		validInput = false; i++;
		while (!validInput && !fieldsFilled[i]) {//name
			bool notAlNumOrSymbol = false;

			field.setString(fields[i]);
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
							if (!isalnum(c) && c != '!' && c != '?' && c != '@')
								notAlNumOrSymbol = true;
						}
						if (notAlNumOrSymbol) {
							error.setString("ERROR, try again.");
						}
						else {
							password = input; //change for each field
							input = "";//reset input
							userIn.setString(input);
							fieldsFilled[i] = true;
							validInput = true; //break out of username display loop
							break;
						}
					}
				}
				else if (event.type == sf::Event::Closed)
					regWindow.close();
			}
			regWindow.clear();
			regWindow.draw(field);
			regWindow.draw(userIn);
			regWindow.draw(error);
			regWindow.display();
		}
		validInput = false; i++;
		while (!validInput && !fieldsFilled[i]) {//age
			bool isNotDigits = false;

			field.setString(fields[i]);
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
							if (!isdigit(c))
								isNotDigits = true;
						if (isNotDigits || std::stoi(input) < 18 || std::stoi(input) > 100) {
							error.setString("ERROR, try again.");
						}

						else {
							age = stoi(input); //change for each field
							input = "";//reset input
							fieldsFilled[i] = true;
							validInput = true; //break out of username display loop
							userIn.setString(input);
							break;
						}
					}
				}
				else if (event.type == sf::Event::Closed)
					regWindow.close();
			}
			regWindow.clear();
			regWindow.draw(field);
			regWindow.draw(userIn);
			regWindow.draw(error);
			regWindow.display();
		}
		validInput = false; i++;

		while (!validInput && !fieldsFilled[i]) {//sex
			bool invalidName = false;

			field.setString(fields[i]);
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
						for (char c : input) {
							if (!isalpha(c))
								invalidName = true;
						}
						if (invalidName) {
							error.setString("ERROR, try again.");
						}
						else {
							name = input; //change for each field
							input = "";//reset input
							fieldsFilled[i] = true;
							validInput = true; //break out of username display loop
							userIn.setString(input);
							break;
						}
					}
				}
				else if (event.type == sf::Event::Closed)
					regWindow.close();
			}
			regWindow.clear();
			regWindow.draw(field);
			regWindow.draw(userIn);
			regWindow.draw(error);
			regWindow.display();
		}
		validInput = false; i++;
		while (!validInput && !fieldsFilled[i]) {//password
			bool notAlNumOrSymbol = false;

			field.setString(fields[i]);
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
							if (!isalnum(c) && c != '!' && c != '?' && c != '@')
								notAlNumOrSymbol = true;
						}


						if (notAlNumOrSymbol) {
							error.setString("ERROR, try again.");
						}
						else {
							password = input; //change for each field
							input = "";//reset input
							userIn.setString(input);
							fieldsFilled[i] = true;
							validInput = true; //break out of username display loop
							break;
						}
					}
				}
				else if (event.type == sf::Event::Closed)
					regWindow.close();
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



//page number 1
int home(sf::RenderWindow &window, sf::Sprite &logo, sf::CircleShape &background)
{
	Menu home(4, "Excercises", "Nutrition", "User Info", "Logout");

	sf::String title = "Home Page";
	sf::Font font;
	if (!font.loadFromFile("Lobster-Regular.ttf")) {}
	sf::Text text(title, font, 24);
	//text.setColor(sf::Color::Green);
	text.setPosition(650, 10);

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
					home.moveUp();
					break;
				case sf::Keyboard::Down:
					home.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (home.getPressedItem()) //this says what menu item has been selected
					{
					case 0:
						return 2;
					case 1:
						return 16;
					case 2:
						return 8;
					case 3:
						return 0;
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

		home.draw(window);
		window.draw(background);
		window.draw(logo);
		window.draw(text);
		//draw, implement stuff
		window.display();
	}
	return -3;
}

int main()
{
	sf::Texture logoTexture;
	sf::Sprite logoSprite;

	sf::CircleShape background(5000);
	background.setFillColor(sf::Color::Green);
	//background.setPosition(1200.0f, 1200.0f);

	if (!logoTexture.loadFromFile("Gainezville.png"))
		std::cout << "\nError, failed to load image\n";
	logoSprite.setTexture(logoTexture);

	int screen = 0;
	sf::RenderWindow window(sf::VideoMode(1400, 900), "GAINESVILLE");

	while (true)
	{
		if (screen == 0)
			screen = start(window, logoSprite);
		if (screen == -2)
			screen = registerNewUser();
		if (screen == -1)
			screen = loginMenu();
		if (screen == 1)
			screen = home(window, logoSprite, background);
		if (screen == 2)
			screen = exercise(window, logoSprite);
		if (screen == 3)
			screen = addExercise(window, logoSprite);
		if (screen == 4)
			screen = viewExercise(window, logoSprite);
		if (screen == 5)
			screen = addWorkout(window, logoSprite);
		if (screen == 6)
			screen = viewWorkoutHistory(window, logoSprite);
		if (screen == 8)
			screen = UserInfo(window, logoSprite);
		if (screen == 9)
			screen = changeUserInfo(window, logoSprite);
		if (screen == 10)
			screen = adminHome(window, logoSprite);
		if (screen == 11)
			screen = AdminInfo(window, logoSprite);
		if (screen == 12)
			screen = changeAdminInfo(window, logoSprite);
		if (screen == 13)
			screen = promoteUser(window, logoSprite);
		if (screen == 14)
			screen = deleteUser(window, logoSprite);
		//if (screen == 15)
		//	screen = filePage(window, logoSprite);
		if (screen == 16)
			screen = nutrition(window, logoSprite);
		if (screen == 17)
			screen = viewIntake(window, logoSprite);
	}
}