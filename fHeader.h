#include <iostream>
#include <string>
using namespace std;


class Calories{
public:
//Constructor
Calories(){int age=0; int height=0;int weight=0;}
//Age
int  getAge() const { return(age);}
void setAge(const int A) { age = A;}
//Height // Inches
int  getHeight() const { return(height);}
void setHeight(const int H) { height = H;}
//Weight //Pounds
int  getWeight() { return(age);}
void setWeight( int W) { weight = W;}
//Gender
char  getGender() { return(gender);}
void setGender( int G) { gender = G;}
//Birthday
void setBirthday(){
++age;
}
//Calories Loss Formula basal metabolic rate (BMR)
int womenBMR(){int womenRate = 655 + (4.35*weight)+(4.7*height)-(4.7*age);}
int menBMR(){int menRate = 66 + (6.23*weight)+(12.7*height)-(6.8*age);  }




private:
    int age;
int weight;
    int height;
    bool active;
    char gender;
    int womenRate;
    int menRate;
};

/*Statistics Weight,height etc...................*/

