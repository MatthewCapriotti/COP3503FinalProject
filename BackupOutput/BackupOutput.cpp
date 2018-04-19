#include "BackupOutput.h"
#include "../User.h"
#include "../Workout/WorkoutHistory.h"
#include "../Workout/Workout.h"
#include "../Exercise/Exercise.h"
#include "../Exercise/ExerciseAction.h"
#include "../Info/Info.h"
//#include "../healthInfo.h"

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

        bool repeat = false;

        for(Exercise* e : Info::exercisePtrVector)
        {
            if(exerciseName == e->getName())
                repeat = true;
        }

        if(repeat)
        {
            cout << "Error: An exercise with that name already exists." << endl;
            continue;
        }

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

void BackupOutput::addWorkout()
{
    string input;
    bool validInput = false;
    int workoutTime;

    string date;

    while(!validInput)
    {
        bool isNotDigits = false;
        date = "";

        cout << "Enter the number of the month the workout was done (i.e. 2 for February): ";
        cin >> input;
        cout << endl;

        for(char c : input)
            if(!isdigit(c))
                isNotDigits = true;

        if(isNotDigits)
        {
            cout << "Error: Invalid input! Please enter a number for the month." << endl;
            continue;
        }
        else if(stoi(input) < 1 || stoi(input) > 12)
        {
            cout << "Error: The number you entered does not correspond to a month" << endl;
            continue;
        }

        switch(stoi(input))
        {
            case 1:
                date += "January ";
                break;
            case 2:
                date += "February ";
                break;
            case 3:
                date += "March ";
                break;
            case 4:
                date += "April ";
                break;
            case 5:
                date += "May ";
                break;
            case 6:
                date += "June ";
                break;
            case 7:
                date += "July ";
                break;
            case 8:
                date += "August ";
                break;
            case 9:
                date += "September ";
                break;
            case 10:
                date += "October ";
                break;
            case 11:
                date += "November ";
                break;
            case 12:
                date += "December ";
                break;
            default:
                date += "Error ";
        }

        isNotDigits = false;

        cout << "Enter the number of the day the workout was done (i.e. 18 for the 18th): ";
        cin >> input;
        cout << endl;

        for(char c : input)
            if(!isdigit(c))
                isNotDigits = true;

        if(isNotDigits)
        {
            cout << "Error: Invalid input! Please enter a number for the day." << endl;
            continue;
        }
        else if(stoi(input) < 1 || stoi(input) > 31)
        {
            cout << "Error: The number you entered does not correspond to a day" << endl;
            continue;
        }

        date += to_string(stoi(input)) + ", ";

        isNotDigits = false;

        cout << "Enter the year the workout was done: ";
        cin >> input;
        cout << endl;

        for(char c : input)
            if(!isdigit(c))
                isNotDigits = true;

        if(isNotDigits)
        {
            cout << "Error: Invalid input! Please enter a number for the year." << endl;
            continue;
        }
        else if(stoi(input) < 2000 || stoi(input) > 9999)
        {
            cout << "Error: The number you entered does not correspond to a reasonable year" << endl;
            continue;
        }

        date += input;
        validInput = true;
    }

    validInput = false;

    while(!validInput)
    {
        bool isNotDigits = false;

        cout << "Enter the total time of the workout (in minutes, digits only): ";
        cin >> input;
        cout << endl;

        for(char c : input)
            if(!isdigit(c))
                isNotDigits = true;

        if(isNotDigits)
        {
            cout << "Error: Total time is not made up entirely of digits." << endl;
            continue;
        }

        workoutTime = stoi(input);
        validInput = true;
    }

    validInput = false;

    int numExs = 0;

    while(!validInput)
    {
        bool isNotDigits = false;

        cout << "Enter the number of exercises done in the workout (digits only): ";
        cin >> input;
        cout << endl;

        for(char c : input)
            if(!isdigit(c))
                isNotDigits = true;

        if(isNotDigits)
        {
            cout << "Error: The number of exercises must be entirely made up of digits." << endl;
            continue;
        }

        numExs = stoi(input);
        validInput = true;
    }

    validInput = false;

    vector<ExerciseAction> exAVector;

    for(int i = 1; i < numExs+1; i++)
    {
        bool isNotDigits = false;
        string exAName = "";
        Exercise extype;

        bool foundType = false;
        bool validSets = false;
        bool validReps = false;
        bool validExTime = false;

        int numSets = 0;
        int exerciseTime = 0;
        vector<int> reps;

        cout << "Enter the name of exercise #" << to_string(i) << ": ";
        cin >> input;
        cout << endl;

        for(Exercise* e : Info::exercisePtrVector)
        {
            if(e->getName() == input)
            {
                extype = *e;
                foundType = true;
            }
        }

        exAName = extype.getName();

        if(!foundType)
        {
            cout << "Error: No saved exercise with the name \"" << input << "\" found." << endl;
            i--;
            continue;
        }

        while(!validSets && !extype.getCardio())
        {
            isNotDigits = false;
            cout << "Enter the number of sets done: ";
            cin >> input;
            cout << endl;

            for(char c : input)
                if(!isdigit(c))
                    isNotDigits = true;

            if(isNotDigits)
            {
                cout << "Error: The number of sets must be entirely made up of digits." << endl;
                continue;
            }

            numSets = stoi(input);
            validSets = true;
        }

        for(int k = 1; k < numSets+1; k++)
        {
            if(extype.getCardio())
                break;

            isNotDigits = false;
            cout << "Enter the number of reps done in set #" << to_string(k) << ": ";
            cin >> input;
            cout << endl;

            for(char c : input)
                if(!isdigit(c))
                    isNotDigits = true;

            if(isNotDigits)
            {
                cout << "Error: The number of reps must be entirely made up of digits." << endl;
                k--;
                continue;
            }
            else if(stoi(input) < 0 || stoi(input) > 99)
            {
                cout << "Error: The number of reps must be between 0 and 99." << endl;
                k--;
                continue;
            }

            reps.emplace_back(stoi(input));
        }

        while(!validExTime)
        {
            isNotDigits = false;
            cout << "Enter the total time of the exercise (in minutes, digits only): ";
            cin >> input;
            cout << endl;

            for(char c : input)
                if(!isdigit(c))
                    isNotDigits = true;

            if(isNotDigits)
            {
                cout << "Error: The exercise time must be entirely made up of digits." << endl;
                continue;
            }

            exerciseTime = stoi(input);
            validExTime= true;
        }

        exAVector.emplace_back(ExerciseAction(exAName, extype, numSets, reps, exerciseTime));
    }

    Info::userHistory.add(Workout(date,workoutTime,exAVector));
}

void BackupOutput::viewWorkoutHist()
{
    if(Info::userHistory.size() == 0)
    {
        cout << "Error: No workouts!" << endl;
        return void();
    }

    for(Workout w : Info::userHistory.getVector())
    {
        cout << w.getDate() << endl;
        cout << w.getTime() << " minutes total" << endl;

        for(ExerciseAction ea : w.getVector())
        {
            if(!ea.getType().getCardio())
            {
                cout << "Exercise: " << ea.getName() << endl;
                cout << "    Time: " << ea.getTime() << " minutes" << endl;
                cout << "    Sets: " << ea.getNumSets() << endl;
                cout << "    Reps: ";

                for(int o : ea.getReps())
                {
                    if(o < 10)
                    {
                        cout << "0" + to_string(o) + ",";
                    }
                    else
                    {
                        cout << to_string(o) + ",";
                    }
                }
                cout << endl;
            }
            else
            {
                cout << "Exercise: " << ea.getName() << endl;
                cout << "    Time: " << ea.getTime() << " minutes" << endl;
            }
        }

        cout << endl << endl;
    }
}

void BackupOutput::editInfo()
{
    string input;

    cout << endl;
    cout << "|----------------------------------|" << endl;
    cout << "|               Edit               |" << endl;
    cout << "|----------------------------------|" << endl;
    cout << "|     Please choose an option.     |" << endl;
    cout << "| 1.  Username                     |" << endl;
    cout << "| 2.  Password                     |" << endl;
    cout << "| 3.  Name                         |" << endl;
    cout << "| 4.  Age                          |" << endl;
    cout << "| 5.  Gender                       |" << endl;
    cout << "| 6.  Email                        |" << endl;
    cout << "| 7.  Phone Number                 |" << endl;
    cout << "| 8.  City                         |" << endl;
    cout << "| 9.  State / Province             |" << endl;
    cout << "| 10. Zip-code                     |" << endl;
    cout << "| 11. Weight                       |" << endl;
    cout << "| 12. Height                       |" << endl;
    cout << "|----------------------------------|" << endl << endl;
    cout << "Enter your choice (1-12): ";
    cin >> input;
    cout << endl;

    if(input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "7" && input != "8" && input != "9" && input != "10" && input != "11" && input != "12")
    {
        cout << "Error: Invalid input! Input must be an integer from 1 to 12 (inclusive)." << endl;
        return void();
    }
    else if(input == "1")
    {
        bool invalidInput = false;

        while(!invalidInput)
        {
            invalidInput = false;

            cout << "Enter the username you would like to change to (alphanumeric characters only): ";
            cin >> input;
            cout << endl;

            for(char c : input)
            {
                if(!isalnum(c))
                {
                    cout << "Error: The username must be made up of alphanumeric characters." << endl;
                    invalidInput = true;
                }
            }

            if(invalidInput)
                continue;

            if(Info::checkUserExists(input))
            {
                cout << "Error: There is already a user that has that username." << endl;
                continue;
            }
            string tempFileNameStr = "Info/saves/" + Info::userMember.getUsername() + ".txt";
            const char* tempFileName = tempFileNameStr.c_str();

            Info::userMember.setUsername(input);
            Info::saveUser();
            remove(tempFileName);
            break;
        }
    }
    else if(input == "2")
    {
        bool validInput = false;
        string passwordFirst;
        string passwordSecond;
        string password;

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
            Info::userMember.setPassword(password);
        }
    }
    else if(input == "3")
    {
        bool validInput = false;
        string name;

        while(!validInput)
        {
            name = "";
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
            Info::userMember.setName(name);
        }
    }
    else if(input == "4")
    {
        bool validInput = false;
        int age;

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
                Info::userMember.setAge(stoi(input));
            }
        }
    }
    else if(input == "5")
    {
        bool validInput = false;
        string gender;

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
            Info::userMember.setGender(gender);
        }
    }
    else if(input == "6")
    {
        bool validInput = false;
        string email;

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
            Info::userMember.setEmail(email);
        }
    }
    else if(input == "7")
    {
        bool validInput = false;

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

            Info::userMember.setPhoneNum(input);
            validInput = true;
        }
    }
    else if(input == "8")
    {
        bool validInput = false;

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

            Info::userMember.setCity(input);
            validInput = true;
        }
    }
    else if(input == "9")
    {
        bool validInput = false;

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

            Info::userMember.setZipCode(input);
            validInput = true;
        }
    }
    else if(input == "10")
    {
        bool validInput = false;

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
    }
    else if(input == "12")
    {
        bool validInput = false;

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
    }
}

void BackupOutput::displayInfo()
{
    cout << endl;
    cout << "        Username: " << Info::userMember.getUsername() << endl;
    cout << "            Name: " << Info::userMember.getName() << endl;
    cout << "             Age: " << to_string(Info::userMember.getAge()) << endl;
    cout << "          Gender: " << Info::userMember.getGender() << endl;
    cout << "           Email: " << Info::userMember.getEmail() << endl;
    cout << "    Phone Number: " << Info::userMember.getPhoneNum() << endl;
    cout << "            City: " << Info::userMember.getCity() << endl;
    cout << "State / Province: " << Info::userMember.getState() << endl;
    cout << "        Zip-code: " << Info::userMember.getZipCode() << endl;
    cout << endl;
    cout << "  Current weight: " << to_string(Info::weight) << " pounds " << endl;
    cout << "  Current height: " << to_string(Info::height) << " inches " << endl;
    cout << endl;
}

void BackupOutput::help()
{
    cout << " \"Add an exercise\" chooses to create a new exercise and add it to your saved exercises." << endl;
    cout << " \"List exercises\" displays a list of all saved exercises and their characteristics." << endl;
    cout << " \"Add a workout\" chooses to create a new workout made up of exercises from your saved list of exercises." << endl;
    cout << " \"View workout history\" displays a list of information from past workouts " << endl;
    cout << " \"View intake recommendation\" displays your recommended calorie and macro intakes." << endl;
    cout << " \"Edit user info\" displays a new menu that allows you to edit any user information." << endl;
    cout << " \"Display user info\" displays all user information.                       " << endl;
    cout << " \"Logout\" saves user information and logs the user out.                   " << endl << endl;
}

void BackupOutput::editAdminInfo()
{
    string input;

    cout << endl;
    cout << "|----------------------------------|" << endl;
    cout << "|               Edit               |" << endl;
    cout << "|----------------------------------|" << endl;
    cout << "|     Please choose an option.     |" << endl;
    cout << "| 1.  Username                     |" << endl;
    cout << "| 2.  Password                     |" << endl;
    cout << "| 3.  Name                         |" << endl;
    cout << "| 4.  Email                        |" << endl;
    cout << "| 5.  Phone number                 |" << endl;
    cout << "|----------------------------------|" << endl << endl;
    cout << "Enter your choice (1-5): ";
    cin >> input;
    cout << endl;

    if(input != "1" && input != "2" && input != "3" && input != "4" && input != "5")
    {
        cout << "Error: Invalid input! Input must be an integer from 1 to 5 (inclusive)." << endl;
        return void();
    }
    else if(input == "1")
    {
        bool invalidInput = false;

        while(!invalidInput)
        {
            invalidInput = false;

            cout << "Enter the username you would like to change to (alphanumeric characters only): ";
            cin >> input;
            cout << endl;

            for(char c : input)
            {
                if(!isalnum(c))
                {
                    cout << "Error: The username must be made up of alphanumeric characters." << endl;
                    invalidInput = true;
                }
            }

            if(invalidInput)
                continue;

            if(Info::checkUserExists(input))
            {
                cout << "Error: There is already a user that has that username." << endl;
                continue;
            }
            string tempFileNameStr = "Info/saves/" + Info::userAdmin.getUsername() + ".txt";
            const char* tempFileName = tempFileNameStr.c_str();

            Info::userAdmin.setUsername(input);
            Info::saveUser();
            remove(tempFileName);
            break;
        }
    }
    else if(input == "2")
    {
        bool validInput = false;
        string passwordFirst;
        string passwordSecond;
        string password;

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
            Info::userAdmin.setPassword(password);
        }
    }
    else if(input == "3")
    {
        bool validInput = false;
        string name;

        while(!validInput)
        {
            name = "";
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
            Info::userAdmin.setName(name);
        }
    }
    else if(input == "4")
    {
        bool validInput = false;
        string email;

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
            Info::userAdmin.setEmail(email);
        }
    }
    else if(input == "5")
    {
        bool validInput = false;

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

            Info::userAdmin.setPhoneNum(input);
            validInput = true;
        }
    }
}

void BackupOutput::deleteUser()
{
    string input;

    cout << "Enter the username of the user you want to delete: ";
    cin >> input;
    cout << endl;

    if(!Info::checkUserExists(input))
    {
        cout << "Error: There is no user with that username." << endl;
        return void();
    }
    else if(input == Info::userAdmin.getUsername())
    {
        cout << "Error: For safety reasons, you cannot delete the user currently logged in." << endl;
        return void();
    }

    string tempFileNameStr = "Info/saves/" + input + ".txt";
    const char* tempFileName = tempFileNameStr.c_str();
    remove(tempFileName);
}

void BackupOutput::produceDecryptedFile()
{
    string input;
    string usernamePlaceholder = Info::userAdmin.getUsername();
    string passwordPlaceholder = Info::userAdmin.getPassword();

    cout << "Enter the username of the user you want to decrypt a file for: ";
    cin >> input;
    cout << endl;

    if(!Info::checkUserExists(input))
    {
        cout << "Error: There is no user with that username." << endl;
        return void();
    }

    Info::adminOverride = true;
    Info::loadUser(input, "password");
    Info::saveDecryptedUser(input);
    Info::adminOverride = false;
    Info::loadUser(usernamePlaceholder, passwordPlaceholder);
}

void BackupOutput::promoteUser()
{
    string input;
    string usernamePlaceholder = Info::userAdmin.getUsername();
    string passwordPlaceholder = Info::userAdmin.getPassword();

    cout << "Enter the username of the user you want to promote: ";
    cin >> input;
    cout << endl;

    if(!Info::checkUserExists(input))
    {
        cout << "Error: There is no user with that username." << endl;
        return void();
    }

    Info::adminOverride = true;
    Info::loadUser(input, "password");
    Info::adminOverride = false;

    if(Info::isAdmin)
    {
        cout << "Error: The user is already an admin." << endl;
        return void();
    }

    Info::isAdmin = true;

    Info::userAdmin = admin(Info::userMember.getUsername(),Info::userMember.getPassword(),Info::userMember.getName(), Info::userMember.getEmail(),Info::userMember.getEmail());

    string tempFileNameStr = "Info/saves/" + Info::userMember.getUsername() + ".txt";
    const char* tempFileName = tempFileNameStr.c_str();
    remove(tempFileName);

    Info::saveUser();

    Info::loadUser(usernamePlaceholder, passwordPlaceholder);
}

void BackupOutput::logout()
{
    cout << "Logging out..." << endl;
    Info::saveUser();
    cout << "Logged out." << endl;
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
    while(input != "9" && !Info::isAdmin)
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
        cout << "| 7. Display user info             |" << endl;
        cout << "| 8. Help                          |" << endl;
        cout << "| 9. Logout                        |" << endl;
        cout << "|----------------------------------|" << endl << endl;
        cout << "Enter your choice (1-9): ";
        cin >> input;
        cout << endl;

        if(input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "7" && input != "8" && input != "9")
        {
            cout << "Error: Invalid input! Please enter an integer from 1 to 9 (inclusive)." << endl;
            continue;
        }
        else if(input == "1")
            BackupOutput::addExercise();
        else if(input == "2")
            BackupOutput::listExercises();
        else if(input == "3")
            BackupOutput::addWorkout();
        else if(input == "4")
            BackupOutput::viewWorkoutHist();
            //else if(input == "5")
            //BackupOutput::provideIntake();
        else if(input == "6")
            BackupOutput::editInfo();
        else if(input == "7")
            BackupOutput::displayInfo();
        else if(input == "8")
            BackupOutput::help();
        else if(input == "9")
            BackupOutput::logout();

    }
    // Menu for non-admins
    while(input != "5" && Info::isAdmin)
    {
        validInput = false; // Resets for each loop
        input = "";         // Resets for each loop

        // Main menu
        cout << endl;
        cout << "|----------------------------------|" << endl;
        cout << "|    Gainzville - Admin Options    |" << endl;
        cout << "|----------------------------------|" << endl;
        cout << "|     Please choose an option.     |" << endl;
        cout << "| 1. Edit admin info               |" << endl;
        cout << "| 2. Delete a user                 |" << endl;
        cout << "| 3. Produce a decrypted user file |" << endl;
        cout << "| 4. Promote a user to admin       |" << endl;
        cout << "| 5. Logout                        |" << endl;
        cout << "|----------------------------------|" << endl << endl;
        cout << "Enter your choice (1-5): ";
        cin >> input;
        cout << endl;

        if(input != "1" && input != "2" && input != "3" && input != "4" && input != "5")
        {
            cout << "Error: Invalid input! Please enter an integer from 1 to 5 (inclusive)." << endl;
            continue;
        }
        else if(input == "1")
            BackupOutput::editAdminInfo();
        else if(input == "2")
            BackupOutput::deleteUser();
        else if(input == "3")
            BackupOutput::produceDecryptedFile();
        else if(input == "4")
            BackupOutput::promoteUser();
        else if(input == "5")
            BackupOutput::logout();
    }

    return 0;
}