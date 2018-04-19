#ifndef healthInfo
#define healthInfo
#include "User.h"
#include "Info/Info.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Calories : member{
public:
    Calories();


/*
int  getAge() const
{
    return(Info::age);
}
void setAge(const int A)
{
    age = A;
}
/*
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
    void caloriesCut(int choice, string gender);
    void caloriesBulk(int choice,string gender);
    void activeCutMenu();
    void activeBulkMenu();
    void recommendedFoods(char gainType);

private:
    int age;
    char gainType;
    int weight;
    int height;
    int choice;
    double bulkingFood;
    double cuttingFood;
    double protein;
    double carbs;
    double fat;
    char gender;
    double womenCutRate;
    double menCutRate;
    double womenBulkRate;

    int menBulkRate;
};

#endif

/*Statistics Weight,height etc...................*/

