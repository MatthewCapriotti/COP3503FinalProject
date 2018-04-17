#include "BackupOutput.h"
#include "../User.h"
#include "../Workout/WorkoutHistory.h"
#include "../Workout/Workout.h"
#include "../Exercise/Exercise.h"
#include "../Exercise/ExerciseAction.h"
#include "../Info/Info.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;



void BackupOutput::createNewUser()
{
    // Declarations and definitions needed to create a new user
    string input;
    bool validInput = false;
    string username;
    string passwordFirst;   //
    string passwordSecond;  // -- User asked to confirm password
    string password;        //
    string name;
    int age;
    string gender;
    string email;
    string phoneNum;
    string city;
    string state;
    string zipcode;

    // Requests desired username
    while(!validInput || Info::userExists)
    {
        bool notAlNum = false;
        Info::userExists = false;

        cout << "Enter desired username (alphanumeric characters only): ";
        cin >> input;
        cout << endl;

        // Checks to make sure the desired username is made up of alphanumeric characters
        for(char c : input)
        {
            if(!isalnum(c))
                notAlNum = true;
        }

        // If not, the following error will be produced
        if(notAlNum)
        {
            cout << "Error: The desired username is not entirely made up of alphanumeric characters." << endl;
            continue;
        }

        // Checks to make sure a user with the desired username does not already exist
        Info::userExists = Info::checkUserExists(input);

        // If one does, the following error will be produced
        if(Info::userExists)
        {
            cout << "Error: A user with the desired username already exists." << endl;
            continue;
        }

        username = input;
        validInput = true;
    }

    validInput = false;

    // Requests desired password
    while(!validInput)
    {
        bool notAlNumOrSymbol = false;

        cout << "Enter desired password (alphanumeric characters or the symbols: !,?,@): ";
        cin >> input;
        cout << endl;

        for(char c : input)
        {
            if(!isalnum(c) && c != '!' && c != '?' && c != '@')
                notAlNumOrSymbol = true;
        }

        if(notAlNumOrSymbol)
        {
            cout << "Error: The desired password is not entirely made up of alphanumeric characters or the specified symbols." << endl;
            continue;
        }

        // First occurrence of the password set to input
        passwordFirst = input;

        cout << "Confirm password: ";
        cin >> input;
        cout << endl;

        passwordSecond = input;

        if(passwordFirst != passwordSecond)
        {
            cout << "Error: Passwords don't match!" << endl;
            continue;
        }

        password = passwordFirst;
        validInput = true;
    }

    validInput = false;

    while(!validInput)
    {
        bool invalidName = false;
        bool hasMiddle = false;
        bool validChoice = false;

        cout << "Please enter your first name (English letters only): ";
        cin >> input;
        cout << endl;

        // Checks to make sure the name is made up of valid characters
        for(char c : input)
            if(!isalpha(c))
                invalidName = true;

        if(invalidName)
        {
            cout << "Error: The first name contains at least one invalid character." << endl;
            continue;
        }

        // Adds first name to full name
        name += input;

        while(!validChoice)
        {
            cout << "Do you have a middle name? (Y/N): ";
            cin >> input;
            cout << endl;

            if(input == "Y" || input == "y")
            {
                cout << "Please enter your middle name (English letters only): ";
                cin >> input;
                cout << endl;

                // Checks to make sure the name is made up of valid characters
                for(char c : input)
                    if(!isalpha(c))
                        invalidName = true;

                if(invalidName)
                {
                    cout << "Error: The middle name contains at least one invalid character." << endl;
                    continue;
                }
                validChoice = true;

                // Adds optional middle name to full name
                name += " " + input;
            }
            else if(input == "N" || input == "n")
                validChoice = true;
            else
            {
                cout << "Invalid input! Please enter \"Y\" or \"N\"." << endl;
            }
        }

        cout << "Please enter your last name (English letters only): ";
        cin >> input;
        cout << endl;

        // Checks to make sure the name is made up of valid characters
        for(char c : input)
            if(!isalpha(c))
                invalidName = true;

        if(invalidName)
        {
            cout << "Error: The last name contains at least one invalid character." << endl;
            continue;
        }

        // Adds last name to full name
        name += " " + input;

        validInput = true;
    }

    validInput = false;

    // Requests the user's age
    while(!validInput)
    {
        bool isNotDigits = false;

        cout << "Please enter your age (digits only, 5-100): ";
        cin >> input;
        cout << endl;

        // Ensures that the age is made up of digits
        for(char c: input)
            if(!isdigit(c))
                isNotDigits = true;

        if(isNotDigits)
        {
            cout << "Error: The age contains at least one non-digit." << endl;
            continue;
        }
        else if(stoi(input) < 5)
        {
            cout << "Error: The age is too low." << endl;
            continue;
        }
        else if(stoi(input) > 100)
        {
            cout << "Error: The age is too high." << endl;
            continue;
        }
        else
        {
            validInput = true;
            age = stoi(input);
        }
    }

    validInput = false;

    // Requests the user's gender
    while(!validInput)
    {
        cout << "Enter your gender (Male or Female): ";
        cin >> input;
        cout << endl;

        // Converts all characters to lowercase
        for(int i = 0; i < input.size(); i++)
            input[i] = tolower(input[i]);

        if(input == "male")
            gender = "Male";
        else if(input == "female")
            gender = "Female";
        else
        {
            cout << "Error: Please enter \"Male\" or \"Female\"." << endl;
            continue;
        }

        validInput = true;
    }

    validInput = false;

    // Requests the user's email
    while(!validInput)
    {
        bool validEmail = false;

        cout << "Enter your email address: ";
        cin >> input;
        cout << endl;

        for(char c : input)
            if(c == '@')
                validEmail = true;

        if(!validEmail)
        {
            cout << "Error: The email address is invalid." << endl;
            continue;
        }
        else
            email = input;

        validInput = true;
    }

    validInput = false;

    // Requests the user's phone number
    while(!validInput)
    {
        bool isNotDigits = false;

        cout << "Please enter your phone number (no hyphens): ";
        cin >> input;
        cout << endl;

        // Checks to make sure the phone number is made up of numerical digits
        for(char c : input)
            if(!isdigit(c))
                isNotDigits = true;

        if(isNotDigits)
        {
            cout << "Error: The phone number is not entirely made up of digits." << endl;
            continue;
        }

        phoneNum = input;
        validInput = true;
    }

    validInput = false;

    // Requests the user's city
    while(!validInput)
    {
        bool isNotAlpha = false;

        cout << "Enter the name of your city of residence (English letters only): ";
        cin >> input;
        cout << endl;

        // Makes sure the city name is made up of English letters
        for(char c : input)
            if(!isalpha(c))
                isNotAlpha = true;

        if(isNotAlpha)
        {
            cout << "The city name contains at least one invalid character." << endl;
            continue;
        }

        city = input;
        validInput = true;
    }

    validInput = false;

    // Requests the user's state or province
    while(!validInput)
    {
        bool isNotAlpha = false;

        cout << "Enter the name of your state or province (English letters only): ";
        cin >> input;
        cout << endl;

        // Makes sure the name is made up of English letters
        for(char c : input)
            if(!isalpha(c))
                isNotAlpha = true;

        if(isNotAlpha)
        {
            cout << "The state or province name contains at least one invalid character." << endl;
            continue;
        }

        state = input;
        validInput = true;
    }

    validInput = false;

    // Requests the user's zipcode
    while(!validInput)
    {
        bool isNotDigits = false;

        cout << "Please enter your zip-code (digits only): ";
        cin >> input;
        cout << endl;

        // Checks to make sure the zip-code is made up of numerical digits
        for(char c : input)
            if(!isdigit(c))
                isNotDigits = true;

        if(isNotDigits)
        {
            cout << "Error: The zip-code is not entirely made up of digits." << endl;
            continue;
        }

        zipcode = input;
        validInput = true;
    }

    validInput = false;

    // Requests the user's current weight in pounds
    while(!validInput)
    {
        bool isNotDigits = false;

        cout << "Please enter your weight (in pounds, 50-999, digits only): ";
        cin >> input;
        cout << endl;

        // Checks to make sure the weight is made up of numerical digits
        for(char c : input)
            if(!isdigit(c))
                isNotDigits = true;

        if(isNotDigits)
        {
            cout << "Error: The weight is not entirely made up of digits." << endl;
            continue;
        }
        else if(stoi(input) < 50)
        {
            cout << "Error: The weight is too low." << endl;
            continue;
        }
        else if(stoi(input) > 999)
        {
            cout << "Error: The weight is too high." << endl;
            continue;
        }

        Info::weight = stoi(input);
        validInput = true;
    }

    validInput = false;

    // Requests the user's current height in pounds
    while(!validInput)
    {
        bool isNotDigits = false;

        cout << "Please enter your height (in inches, 36-99, digits only): ";
        cin >> input;
        cout << endl;

        // Checks to make sure the height is made up of numerical digits
        for(char c : input)
            if(!isdigit(c))
                isNotDigits = true;

        if(isNotDigits)
        {
            cout << "Error: The height is not entirely made up of digits." << endl;
            continue;
        }
        else if(stoi(input) < 36)
        {
            cout << "Error: The height is too low." << endl;
            continue;
        }
        else if(stoi(input) > 99)
        {
            cout << "Error: The height is too high." << endl;
            continue;
        }

        Info::height = stoi(input);
        validInput = true;
    }

    Info::userMember = member(username, password, name, age, gender, email, phoneNum, city, state, zipcode);
    Info::saveUser();
}

void BackupOutput::login()
{
    bool validInput = false;
    string input;

    while(!validInput)
    {
        Info::isAuthenticated = false;
        string username = "";
        string password = "";

        cout << "Enter your username: ";
        cin >> input;
        cout << endl;

        Info::userExists = Info::checkUserExists(input);

        if(!Info::userExists)
        {
            cout << "Error: There is no user with that username." << endl;
            continue;
        }
        else
        {
            username = input;

            cout << "Enter your password: ";
            cin >> input;
            cout << endl;

            password = input;

            Info::loadUser(username, password);

            if(!Info::isAuthenticated)
            {
                cout << "Error: The password is invalid." << endl;
                continue;
            }
            else
            {
                validInput = true;
            }
        }
    }
}

void BackupOutput::addExercise()
{
    string input;
    bool invalidForm = false;
    bool validInput = false;

    string exerciseName;
    string muscleTargeted;
    bool isCardio;

    while(!validInput)
    {
        input = "";
        invalidForm = false;
        validInput = false;

        exerciseName = "";
        muscleTargeted = "";
        isCardio = false;

        cout << "Enter the exercise name (English letters only): ";
        cin >> input;
        cout << endl;

        for(char c : input)
            if(!isalpha(c))
                invalidForm = true;

        if(invalidForm)
        {
            cout << "Error: The exercise name is not entirely made up of English letters." << endl;
            continue;
        }

        exerciseName = input;

        input = "";

        cout << "Is this a strength exercise or a cardio exercise? Enter \"Strength\" or \"Cardio\": ";
        cin >> input;
        cout << endl;

        // Converts all characters to lowercase
        for(int i = 0; i < input.size(); i++)
            input[i] = tolower(input[i]);

        if(input == "strength")
            isCardio = false;
        else if(input == "cardio")
            isCardio = true;
        else
        {
            cout << "Error: Invalid input! Please enter \"Strength\" or \"Cardio\"." << endl;
            continue;
        }

        invalidForm = false;
        input = "";

        if(!isCardio)
        {
            cout << "Enter the muscle or area that the exercise targets (one word): ";
            cin >> input;
            cout << endl;

            for(char c : input)
                if(!isalpha(c))
                    invalidForm = true;

            if(invalidForm)
            {
                cout << "Error: The targeted muscle or area name is not entirely made up of English letters." << endl;
                continue;
            }

            muscleTargeted = input;
        }
        else
            muscleTargeted = "NA";

        validInput = true;
    }

    Info::exercisePtrVector.emplace_back(new Exercise(exerciseName, muscleTargeted, isCardio));
}

void BackupOutput::listExercises()
{
    int i = 0;

    if(Info::exercisePtrVector.size() == 0)
        cout << "Error: No exercises!" << endl;

    for(Exercise* e : Info::exercisePtrVector)
    {
        i++;

        if(e->getCardio())
            cout << to_string(i) << ". " << e->getName() << " - Cardio" << endl;
        else
            cout << to_string(i) << ". " << e->getName() << " - Strength: " << e->getMuscle() << endl;
    }
}

int main()
{
    // Variable declarations and definitions needed for output
    string input;
    bool validInput = false;

    // Requests user input
    cout << "Are you a new user? (Y/N): ";
    cin >> input;
    cout << endl;

    // Asking if the user is a new user:
    while(!validInput)
    {
        // If yes, then Info::newUser is set to true and this loop is broken out of.
        // If no, then Info::newUser is kept false (rewritten here for clarity) and
        // this loop is broken out of. If invalid input, this loop repeats.
        if(input == "Y" || input == "y")
        {
            Info::newUser = true;
            validInput = true;
        }
        else if(input == "N" || input == "n")
        {
            Info::newUser = false;
            validInput = true;
        }
        else
        {
            cout << "Invalid input! Please enter \"Y\" or \"N\": ";
            cin >> input;
            cout << endl;
        }
    }

    validInput = false;

    // Decides whether to create a new user or login the existing user
    if(Info::newUser)
        BackupOutput::createNewUser();
    else
        BackupOutput::login();

    input = "";

    // Menu for non-admins
    while(input != "8" && !Info::isAdmin)
    {
        validInput = false; // Resets for each loop
        input = "";         // Resets for each loop

        // Main menu
        cout << endl;
        cout << "|----------------------------------|" << endl;
        cout << "|            Gainzville            |" << endl;
        cout << "|----------------------------------|" << endl;
        cout << "|     Please choose an option.     |" << endl;
        cout << "| 1. Add an exercise               |" << endl;
        cout << "| 2. List exercises                |" << endl;
        cout << "| 3. Add a workout                 |" << endl;
        cout << "| 4. View workout history          |" << endl;
        cout << "| 5. View intake recommendations   |" << endl;
        cout << "| 6. Edit user info                |" << endl;
        cout << "| 7. Help                          |" << endl;
        cout << "| 8. Logout                        |" << endl;
        cout << "|----------------------------------|" << endl << endl;
        cout << "Enter your choice (1-8): ";
        cin >> input;
        cout << endl;

        if(input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "7" && input != "8")
        {
            cout << "Error: Invalid input! Please enter an integer from 1 to 8 (inclusive)." << endl;
            continue;
        }
        else if(input == "1")
            BackupOutput::addExercise();
        else if(input == "2")
            BackupOutput::listExercises();

    }

    return 0;
}