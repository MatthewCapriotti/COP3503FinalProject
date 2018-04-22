#ifndef WIP_DO_NOT_PUSH_Info_H
#define WIP_DO_NOT_PUSH_Info_H

#include "../User.h"
#include "../Workout/WorkoutHistory.h"
#include "../Workout/Workout.h"
#include "../Exercise/Exercise.h"
#include "../Exercise/ExerciseAction.h"
#include "../healthInfo.h"

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
    static int weight;                                              // In pounds
    static int height;                                              // In inches
    static bool isAdmin;                                            // Is true if the user is an admin
    static bool isAuthenticated;                                    // Is true if the username and password match and are valid
    static bool userExists;                                         // Is true if a user with the specified username exists
    static bool newUser;                                            // Is true if the current user is a new user
    static bool adminOverride;                                      // Allows admins to access user info without a password
    static bool usernameTooFar;                                     // Is true if the user enters an invalid username 5 times
    static string goal;                                             // Contains the goal of the new user
    static member userMember;                                       // To be used if the user is not an admin
    static admin userAdmin;                                         // To be used if the user is an admin
    static Calories calorieInstance;                                // Used as instance of Calories class

    static string encrypt(string line);                             // Encrypts one line
    static string decrypt(string line);                             // Decrypts one line
    static bool checkUserExists(const string username);
    static void loadUser(const string username, string password);   // Loads the user's information
    static void saveUser();                                         // Saves the user's information
    static void saveDecryptedUser(const string username);                                // For testing: exports decrypted file of user info

};

#endif //WIP_DO_NOT_PUSH_Info_H
