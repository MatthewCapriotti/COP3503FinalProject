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
    bool endOfUser = false;                       // Becomes false when at the end of a user's information

    // These declarations should not be necessary in the final program
    int weight;
    int height;
    int age;
    string goal;                            // Set as a string for organization at this early stage
    vector<string> calorieIntake;

    string userHistory;                     // Set as a string for organization at this early stage

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
        cout << inFS.good() << endl;
    }

    // Iterates through user's information if found
    if(foundUser)
    {
        while(inFS >> line && line != "endOfUser")
        {
            if(line.substr(0,7) == "weight:")
                weight = stoi(line.substr(7));
            if(line.substr(0,7) == "height:")
                height = stoi(line.substr(7));
            if(line.substr(0,5) == "goal")
                goal = line.substr(5);

            if(line == "beginIntake")
            {
                while(line != "endIntake")
                {
                    calorieIntake.push_back(line);
                    inFS >> line;
                }
            }

            inFS >> line;

            if(line == "endOfUser")
                break;
        }
    }




}

int main()
{

    loadUser("test");


    return 0;
}