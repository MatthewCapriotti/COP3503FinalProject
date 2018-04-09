#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void loadUser(string username)
{
    ifstream inFS ("save.txt");             // Input stream
    string line = "";                       // Current line in the text document
    bool foundUser = false;                 // Becomes true if the username is found in the text document
    bool endOfUser = false;                 // Becomes false when at the end of a user's information

    // These declarations should not be necessary in the final program
    int weight;
    int height;
    int age;
    string goal;                            // Set as a string for organization at this early stage
    vector<string> calorieIntake;
    vector<string> exercisesVector;         // Set as a string vector for organization at this early stage

    string userHistory;                     // Set as a string for organization at this early stage

    // TO BE USED WHEN "Exercise" BECOMES AVAILABLE
    string exerciseName;
    string muscleTargeted;
    bool isCardio;


    // Sets "line" to the string contained in the current line of the text document.
    // Loop terminates when at the end of the document.
    while(!foundUser)
    {
        inFS >> line;
        if(line.substr(0,9) == "username:")
        {
            if(line.substr(9) == username)
            {
                foundUser = true;
            }
        }
    }

    // Iterates through user's information if found
    if(foundUser)
    {
        while(line != "endOfUser")
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
            if(line.substr(0,11) == "beginIntake")
            {
                inFS >> line;
                while(line.substr(0,9) != "endIntake")
                {
                    calorieIntake.push_back(line);
                    inFS >> line;
                }
            }

            // Begins checking exercises, line by line. ALL exercise info will be placed into each
            // item in the vector, and will be parsed when the Exercise class becomes available.
            if(line.substr(0,14) == "beginExercises")
            {
                inFS >> line;
                while(line.substr(0,12) != "endExercises")
                {
                    cout << line << endl;
                    exercisesVector.push_back(line);
                    inFS >> line;
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




}

int main()
{

    loadUser("test");


    return 0;
}
