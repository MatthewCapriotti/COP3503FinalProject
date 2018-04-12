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

    // TO BE USED WHEN "Exercise" BECOMES AVAILABLE
    string exerciseName;
    string muscleTargeted;
    bool isCardio;

    // TO BE USED WHEN "Workout" BECOMES AVAILABLE
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
                    // isAuthenticated = true;
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

            /*
            // Begins checking workouts, line by line. ALL workout info will be placed into each item
            // in the vector, and will be parsed when the Exercise and Workout classes become available.
            if(line == "beginWorkouts")
            {
                inFS >> line; // Moves file stream forward
                // Will stop if the "endWorkouts" keyword is detected or if the last line in the file
                while(line != "endWorkouts" && !inFS.eof())
                {
                    // The following char indicators will determine what information it relates to in the file
                    //
                    // ! - follows the date of the workout
                    // ? - follows the total time of the workout
                    // $ - follows the name of the type of the particular exercise
                    // # - follows the numSets of the particular exercise
                    // % - follows the list of reps per set of the particular exercise
                    // , - separate each number of reps per set of the particular exercise
                    // & - follows the total time of the particular exercise done
                    // | - follows the end of the particular exercise
                    // ~ - indicates the end of the workout


                    size_t currIndex = 0;                       // Used for misc tracking in the line
                    size_t endOfWorkoutTimeIndex = 0;           // Index for the end of the total time of the workout
                    size_t endOfDateIndex = 0;                  // Index for the end of the date of the workout
                    size_t currExerciseStartIndex = 0;          // Index for the start of the current particular exercise
                    size_t endOfExerciseNameIndex = 0;          // Index for the end of the exercise name
                    size_t endOfNumSetsIndex = 0;               // Index for the end of the number of sets of the particular exercise
                    size_t endOfRepsListIndex = 0;              // Index for the end of the list of reps per set
                    size_t endOfExerciseTimeIndex = 0;          // Index for the end of the total time of the particular exercise
                    size_t endOfExerciseIndex = 0;              // Index for the end of the current exercise
                    size_t endOfWorkoutIndex = 0;               // Index for the end of the workout

                    // Detects the end of the workout from the beginning
                    if(line.find('~') != string::npos)
                        endOfWorkoutIndex = line.find('~');

                    // Resetting for each line
                    workoutTime = 0;
                    date = "";
                    exerciseName = "";

                    // New Declarations needed to create Workout instance and each reset per line
                    int numSets = 0;
                    vector<int> reps;
                    int exerciseTime = 0;
                    bool endOfExercise = false;
                    bool endOfWorkout = false;

                    vector<ExerciseAction> exActionVector;


                    while(!endOfWorkout)
                    {
                        endOfExercise = false;

                        // Setting the date of the workout
                        if(line.find('!',currIndex) != string::npos)
                            date = line.substr(0,line.find('!',0));

                        // Setting the total time of the workout (in minutes)
                        if(line.find('?', currIndex) != string::npos)
                            workoutTime = stoi(line.substr(currIndex,line.find('?',0)));


                        // Setting the beginning of the first exercise
                        if(line.find('?', currIndex) != string::npos)
                            currExerciseStartIndex = line.find('?', currIndex)+1;

                        cout << currExerciseStartIndex << endl;

                        // Put into a loop for organization, although it does not function as such
                        while(!endOfExercise)
                        {
                            endOfExerciseIndex = line.find('|', currExerciseStartIndex);
                            endOfExerciseNameIndex = line.find('$', currExerciseStartIndex);
                            endOfRepsListIndex = line.find('%', currExerciseStartIndex);
                            endOfNumSetsIndex = line.find('#',currExerciseStartIndex);
                            endOfExerciseTimeIndex = endOfExerciseIndex; // At the same spot

                            // The name of the exercise is between the starting point of the exercise and the '$'
                            exerciseName = line.substr(currExerciseStartIndex, line.find('$',currExerciseStartIndex)-currExerciseStartIndex);

                            // Acquiring the number of sets of the exercise done
                            numSets = stoi(line.substr(line.find("$",currExerciseStartIndex)+1,endOfNumSetsIndex-endOfExerciseNameIndex-1));

                            // Adding to reps vector
                            while(currIndex < endOfRepsListIndex)
                            {
                                if(currIndex == 0)
                                    currIndex = line.find('#',currExerciseStartIndex)+1;

                                reps.push_back(stoi(line.substr(currIndex, 2)));

                                currIndex += 3;
                            }

                            // Finds the exercise time
                            exerciseTime = stoi(line.substr(endOfRepsListIndex+1,endOfExerciseTimeIndex-endOfRepsListIndex-1));

                            currIndex = endOfExerciseIndex;

                            break;
                        }

                        Exercise exType;

                        for(Exercise *exPtr : exercisePtrVector)
                        {
                            if(exPtr->getName() == exerciseName)
                                exType = *exPtr;
                        }
                        exActionVector.push_back(ExerciseAction(exerciseName, exType, numSets, reps, exerciseTime));

                        // Determines if at the end of the line
                        if(currIndex == line.find('~',0)-1)
                            break;
                    }

                    userHistory.add(Workout(date, workoutTime, exActionVector));

                    inFS >> line;
                }
            }
            */

            // Moves stream forward
            inFS >> line;

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