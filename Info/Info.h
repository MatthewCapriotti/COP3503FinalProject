#ifndef WIP_DO_NOT_PUSH_Info_H
#define WIP_DO_NOT_PUSH_Info_H

#include "User.h"
#include "WorkoutHistory.h"
#include "Workout.h"
#include "Exercise.h"
#include "ExerciseAction.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

class Info
{
public:
    static vector<Exercise*> exercisePtrVector;                     // Vector of Exercise pointers
    static WorkoutHistory userHistory;                              // WorkoutHistory of all workouts the user has done
    static bool isAdmin;                                            // Is true if the user is an admin
    static void loadUser(const string username, string password);   // Loads the user's information

};

#endif //WIP_DO_NOT_PUSH_Info_H
