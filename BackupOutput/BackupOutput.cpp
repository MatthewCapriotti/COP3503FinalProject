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

    Info::userMember = member(username, password, name, age, gender, email, phoneNum, city, state, zipcode);
    Info::saveUser();
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

    if(Info::newUser)
        BackupOutput::createNewUser();

    return 0;
}