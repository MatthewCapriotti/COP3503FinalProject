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



int  getAge() const;
void setAge(const int A);

//Height // Inches
int  getHeight() const;
void setHeight(const int H);
//Weight //Pounds
int  getWeight();
void setWeight(int W);
//Gender
string getGender();
void setGender( string G);

string getGainType();
void setGainType( string G);

double getCarbs();
void setCarbs( double c);

double getFat();
void setFat( double f);

double getWomenBulkRate();
void setWomenBulkRate(double w);

double getMenBulkRate();
void setMenBulkRate(double w);

double getWomenCutRate();
void setWomenCutRate (double w);

double getMenCutRate();
void setMenCutRate (double w);

double getProtein();
void setProtein( double p);
//Birthday
/*
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
void recommendedFoods(string gainType);

private:
    int age;
    string gainType; // Changed to string and mad the criteria for the user to input Cut or Bulk
    int weight;
    int height;
    int choice;
    double bulkingFood;
    double cuttingFood;
    double protein;
    double carbs;
    double fat;
    string gender;
    double womenCutRate;
    double menCutRate;
    double womenBulkRate;
    double menBulkRate;
};

#endif

/*Statistics Weight,height etc...................*/

