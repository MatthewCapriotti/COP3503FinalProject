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
int Info::weight = 0;
int Info::height = 0;
bool Info::isAdmin = false;
bool Info::isAuthenticated = false;
bool Info::userExists = false;
bool Info::newUser = false;
bool Info::adminOverride = false;
string Info::goal = "";
member Info::userMember = member();
admin Info::userAdmin = admin();

// Encrypts each line
string Info::encrypt(string line)
{

    // Defining key
    map<char,char> EKey;
    EKey.emplace('a', 'Q');
    EKey.emplace('b', 'h');
    EKey.emplace('c', 'm');
    EKey.emplace('d', 'V');
    EKey.emplace('e', '3');
    EKey.emplace('f', 'd');
    EKey.emplace('g', 'G');
    EKey.emplace('h', 'A');
    EKey.emplace('i', '1');
    EKey.emplace('j', '.');
    EKey.emplace('k', 'X');
    EKey.emplace('l', '8');
    EKey.emplace('m', 'r');
    EKey.emplace('n', 'K');
    EKey.emplace('o', 'B');
    EKey.emplace('p', 'a');
    EKey.emplace('q', '!');
    EKey.emplace('r', 'u');
    EKey.emplace('s', 'b');
    EKey.emplace('t', 'M');
    EKey.emplace('u', 'C');
    EKey.emplace('v', 'z');
    EKey.emplace('w', '2');
    EKey.emplace('x', '0');
    EKey.emplace('y', 'i');
    EKey.emplace('z', 'R');
    EKey.emplace('1', 'I');
    EKey.emplace('2', 'l');
    EKey.emplace('3', 'S');
    EKey.emplace('4', 'E');
    EKey.emplace('5', '4');
    EKey.emplace('6', ':');
    EKey.emplace('7', 'j');
    EKey.emplace('8', 'g');
    EKey.emplace('9', 'U');
    EKey.emplace('0', 'T');
    EKey.emplace(':', 'k');
    EKey.emplace(',', '7');
    EKey.emplace(' ', ' ');
    EKey.emplace('!', ',');
    EKey.emplace('?', 'e');
    EKey.emplace('@', 'N');
    EKey.emplace('.', 'D');
    EKey.emplace('A', 'f');
    EKey.emplace('B', 'c');
    EKey.emplace('C', '9');
    EKey.emplace('D', '6');
    EKey.emplace('E', 'o');
    EKey.emplace('F', 'Z');
    EKey.emplace('G', 'F');
    EKey.emplace('H', 'q');
    EKey.emplace('I', 'w');
    EKey.emplace('J', '5');
    EKey.emplace('K', 'y');
    EKey.emplace('L', 's');
    EKey.emplace('M', 'W');
    EKey.emplace('N', 'P');
    EKey.emplace('O', 'H');
    EKey.emplace('P', 'p');
    EKey.emplace('Q', 'L');
    EKey.emplace('R', '@');
    EKey.emplace('S', 'v');
    EKey.emplace('T', 'Y');
    EKey.emplace('U', 'n');
    EKey.emplace('V', 't');
    EKey.emplace('W', 'J');
    EKey.emplace('X', 'x');
    EKey.emplace('Y', 'O');
    EKey.emplace('Z', '?');

    string encryptedLine = line;

    for(int i = 0; i < line.size(); i++)
        encryptedLine[i] = EKey.at(line[i]);

    return encryptedLine;
}

// Decrypts each line
string Info::decrypt(string line)
{
    // Defining key
    map<char,char> DKey;
    DKey.emplace('Q', 'a');
    DKey.emplace('h', 'b');
    DKey.emplace('m', 'c');
    DKey.emplace('V', 'd');
    DKey.emplace('3', 'e');
    DKey.emplace('d', 'f');
    DKey.emplace('G', 'g');
    DKey.emplace('A', 'h');
    DKey.emplace('1', 'i');
    DKey.emplace('.', 'j');
    DKey.emplace('X', 'k');
    DKey.emplace('8', 'l');
    DKey.emplace('r', 'm');
    DKey.emplace('K', 'n');
    DKey.emplace('B', 'o');
    DKey.emplace('a', 'p');
    DKey.emplace('!', 'q');
    DKey.emplace('u', 'r');
    DKey.emplace('b', 's');
    DKey.emplace('M', 't');
    DKey.emplace('C', 'u');
    DKey.emplace('z', 'v');
    DKey.emplace('2', 'w');
    DKey.emplace('0', 'x');
    DKey.emplace('i', 'y');
    DKey.emplace('R', 'z');
    DKey.emplace('I', '1');
    DKey.emplace('l', '2');
    DKey.emplace('S', '3');
    DKey.emplace('E', '4');
    DKey.emplace('4', '5');
    DKey.emplace(':', '6');
    DKey.emplace('j', '7');
    DKey.emplace('g', '8');
    DKey.emplace('U', '9');
    DKey.emplace('T', '0');
    DKey.emplace('k', ':');
    DKey.emplace('7', ',');
    DKey.emplace(' ', ' ');
    DKey.emplace(',', '!');
    DKey.emplace('e', '?');
    DKey.emplace('N', '@');
    DKey.emplace('D', '.');
    DKey.emplace('f', 'A');
    DKey.emplace('c', 'B');
    DKey.emplace('9', 'C');
    DKey.emplace('6', 'D');
    DKey.emplace('o', 'E');
    DKey.emplace('Z', 'F');
    DKey.emplace('F', 'G');
    DKey.emplace('q', 'H');
    DKey.emplace('w', 'I');
    DKey.emplace('5', 'J');
    DKey.emplace('y', 'K');
    DKey.emplace('s', 'L');
    DKey.emplace('W', 'M');
    DKey.emplace('P', 'N');
    DKey.emplace('H', 'O');
    DKey.emplace('p', 'P');
    DKey.emplace('L', 'Q');
    DKey.emplace('@', 'R');
    DKey.emplace('v', 'S');
    DKey.emplace('Y', 'T');
    DKey.emplace('n', 'U');
    DKey.emplace('t', 'V');
    DKey.emplace('J', 'W');
    DKey.emplace('x', 'X');
    DKey.emplace('O', 'Y');
    DKey.emplace('?', 'Z');

    string decryptedLine = line;

    for(int i = 0; i < line.size(); i++)
        decryptedLine[i] = DKey.at(line[i]);

    return decryptedLine;
}

bool Info::checkUserExists(const string username)
{
    ifstream inFS("Info/saves/" + username + ".txt");
    string line;
    getline(inFS,line);
    line = decrypt(line);
    if(line == "username:" + username)
        return true;
    else
        return false;
}

void Info::loadUser(const string username, string password)
{
    Info::isAdmin = false;
    ifstream inFS ("Info/saves/" + username + ".txt");        // Input stream
    string line;                            // Current line in the text document
    bool foundUser = false;                 // Becomes true if the username is found in the text document
    bool endOfUser = false;                 // Becomes false when at the end of a user's information

    // These declarations should not be necessary in the final program
    string name;
    int age;
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
        getline(inFS,line); // Moves file stream forward line by line
        line = decrypt(line);

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
                getline(inFS,line);
                line = decrypt(line);
                if(line.substr(9) == password)
                    Info::isAuthenticated = true;
                else
                {
                    if(Info::adminOverride)
                    {
                        password = line.substr(9);
                        Info::isAuthenticated = true;
                    }
                    else
                        return void();
                }
            }
        }

        // Stops searching for "username" if at the end of file
        if(inFS.eof())
            break;
    }

    getline(inFS,line);   // Moves file stream forward to check if the user is an admin
    line = decrypt(line);

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
                getline(inFS,line);               // Moves file stream forward
                line = decrypt(line);

                // Iterates through every word until "endGoal" is reached
                while(line != "endName")
                {
                    n+= line;               // Adds the next part of the naem
                    n+= " ";                // Adds a space
                    getline(inFS,line);           // Moves the file stream forward
                    line = decrypt(line);
                }
                name = n;             // Sets Info::goal
            }
            // Checks for the user's email
            if(line.substr(0,6) == "email:")
                email = line.substr(6);
            // Checks for the user's phone number
            if(line.substr(0,6) == "phone:")
                phoneNum = line.substr(6);

            getline(inFS,line);   // Moves the file stream forward
            line = decrypt(line);
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
                Info::weight = stoi(line.substr(7));
            // Checks for the user's saved height
            if (line.substr(0, 7) == "height:")
                Info::height = stoi(line.substr(7));
            // Checks for the user's saved goal
            if (line.substr(0, 5) == "goal:")
            {
                string g = line.substr(5);  // Initially sets string g to the first word after "goal:"
                g += " ";                   // Adds a space after the first word
                getline(inFS,line);               // Moves file stream forward
                line = decrypt(line);

                // Iterates through every word until "endGoal" is reached
                while(line != "endGoal")
                {
                    g+= line;               // Adds the next word
                    g+= " ";                // Adds a space
                    getline(inFS,line);           // Moves the file stream forward
                    line = decrypt(line);
                }
                Info::goal = g;             // Sets Info::goal
            }
            // Checks for the user's name
            if(line.substr(0,5) == "name:")
            {
                string n = line.substr(5);  // Initially sets string g to the first word after "name:"
                n += " ";                   // Adds a space after the first part of the name
                getline(inFS,line);               // Moves file stream forward
                line = decrypt(line);

                // Iterates through every word until "endGoal" is reached
                while(line != "endName")
                {
                    n+= line;               // Adds the next part of the naem
                    n+= " ";                // Adds a space
                    getline(inFS,line);           // Moves the file stream forward
                    line = decrypt(line);
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
                getline(inFS,line);
                line = decrypt(line);
                while(line != "endIntake" && !inFS.eof())
                {
                    calorieIntake.push_back(line);
                    getline(inFS,line);
                    line = decrypt(line);
                }
            }

            // Begins checking exercises, line by line. ALL exercise info will be placed into each
            // item in the vector, and will be parsed when the Exercise class becomes available.
            if(line == "beginExercises")
            {
                getline(inFS,line); // Moves to next line to prevent "beginExercises" from being processed as an exercise
                line = decrypt(line);
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

                    getline(inFS,line); // File stream moved to next line
                    line = decrypt(line);
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

                getline(inFS,line); // Moves file stream forward
                line = decrypt(line);

                // Will stop if the "endWorkouts" keyword is detected or if the last line in the file
                while(line != "endWorkouts" && !inFS.eof())
                {
                    exActionVector.clear();                         // ExerciseAction vector cleared per workout
                    bool endOfExercises = false;                    // When a new workout is started, it is not possible for "endOfExercises" to be true
                    date = wInstance.Workout::convertDate(line);    // Date is parsed from "MMDDYYYY" format to "Month Day, Year" format
                    getline(inFS,line);                                   // File stream moved forward
                    line = decrypt(line);
                    workoutTime = stoi(line);                       // Total workout time (in minutes) is parsed from the file
                    getline(inFS,line);                                   // File stream moved forward
                    line = decrypt(line);

                    // Iterates through all exercises in one
                    while(!endOfExercises)
                    {
                        int numSets;            // Reset per exercise
                        vector<int> reps;       // Reset per exercise
                        int exerciseTime;       // Reset per exercise

                        // If this line is detected, the file stream is moved forward so the first name can be parsed
                        if(line == "beginEs")
                        {
                            getline(inFS,line);
                            line = decrypt(line);
                        }


                        exerciseName = line;    // This variable is reused from the section of this function parsing Exercise objects
                        getline(inFS,line);           // File stream moved forward
                        line = decrypt(line);
                        numSets = stoi(line);   // Number of sets parsed from line
                        getline(inFS,line);           // File stream moved forward
                        line = decrypt(line);

                        size_t currIndex = 0;   // Used to track position when parsing reps for the reps vector.

                        // Parses through the reps line and iterates as many times as there are sets
                        for(int i = 0; i < numSets; i++)
                        {
                            reps.push_back(stoi(line.substr(currIndex,2))); // 2-digit-long substring parsed starting from currIndex, converted to integer, and stored in reps vector
                            currIndex += 3;                                 // CurrIndex increased by 3 per set, as per the format in save.txt
                        }
                        getline(inFS,line);               // File stream moved forward
                        line = decrypt(line);

                        exerciseTime = stoi(line);  // Total time of exercise parsed from line
                        getline(inFS,line);               // File stream moved forward
                        line = decrypt(line);

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

                    getline(inFS,line);   // File stream moved forward
                    line = decrypt(line);
                }
            }

            getline(inFS,line);   // File stream moved forward
            line = decrypt(line);

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

void Info::saveDecryptedUser(const string username)
{
    // Basic declarations needed for printing to file
    string fileName;

    if(!Info::isAdmin)
        fileName = "Info/saves/" + userMember.getUsername() + "(decrypted).txt";
    else
        fileName = "Info/saves/" + userAdmin.getUsername() + "(decrypted).txt";


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
        line = "weight:" + to_string(Info::weight);
        outFS << line << endl;
        line = "height:" + to_string(Info::height);
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
                        line = "0" + to_string(i) + ",";
                        outFS << line;
                    }
                    else
                    {
                        line = to_string(i) + ",";
                        outFS << line;
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
        line = "username:" + Info::userMember.getUsername();
        outFS << encrypt(line) << endl;
        line = "password:" + Info::userMember.getPassword();
        outFS << encrypt(line) << endl;

        // Printing basic user info
        line = "notAdmin";
        outFS << encrypt(line) << endl;
        line = "name:" + Info::userMember.getName();
        outFS << encrypt(line) << endl;
        line = "endName";
        outFS << encrypt(line) << endl;
        line = "age:" + to_string(Info::userMember.getAge());
        outFS << encrypt(line) << endl;
        line = "gender:" + Info::userMember.getGender();
        outFS << encrypt(line) << endl;
        line = "weight:" + to_string(Info::weight);
        outFS << encrypt(line) << endl;
        line = "height:" + to_string(Info::height);
        outFS << encrypt(line) << endl;
        line = "email:" + Info::userMember.getEmail();
        outFS << encrypt(line) << endl;
        line = "phone:" + Info::userMember.getPhoneNum();
        outFS << encrypt(line) << endl;
        line = "city:" + Info::userMember.getCity();
        outFS << encrypt(line) << endl;
        line = "state:" + Info::userMember.getState();
        outFS << encrypt(line) << endl;
        line = "zipcode:" + Info::userMember.getZipCode();
        outFS << encrypt(line) << endl;
        line = "goal:" + Info::goal;
        outFS << encrypt(line) << endl;
        line = "endGoal";
        outFS << encrypt(line) << endl;

        // Printing user intake section
        line = "beginIntake";
        outFS << encrypt(line) << endl;

        /*
        * Assuming there will be code here that will print calorie info
        */

        line = "endIntake";
        outFS << encrypt(line) << endl;

        // Printing saved Exercise object information
        line = "beginExercises";
        outFS << encrypt(line) << endl;

        for(Exercise* e : Info::exercisePtrVector)
        {
            string b;
            if(!e->getCardio())
                b = "0";
            else
                b = "1";

            line = e->getName() + "!" + b + "?" + e->getMuscle();
            outFS << encrypt(line) << endl;
        }

        // Prints keyword that indicates end of Exercise objects
        line = "endExercises";
        outFS << encrypt(line) << endl;

        // Printing user's WorkoutHistory
        line = "beginWorkouts";
        outFS << encrypt(line) << endl;

        for(Workout w : Info::userHistory.getVector())
        {
            // Prints date of the workout
            line = w.Workout::convertDate(w.getDate());
            outFS << encrypt(line) << endl;

            // Prints total time of the workout
            line = to_string(w.getTime());
            outFS << encrypt(line) << endl;

            // Prints info from each ExerciseAction object
            line = "beginEs";
            outFS << encrypt(line) << endl;

            for(ExerciseAction ea : w.getVector())
            {
                // Prints ExerciseAction name (same as Exercise object name)
                line = ea.getName();
                outFS << encrypt(line) << endl;

                // Prints number of sets
                line = to_string(ea.getNumSets());
                outFS << encrypt(line) << endl;

                // Prints list (with commas) of reps per set
                for(int i : ea.getReps())
                {
                    if(i < 10)
                    {
                        line = "0" + to_string(i) + ",";
                        outFS << encrypt(line);
                    }
                    else
                    {
                        line = to_string(i) + ",";
                        outFS << encrypt(line);
                    }
                }
                outFS << endl;

                // Prints total time of exercise done
                line = to_string(ea.getTime());
                outFS << encrypt(line) << endl;
            }

            line = "endEs";
            outFS << encrypt(line) << endl;
        }

        // Prints keyword that indicates end of the user's WorkoutHistory
        line = "endWorkouts";
        outFS << encrypt(line) << endl;
        line = "endOfUser";
        outFS << encrypt(line) << endl;
        line = "endOfFile";
        outFS << encrypt(line) << endl;
    }

    else
    {
        // Prints admin's user info
        line = "username:" + userAdmin.getUsername();
        outFS << encrypt(line) << endl;
        line = "password:" + userAdmin.getPassword();
        outFS << encrypt(line) << endl;
        line = "isAdmin";
        outFS << encrypt(line) << endl;
        line = "name:" + userAdmin.getName();
        outFS << encrypt(line) << endl;
        line = "endName";
        outFS << encrypt(line) << endl;
        line = "email:" + userAdmin.getEmail();
        outFS << encrypt(line) << endl;
        line = "phone:" + userAdmin.getPhoneNum();
        outFS << encrypt(line) << endl;
        line = "endOfUser";
        outFS << encrypt(line) << endl;
        line = "endOfFile";
        outFS << encrypt(line) << endl;
    }
}

