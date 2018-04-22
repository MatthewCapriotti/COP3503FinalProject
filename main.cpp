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


int viewExercise(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu viewExercise(1, "Back");
	viewExercise.customPosition(true);


	//Set up the string to print and store it in myExercises
	int i = 0;
	/*
	sf::String myExercises;
	if (Info::exercisePtrVector.size() == 0)
	myExercises = "Error: No exercises!\n";
	for (Exercise* e : Info::exercisePtrVector)
	{
	i++;


	if (e->getCardio())
	myExercises += to_string(i) + ". " + e->getName() + " - Cardio" + "\n";
	else
	myExercises += to_string(i) + ". " + e->getName() + " - Strength: " + e->getMuscle() + "\n";
	}
	*/
	sf::String myExercises = "Pray to the comp sci Gods";
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {}
	sf::Text text(myExercises, font, 30);
	text.setPosition(600, 10);


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
		//draw, implement stuff
		window.display();
	}
	return -3;
}

int home(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu home(4, "Excercises", "Nutrition", "User Info", "Logout");

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
		window.draw(logo);
		//draw, implement stuff
		window.display();
	}
	return -3;
}
int adminHome(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu adminHome(5, "Admin Info", "Promote User", "Delete User", "Produce File", "Logout");

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
		//draw, implement stuff
		window.display();
	}
	return -3;
}

int exercise(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu exercise(5, "Add Exercise", "View Exercises", "Add Workout", "View Workout History", "Back");


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
		//draw, implement stuff
		window.display();
	}
	return -3;
}
int start(sf::RenderWindow &window, sf::Sprite &logo)
{
	Menu start(2, "Login", "Register");


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

		//draw, implement stuff
		window.display();
	}
	return -3;
}
int main()
{
	sf::Texture logoTexture;
	sf::Sprite logoSprite;

	if (!logoTexture.loadFromFile("Gainezville.png"))
		std::cout << "\nError, failed to load image\n";
	logoSprite.setTexture(logoTexture);

	int screen = 1;
	sf::RenderWindow window(sf::VideoMode(1400, 900), "GAINESVILLE");
	for (;;)
	{
		if (screen == 0)
			screen = start(window, logoSprite);
		//if (screen == -2)
		//screen = registerUser(window);
		//if (screen == -1)
		//screen = login(window)
		if (screen == 1)
			screen = home(window, logoSprite);
		if (screen == 2)
			screen = exercise(window, logoSprite);
		//if (screen == 3)
		//	screen = addExercise(window);
		if (screen == 4)
			screen = viewExercise(window, logoSprite);
		//if (screen == 5)
		//	screen = addWorkout(window);
		//if (screen == 6)
		//	screen = workoutHistory(window);
		//if (screen == 8)
		//	screen = userInfo(window);
		//if (screen == 9)
		//	screen = changeUserInfo(window);
		if (screen == 10)
			screen = adminHome(window, logoSprite);
		//if (screen == 11)
		//	screen = adminInfo(window);
		//if (screen == 12)
		//	screen = changeAdminInfo(window);
		//if (screen == 13)
		//	screen = promoteUser(window);
		//if (screen == 14)
		//	screen = deleteUser(window);
		//if (screen == 15)
		//	screen = filePage(window);
		//if (screen == 16)
		//	screen = nutrition(window);
	}
}

/*****************************
*separater
*/
/*
int home (sf::RenderWindow &window, sf::Sprite &logoSprite)
{
Menu home(5, "Excercises", "Nutrition", "User Info", "Progress", "Test");
home.customPosition(false);


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
break;
case 1:
break;
case 2:
break;
case 3:
break;
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

home.draw(window);
window.draw(logoSprite);
//draw, implement stuff
window.display();
}
return -2;
}

int test(sf::RenderWindow &window, sf::Sprite &logoSprite)
{
Menu test(1, "Back");
test.customPosition(true);

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
test.moveUp();
break;
case sf::Keyboard::Down:
test.moveDown();
break;
case sf::Keyboard::Return:
switch (test.getPressedItem()) //this says what menu item has been selected
{
case 0:
return 0;
case 1:
break;
case 2:
break;
case 3:
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

test.draw(window);
window.draw(logoSprite);
//draw, implement stuff
window.display();
}
return -3;
}

int main()
{
sf::Texture logoTexture;
sf::Sprite logoSprite;

if (!logoTexture.loadFromFile("Test.png"))
std::cout << "\nError, failed to load image\n";
logoSprite.setTexture(logoTexture);


int screen = 0;
sf::RenderWindow window(sf::VideoMode(1400, 900), "SFML TEST");
for (;;)
{
if (screen == 0)
screen = home(window, logoSprite);
if (screen == 1)
screen = test(window, logoSprite);
}
}
*/









/*

#include <iostream>
#include <SFML\Graphics.hpp>

using namespace std;

#include <SFML/Graphics.hpp>

int main()
{
// create the window
sf::RenderWindow window(sf::VideoMode(800, 600), "GainesVille");

// run the program as long as the window is open
while (window.isOpen())
{
// check all the window's events that were triggered since the last iteration of the loop
sf::Event event;
while (window.pollEvent(event))
{
// "close requested" event: we close the window
if (event.type == sf::Event::Closed)
window.close();
}

// clear the window with black color
window.clear(sf::Color::Black);

// draw everything here...
// window.draw(...);

// end the current frame
window.display();
}

return 0;
}


/****************************************************************
*	failed attempt to implement screens instead of windowds for ease of switching
*	look into creating your own screen so you can test this
*  implemnts menu.h and menu.cpp but the should ultimately be renames as screen is this is used
*	https://github.com/SFML/SFML/wiki/Tutorial:-Manage-different-Screens
*****************************************************************/



/*
class cScreen
{
public:
virtual int Run(sf::RenderWindow &App) {}
};

int main(int argc, char** argv)
{
//Applications variables
std::vector<cScreen*> Screens;
int screen = 0;

//Window creation
sf::RenderWindow App(sf::VideoMode(640, 480, 32), "SFML Demo 3");

//Mouse cursor no more visible
App.setMouseCursorVisible(false);

//Screens preparations
screen_0 s0;
Screens.push_back(&s0);
screen_1 s1;
Screens.push_back(&s1);

//Main loop
while (screen >= 0)
{
screen = Screens[screen]->Run(App);
}

return EXIT_SUCCESS;
}

*/