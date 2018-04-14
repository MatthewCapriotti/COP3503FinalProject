#ifndef WIP_DO_NOT_PUSH_Info_H
#define WIP_DO_NOT_PUSH_Info_H

#include "../User.h"
#include "../Workout/WorkoutHistory.h"
#include "../Workout/Workout.h"
#include "../Exercise/Exercise.h"
#include "../Exercise/ExerciseAction.h"

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
    static member userMember;                                        // To be used if the user is not an admin
    static admin userAdmin;                                         // To be used if the user is an admin
    static void loadUser(const string username, string password);   // Loads the user's information

};

#endif //WIP_DO_NOT_PUSH_Info_H
