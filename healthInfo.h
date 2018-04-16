#ifndef healthInfo
#define healthInfo
#include "User.cpp"
#include "Info/Info.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Calories : member{
public:

//Age

/*
int  getAge() const
{
    return(age);
}
void setAge(const int A)
{
    age = A;
}
//Height // Inches
int  getHeight() const
{
    return(height);
}
void setHeight(const int H)
{
    height = H;
}
//Weight //Pounds
int  getWeight()
{
    return(age);
}
void setWeight(int W)
{
    weight = W;
}
//Gender
char  getGender()
{
    return(gender);
}
void setGender( int G)
{

    gender = G;
}
//Birthday
void setBirthday()
{
    ++age;
}
*/

int womenBMR();
int menBMR();
void caloriesCut(int choice, char gender);
void caloriesBulk(int choice,char gender);
void activeCutMenu();
void activeBulkMenu();
void recommendedFoods(char gainType);

private:
    int age;
    char gainType;
    int weight;
    int height;
    int choice;
    int bulkingFood;
    int cuttingFood;
    int protein;
    int carbs;
    int fat;
    char gender;
    int womenCutRate;
    int menCutRate;
    int womenBulkRate;

    int menBulkRate;
};

#endif

/*Statistics Weight,height etc...................*/

