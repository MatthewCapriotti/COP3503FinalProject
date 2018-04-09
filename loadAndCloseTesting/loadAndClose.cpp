#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

void loadUser(const string username)
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

    string userHistory;                     // Set as a string for organization at this early stage

    // TO BE USED WHEN "Exercise" BECOMES AVAILABLE
    string exerciseName;
    string muscleTargeted;
    bool isCardio;


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
                while(line != "endExercises")
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


                    // I'm assuming somewhere here there will be statements such as:
                    //
                    // Exercise *ex = new Exercise(exerciseName, isCardio, muscleTargeted);
                    // exercisePtrVector.push_back(ex)
                    //
                    // and that these can be dereferenced outside of this method.
                    // "exercisePtrVector" needs to be declared as public somewhere else in this case.

                    inFS >> line; // File stream moved to next line
                }
            }

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
        cout << str << " ";
        cout << exercisesIsCardioMap[str] << " ";
        cout << exercisesMuscleMap[str] << endl;
    }

    inFS.close(); // File is closed
}

int main()
{

    loadUser("test");


    return 0;
}