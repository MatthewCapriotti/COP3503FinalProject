#include "ExerciseAction.h"
#include "Exercise.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

ExerciseAction::ExerciseAction() = default;

ExerciseAction::ExerciseAction(string exerciseName, Exercise exType, int numSets, vector<int> reps, int exerciseTime)
{
    this->exerciseName =exerciseName;
    this->exType = exType;
    this->numSets = numSets;
    this->reps = reps;
    this->exerciseTime = exerciseTime;
}

void ExerciseAction::setName(string exerciseName)
{
    this->exerciseName = exerciseName;
}

void ExerciseAction::setType(Exercise exType)
{
    this->exType = exType;
}

void ExerciseAction::setNumSets(int numSets)
{
    this->numSets = numSets;
}

void ExerciseAction::setReps(vector<int> reps)
{
    this->reps = reps;
}

void ExerciseAction::setTime(int exerciseTime)
{
    this->exerciseTime = exerciseTime;
}

string ExerciseAction::getName()
{
    return exerciseName;
}

Exercise ExerciseAction::getType()
{
    return exType;
}

int ExerciseAction::getNumSets()
{
    return numSets;
}

vector<int> ExerciseAction::getReps()
{
    return reps;
}

int ExerciseAction::getTime()
{
    return exerciseTime;
}