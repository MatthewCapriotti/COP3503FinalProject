#include "WorkoutHistory.h"
#include "Workout.h"
#include "../Exercise/Exercise.h"
#include "../Exercise/ExerciseAction.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

WorkoutHistory::WorkoutHistory() = default;

WorkoutHistory::WorkoutHistory(vector<Workout> workoutVector)
{
    this->workoutVector = workoutVector;
}

Workout WorkoutHistory::at(int index)
{
    return workoutVector[index];
}

int WorkoutHistory::size()
{
    return workoutVector.size();
}

void WorkoutHistory::add(Workout workout)
{
    workoutVector.push_back(workout);
}

vector<Workout> WorkoutHistory::getVector()
{
    return workoutVector;
}