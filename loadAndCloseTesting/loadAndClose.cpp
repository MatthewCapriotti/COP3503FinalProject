#include "User.h"
#include "Declarations.h"
#include "WorkoutHistory.h"
#include "Workout.h"
#include "Exercise.h"
#include "ExerciseAction.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

void loadUser(const string username, string password)
{
    ifstream inFS ("save.txt");             // Input stream
    string line;                            // Current line in the text document
    bool foundUser = false;                 // Becomes true if the username is found in the text document
    bool endOfUser = false;                 // Becomes false when at the end of a user's information

    // These declarations should not be necessary in the final program
    int weight;
    int height;
    int age;
    string goal;                            // Set as a string for organization at this early stage
    vector<string> calorieIntake;
    vector<string> exercisesVector;         // Set as a string vector for organization at this early stage
    map<string,bool> exercisesIsCardioMap;  // Contains the "isCardio" bool with its associated exercise (by name at this stage)
    map<string,string> exercisesMuscleMap;  // Contains the string for the muscle the associated exercise targets

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

        // Searches for this keyword that precedes the actual username
        if(line.substr(0,9) == "username:")
        {
            // If found, whatever comes after this is the username
            if(line.substr(9) == username)
            {
                foundUser = true;
                inFS >> line;
                if(line.substr(9) == password)
                {
                    // I'm assuming somewhere here there will be statements such as:
                    //
                    //User::isAuthenticated = true;
                }
                else
                    return void();
            }
        }

        // Stops searching for "username" if at the end of file
        if(inFS.eof())
            break;
    }

    // Iterates through user's information if found
    if(foundUser)
    {
        while(line != "endOfUser" && !inFS.eof())
        {
            // Checks for the user's saved weight
            if (line.substr(0, 7) == "weight:")
            {
                weight = stoi(line.substr(7));
            }
            // Checks for the user's saved height
            if (line.substr(0, 7) == "height:")
            {
                height = stoi(line.substr(7));
            }
            // Checks for the user's saved goal
            if (line.substr(0, 5) == "goal:")
            {
                goal = line.substr(5);
            }

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
            {
                break;
            }
        }
    }

    // Just for testing
    for(string str : exercisesVector)
    {
        //cout << str << " ";
        //cout << exercisesIsCardioMap[str] << " ";
        //cout << exercisesMuscleMap[str] << endl;
    }

    inFS.close(); // File is closed
}

int main()
{

    loadUser("test", "ps");


    return 0;
}