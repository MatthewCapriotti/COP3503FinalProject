#ifndef WIP_DO_NOT_PUSH_BACKUPOUTPUT_H
#define WIP_DO_NOT_PUSH_BACKUPOUTPUT_H

#include "BackupOutput.h"
#include "../User.h"
#include "../Workout/WorkoutHistory.h"
#include "../Workout/Workout.h"
#include "../Exercise/Exercise.h"
#include "../Exercise/ExerciseAction.h"
#include "../Info/Info.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class BackupOutput
{
public:
    static void createNewUser();                    // Method for creating a new user
    static void login();                            // Method for logging in a user

    static void addExercise();                      // Method for non-admin adding an exercise
    static void listExercises();                    // Method for non-admin listing all exercises
    static void addWorkout();                       // Method for non-admin adding a workout
    static void viewWorkoutHist();                  // Method for non-admin viewing userHistory
    static void provideIntake();                    // Method for non-admin viewing intake recommendations
    static void editInfo();                         // Method for non-admin editing user info
    static void help();                             // Method for non-admin help info
    static void logoutUser();                       // Method for non-admin logout
};


#endif //WIP_DO_NOT_PUSH_BACKUPOUTPUT_H
