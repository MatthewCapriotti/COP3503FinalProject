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
};


#endif //WIP_DO_NOT_PUSH_BACKUPOUTPUT_H
