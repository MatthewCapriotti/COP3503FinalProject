#ifndef WIP_DO_NOT_PUSH_WORKOUT_H
#define WIP_DO_NOT_PUSH_WORKOUT_H

#include "Exercise.h"
#include "ExerciseAction.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class Workout
{
private:
    string workoutDate;                         // When instantiated, this is parsed from a date in a different format (i.e. "09222017" would be the parameter and would be parsed to "September 22 2017")
    int workoutTime;                            // In minutes
    vector<ExerciseAction> exActionVector;  // Vector of pointers to ExerciseAction objects

public:
    string convertDate(string dateToConvert);   // Converts date between formats as necessary (both ways)
    Workout();
    Workout(string workoutDate, int workoutTime, vector<ExerciseAction> exActionVector);
    void setDate(string workoutDate);
    void setTime(int workoutTime);
    void setVector(vector<ExerciseAction> exActionVector);
    string getDate();
    int getTime();
    vector<ExerciseAction> getVector();
};


#endif //WIP_DO_NOT_PUSH_WORKOUT_H
