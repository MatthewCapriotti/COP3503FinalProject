#ifndef WIP_DO_NOT_PUSH_WORKOUTHISTORY_H
#define WIP_DO_NOT_PUSH_WORKOUTHISTORY_H

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

class WorkoutHistory
{
private:
    vector<Workout> workoutVector;  // Vector of all workouts contained in history

public:
    WorkoutHistory();
    explicit WorkoutHistory(vector<Workout> workoutVector);
    Workout at(int index);
    int size();
    void add(Workout workout);
};


#endif //WIP_DO_NOT_PUSH_WORKOUTHISTORY_H
