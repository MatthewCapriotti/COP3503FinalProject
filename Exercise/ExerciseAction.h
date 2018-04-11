#ifndef WIP_DO_NOT_PUSH_EXERCISEACTION_H
#define WIP_DO_NOT_PUSH_EXERCISEACTION_H

#include "Exercise.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class ExerciseAction
{
private:
    string exerciseName;    // Name of the exercise (same as the name of the type, so the private variables have the same name)
    Exercise exType;        // Type of the exercise (and Exercise object)
    int numSets;            // Number of sets of the exercise done (limited to 99)
    vector<int> reps;       // Int vector of the number of reps done per set (limited to 99)
    int exerciseTime;       // Total time done for this exercise (not total time of each set) in minutes

public:
    ExerciseAction();                   // Default constructor
    ExerciseAction(string exerciseName, Exercise exType, int numSets, vector<int> reps, int exerciseTime);
    void setName(string exerciseName);
    void setType(Exercise exType);
    void setNumSets(int numSets);
    void setReps(vector<int> reps);
    void setTime(int exerciseTime);
    string getName();
    Exercise getType();
    int getNumSets();
    vector<int> getReps();
    int getTime();
};


#endif //WIP_DO_NOT_PUSH_EXERCISEACTION_H
