#ifndef WIP_DO_NOT_PUSH_EXERCISE_H
#define WIP_DO_NOT_PUSH_EXERCISE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class Exercise
{
private:
    string exerciseName;        // Name of the type of exercise (i.e. "Push-up")
    string muscleTargeted;      // Name of the muscle targeted
    bool isCardio;              // 1 if a cardio exercise, 0 if a strength exercise

public:
    Exercise();
    Exercise(string exerciseName, string muscleTargeted, bool isCardio);
    void setName(string exerciseName);
    void setMuscle(string muscleTargeted);
    void setCardio(bool isCardio);
    string getName();
    string getMuscle();
    bool getCardio();
};


#endif //WIP_DO_NOT_PUSH_EXERCISE_H
