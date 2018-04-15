#include "../User.h"
#include "../Workout/WorkoutHistory.h"
#include "../Workout/Workout.h"
#include "../Exercise/Exercise.h"
#include "../Exercise/ExerciseAction.h"
#include "Info.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

vector<Exercise*> Info::exercisePtrVector;
WorkoutHistory Info::userHistory = WorkoutHistory();
bool Info::isAdmin = false;
bool Info::isAuthenticated = false;
bool Info::userExists = false;
bool Info::newUser = false;
string Info::goal = "";
member Info::userMember = member();
admin Info::userAdmin = admin();

// Encrypts each line
string Info::encrypt(string line)
{
    string encryptedLine = line;

    for(int i = 0; i < line.size(); i++)
        encryptedLine[i] = line[i] ^ '`';
    for(int i = 0; i < line.size(); i++)
        encryptedLine[i] = encryptedLine[i] ^ '(';
    for(int i = 0; i < line.size(); i++)
        encryptedLine[i] = encryptedLine[i] ^ '~';

    return encryptedLine;
}

// Decrypts each line
string Info::decrypt(string line)
{
    string decryptedLine = line;

    for(int i = 0; i < line.size(); i++)
        decryptedLine[i] = line[i] ^ '~';
    for(int i = 0; i < line.size(); i++)
        decryptedLine[i] = decryptedLine[i] ^ '(';
    for(int i = 0; i < line.size(); i++)
        decryptedLine[i] = decryptedLine[i] ^ '`';

    return decryptedLine;
}

bool Info::checkUserExists(const string username)
{
    ifstream inFS("Info/saves/" + username + ".txt");
    string line;
    inFS >> line;
    if(line == "username:" + username)
        return true;
    else
        return false;
}

void Info::loadUser(const string username, string password)
{
    ifstream inFS ("Info/saves/" + username + ".txt");        // Input stream
    string line;                            // Current line in the text document
    bool foundUser = false;                 // Becomes true if the username is found in the text document
    bool endOfUser = false;                 // Becomes false when at the end of a user's information

    // These declarations should not be necessary in the final program
    string name;
    int age;
    int weight;     // In pounds
    int height;     // In inches
    string gender;
    string email;
    string phoneNum;
    string city;
    string state;
    string zipcode;
    vector<string> calorieIntake;
    vector<string> exercisesVector;                 // Set as a string vector for organization at this early stage
    map<string,bool> exercisesIsCardioMap;          // Contains the "isCardio" bool with its associated exercise (by name at this stage)
    map<string,string> exercisesMuscleMap;          // Contains the string for the muscle the associated exercise targets
    WorkoutHistory userHistory = WorkoutHistory();  // Will contain all of the workouts performed by the user
    vector<Exercise*> exercisePtrVector;            // Will contain all of the Exercise objects saved for the user

    string exerciseName;
    string muscleTargeted;
    bool isCardio;

    int workoutTime;    // In minutes
    string date;        // Example: "02192018" = February 19, 2018


    // Sets "line" to the string contained in the current line of the text document.
    // Loop terminates when at the end of the document.
    while(!foundUser)
    {
        inFS >> line; // Moves file stream forward line by line

        Info::userExists = Info::checkUserExists(username); // Sets Info::userExists to true if a user with this username exists

        // If the user does not exist, the loadUser() function is exited
        if(!Info::userExists)
            return void();

        // Searches for this keyword that precedes the actual username
        if(line.substr(0,9) == "username:")
        {
            // If found, whatever comes after this is the username
            if(line.substr(9) == username)
            {
                foundUser = true;
                inFS >> line;
                if(line.substr(9) == password)
                    Info::isAuthenticated = true;
                else
                    return void();
            }
        }

        // Stops searching for "username" if at the end of file
        if(inFS.eof())
            break;
    }

    inFS >> line;   // Moves file stream forward to check if the user is an admin

    if(line == "isAdmin")
        Info::isAdmin = true;

    // File parsing if the user is an admin
    if(foundUser && Info::isAuthenticated && Info::isAdmin)
    {
        while(line != "endOfUser" && !inFS.eof())
        {
            // Checks for the user's name
            if(line.substr(0,5) == "name:")
            {
                string n = line.substr(5);  // Initially sets string g to the first word after "name:"
                n += " ";                   // Adds a space after the first part of the name
                inFS >> line;               // Moves file stream forward

                // Iterates through every word until "endGoal" is reached
                while(line != "endName")
                {
                    n+= line;               // Adds the next part of the naem
                    n+= " ";                // Adds a space
                    inFS >> line;           // Moves the file stream forward
                }
                name = n;             // Sets Info::goal
            }
            // Checks for the user's email
            if(line.substr(0,6) == "email:")
                email = line.substr(6);
            // Checks for the user's phone number
            if(line.substr(0,6) == "phone:")
                phoneNum = line.substr(6);

            inFS >> line;   // Moves the file stream forward
        }
    }

    // Iterates through user's information if found
    if(foundUser && Info::isAuthenticated && !Info::isAdmin)
    {
        while(line != "endOfUser" && !inFS.eof())
        {
            // Checks if the user is an admin
            if(line == "isAdmin")
                Info::isAdmin = true;
            // Checks for the user's saved weight
            if (line.substr(0, 7) == "weight:")
                weight = stoi(line.substr(7));
            // Checks for the user's saved height
            if (line.substr(0, 7) == "height:")
                height = stoi(line.substr(7));
            // Checks for the user's saved goal
            if (line.substr(0, 5) == "goal:")
            {
                string g = line.substr(5);  // Initially sets string g to the first word after "goal:"
                g += " ";                   // Adds a space after the first word
                inFS >> line;               // Moves file stream forward

                // Iterates through every word until "endGoal" is reached
                while(line != "endGoal")
                {
                    g+= line;               // Adds the next word
                    g+= " ";                // Adds a space
                    inFS >> line;           // Moves the file stream forward
                }
                Info::goal = g;             // Sets Info::goal
            }
            // Checks for the user's name
            if(line.substr(0,5) == "name:")
            {
                string n = line.substr(5);  // Initially sets string g to the first word after "name:"
                n += " ";                   // Adds a space after the first part of the name
                inFS >> line;               // Moves file stream forward

                // Iterates through every word until "endGoal" is reached
                while(line != "endName")
                {
                    n+= line;               // Adds the next part of the naem
                    n+= " ";                // Adds a space
                    inFS >> line;           // Moves the file stream forward
                }
                name = n;             // Sets Info::goal
            }
            // Checks for the user's age
            if(line.substr(0,4) == "age:")
                age = stoi(line.substr(4));
            // Checks for the user's gender
            if(line.substr(0,7) == "gender:")
                gender = line.substr(7);
            // Checks for the user's email
            if(line.substr(0,6) == "email:")
                email = line.substr(6);
            // Checks for the user's phone number
            if(line.substr(0,6) == "phone:")
                phoneNum = line.substr(6);
            // Checks for the user's city
            if(line.substr(0,5) == "city:")
                city = line.substr(5);
            // Check's for the user's state
            if(line.substr(0,6) == "state:")
                state = line.substr(6);
            // Checks for the user's zip-code
            if(line.substr(0,8) == "zipcode:")
                zipcode = line.substr(8);

            // Begins checking intake values, line by line
            if(line == "beginIntake")
            {
                inFS >> line;
                while(line != "endIntake" && !inFS.eof())
                {
                    calorieIntake.push_back(line);
                    inFS >> line;
                }
            }

            // Begins checking exercises, line by line. ALL exercise info will be placed into each
            // item in the vector, and will be parsed when the Exercise class becomes available.
            if(line == "beginExercises")
            {
                inFS >> line; // Moves to next line to prevent "beginExercises" from being processed as an exercise
                while(line != "endExercises" && !inFS.eof())
                {
                    // The scopes of the following declarations are limited to this loop for clarity
                    size_t exNameEndIndex = 0;
                    size_t exCardioIndex = 0;
                    size_t exMuscleTargetedStartIndex = 0;


                    exerciseName = "";      //
                    muscleTargeted = "";    //  -- All values are reset per exercise line in the file
                    isCardio = false;       //

                    if(line.find('!',0) != string::npos)    // Checks to make sure that the line format is valid for safety
                        exNameEndIndex = line.find('!',0);  // The end index of the name is really the character AFTER the name

                    if(line.find('?',0) != string::npos)    // Checks to make sure that the line format is valid for safety
                    {
                        exCardioIndex = line.find('?',0)-1; // The cardio bool is only one character in the line, coming one before the '?'.
                        exMuscleTargetedStartIndex = line.find('?',0)+1;    // The name of the muscle targeted is all that follows '?'.
                    }

                    // Defining both strings properly based on the indices calculated above
                    exerciseName = line.substr(0,exNameEndIndex);
                    muscleTargeted = line.substr(exMuscleTargetedStartIndex);

                    if(line.at(exCardioIndex) == '0')
                        isCardio = false;
                    else
                        isCardio = true;

                    exercisesVector.push_back(exerciseName); // This vector is only used for organization at this early stage
                    exercisesIsCardioMap[exerciseName] = isCardio;
                    exercisesMuscleMap[exerciseName] = muscleTargeted;

                    Exercise *ex = new Exercise(exerciseName, muscleTargeted, isCardio);
                    exercisePtrVector.push_back(ex);

                    inFS >> line; // File stream moved to next line
                }
            }

            // Begins checking workouts, line by line. ALL workout info will be placed into each item
            // in the vector, and will be parsed when the Exercise and Workout classes become available.
            if(line == "beginWorkouts")
            {
                // Blank workout created because many of its functions cannot be static
                Workout wInstance = Workout();

                // Vector needed to create each workout and is reset
                vector<ExerciseAction> exActionVector;

                inFS >> line; // Moves file stream forward

                // Will stop if the "endWorkouts" keyword is detected or if the last line in the file
                while(line != "endWorkouts" && !inFS.eof())
                {
                    exActionVector.clear();                         // ExerciseAction vector cleared per workout
                    bool endOfExercises = false;                    // When a new workout is started, it is not possible for "endOfExercises" to be true
                    date = wInstance.Workout::convertDate(line);    // Date is parsed from "MMDDYYYY" format to "Month Day, Year" format
                    inFS >> line;                                   // File stream moved forward
                    workoutTime = stoi(line);                       // Total workout time (in minutes) is parsed from the file
                    inFS >> line;                                   // File stream moved forward

                    // Iterates through all exercises in one
                    while(!endOfExercises)
                    {
                        int numSets;            // Reset per exercise
                        vector<int> reps;       // Reset per exercise
                        int exerciseTime;       // Reset per exercise

                        // If this line is detected, the file stream is moved forward so the first name can be parsed
                        if(line == "beginEs")
                            inFS >> line;


                        exerciseName = line;    // This variable is reused from the section of this function parsing Exercise objects
                        inFS >> line;           // File stream moved forward
                        numSets = stoi(line);   // Number of sets parsed from line
                        inFS >> line;           // File stream moved forward

                        size_t currIndex = 0;   // Used to track position when parsing reps for the reps vector.

                        // Parses through the reps line and iterates as many times as there are sets
                        for(int i = 0; i < numSets; i++)
                        {
                            reps.push_back(stoi(line.substr(currIndex,2))); // 2-digit-long substring parsed starting from currIndex, converted to integer, and stored in reps vector
                            currIndex += 3;                                 // CurrIndex increased by 3 per set, as per the format in save.txt
                        }
                        inFS >> line;               // File stream moved forward

                        exerciseTime = stoi(line);  // Total time of exercise parsed from line
                        inFS >> line;               // File stream moved forward

                        Exercise exType;            // Left undefined here, will be defined in following loop

                        // Iterates through all Exercise objects (exercise types) stored in "exercisePtrVector", which was filled in the previous section of this function
                        for(Exercise* e : exercisePtrVector)
                        {
                            // If the name of this Exercise object matches "exerciseName" as defined by parsing this workout, "exType" will be defined as that Exercise object.
                            if(e->getName() == exerciseName)
                            {
                                exType = *e;    // "exType" set to the Exercise object that "e" is pointing to
                                break;          // Loop is broken once the proper Exercise object is found
                            }
                        }

                        // With all this info, a new ExerciseAction object is created  and stored in "exActionVector".
                        exActionVector.emplace_back(ExerciseAction(exerciseName,exType,numSets,reps,exerciseTime));

                        // "endEs" indicates the end of exercises in a workout
                        if(line == "endEs")
                            endOfExercises = true;
                    }

                    // New Workout object added to "userHistory" now that all of the necessary information has been parsed
                    userHistory.add(Workout(date, workoutTime, exActionVector));

                    inFS >> line;   // File stream moved forward
                }
            }

            inFS >> line;   // File stream moved forward

            // If the line equals this statement, the loop will terminate as the user's
            // information will have fully been checked.
            if(line.substr(0,9) == "endOfUser")
                break;
        }
    }

    Info::userHistory = userHistory;      // Sets the user history
    Info::exercisePtrVector = exercisePtrVector; // Sets the Exercise pointer vector

    // Ensures that a user was both found and authenticated before creating an actor
    if(foundUser && Info::isAuthenticated)
    {
        if(!Info::isAdmin)    // If the user is not an admin, a member object will be created
            Info::userMember = member(username, password, name, age, gender, email, phoneNum, city, state, zipcode);
        else            // If the user is an admin, an admin object will be created
            Info::userAdmin = admin(username, password, name, email, phoneNum);
    }

    inFS.close(); // File is closed
}

void Info::saveUser()
{
    // Basic declarations needed for printing to file
    string fileName;

    if(!Info::isAdmin)
        fileName = "Info/saves/" + userMember.getUsername() + ".txt";
    else
        fileName = "Info/saves/" + userAdmin.getUsername() + ".txt";

    ofstream outFS(fileName);

    string line;

    // Prints following statement if the user is an admin
    if(!Info::isAdmin)
    {
        // Username and password
        line = "username:" + Info::userMember.getUsername();    //
        outFS << line << endl;                                  //  -- Output to file separated like this to prepare for later encryption method
        line = "password:" + Info::userMember.getPassword();
        outFS << line << endl;

        // Printing basic user info
        line = "notAdmin";
        outFS << line << endl;
        line = "name:" + Info::userMember.getName();
        outFS << line << endl;
        line = "endName";
        outFS << line << endl;
        line = "age:" + to_string(Info::userMember.getAge());
        outFS << line << endl;
        line = "gender:" + Info::userMember.getGender();
        outFS << line << endl;
        line = "email:" + Info::userMember.getEmail();
        outFS << line << endl;
        line = "phone:" + Info::userMember.getPhoneNum();
        outFS << line << endl;
        line = "city:" + Info::userMember.getCity();
        outFS << line << endl;
        line = "state:" + Info::userMember.getState();
        outFS << line << endl;
        line = "zipcode:" + Info::userMember.getZipCode();
        outFS << line << endl;
        line = "goal:" + Info::goal;
        outFS << line << endl;
        line = "endGoal";
        outFS << line << endl;

        // Printing user intake section
        line = "beginIntake";
        outFS << line << endl;

        /*
        * Assuming there will be code here that will print calorie info
        */

        line = "endIntake";
        outFS << line << endl;

        // Printing saved Exercise object information
        line = "beginExercises";
        outFS << line << endl;

        for(Exercise* e : Info::exercisePtrVector)
        {
            string b;
            if(e->getCardio() == false)
                b = "0";
            else
                b = "1";

            line = e->getName() + "!" + b + "?" + e->getMuscle();
            outFS << line << endl;
        }

        // Prints keyword that indicates end of Exercise objects
        line = "endExercises";
        outFS << line << endl;

        // Printing user's WorkoutHistory
        line = "beginWorkouts";
        outFS << line << endl;

        for(Workout w : Info::userHistory.getVector())
        {
            // Prints date of the workout
            line = w.Workout::convertDate(w.getDate());
            outFS << line << endl;

            // Prints total time of the workout
            line = to_string(w.getTime());
            outFS << line << endl;

            // Prints info from each ExerciseAction object
            line = "beginEs";
            outFS << line << endl;

            for(ExerciseAction ea : w.getVector())
            {
                // Prints ExerciseAction name (same as Exercise object name)
                line = ea.getName();
                outFS << line << endl;

                // Prints number of sets
                line = to_string(ea.getNumSets());
                outFS << line << endl;

                // Prints list (with commas) of reps per set
                for(int i : ea.getReps())
                {
                    if(i < 10)
                    {
                        line = "0" + to_string(i);
                        outFS << line << ",";
                    }
                    else
                    {
                        line = to_string(i);
                        outFS << line << ",";
                    }
                }
                outFS << endl;

                // Prints total time of exercise done
                line = to_string(ea.getTime());
                outFS << line << endl;
            }

            line = "endEs";
            outFS << line << endl;
        }

        // Prints keyword that indicates end of the user's WorkoutHistory
        line = "endWorkouts";
        outFS << line << endl;
        line = "endOfUser";
        outFS << line << endl;
        line = "endOfFile";
        outFS << line << endl;
    }

    else
    {
        // Prints admin's user info
        line = "username:" + userAdmin.getUsername();
        outFS << line << endl;
        line = "password:" + userAdmin.getPassword();
        outFS << line << endl;
        line = "isAdmin";
        outFS << line << endl;
        line = "name:" + userAdmin.getName();
        outFS << line << endl;
        line = "endName";
        outFS << line << endl;
        line = "email:" + userAdmin.getEmail();
        outFS << line << endl;
        line = "phone:" + userAdmin.getPhoneNum();
        outFS << line << endl;
        line = "endOfUser";
        outFS << line << endl;
        line = "endOfFile";
        outFS << line << endl;
    }
}

int main()
{
    Info::loadUser("testAdmin", "123");

    Info::saveUser();



    return 0;
}

