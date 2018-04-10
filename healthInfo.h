#ifndef healthInfo
#define healthInfo

#include <iostream>
#include <string>
using namespace std;


class Calories{
public:
//Constructor
Calories()
{

    int age=0;
    int height=0;
    int weight=0;
}
//Age


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
//Calories Loss Formula basal metabolic rate (BMR)
int womenBMR()
{
    return 655 + (4.35*weight)+(4.7*height)-(4.7*age);
}
int menBMR()
{

    return 66 + (6.23*weight)+(12.7*height)-(6.8*age);
}

//Calories Needed to lose weight based on active state
void caloriesCut(int choice, char gender){
    //1: Sedentary tending to spend much time seated; somewhat inactive.
    //2: Lightly active (light exercise one to three days a week)
    //3: Moderately active (moderate exercise three to five days per week):
    //4: Very active (vigorous exercise six to seven days a week):
    //5: Extremely active (intense exercise or sports training six to seven days per week):
    switch(choice){
case 1:
    if(gender == 'M'){
       menRate = (menBMR() * 1.2);
    }
    else if(gender == 'F')
    {
        womenRate = womenBMR() * 1.2;
    }
    break;
case 2:
    if(gender == 'M'){
        menRate = menBMR() * 1.375;
    }
    else if(gender == 'F')
    {
        womenRate = womenBMR() * 1.375;
    }
    break;
case 3:
    if(gender == 'M'){
        menRate = menBMR() * 1.55;
    }
    else if(gender == 'F')
    {
        womenRate = womenBMR() * 1.55;
    }
    break;
case 4:
    if(gender == 'M'){
        menRate = menBMR() * 1.725;
    }
    else if(gender == 'F')
    {
 womenRate = womenBMR() * 1.725;
    }
    break;
case 5:
    if(gender == 'M'){
        menRate = menBMR() * 1.9;
    }
    else if(gender == 'F')
    {
        womenRate = womenBMR() * 1.9;
    }
    break;


    }
    if(gender=='M'){
        cout<< "Calories needed to cut is: "<< menRate<<endl;
    }else if(gender=='F'){
    cout<<" Calories needed to cut is : "<< womenRate<<endl;
    }
}
void activeMenu(){
    cout<<"How active are you?\n"<<endl;
cout<<"1: Sedentary tending to spend much time seated; somewhat inactive.\n"
    "2: Lightly active (light exercise one to three days a week)\n"
    "3: Moderately active (moderate exercise three to five days per week):\n"
    "4: Very active (vigorous exercise six to seven days a week):\n"
    "5: Extremely active (intense exercise or sports training six to seven days per week:\n";
    cout<<"\nEnter 1-5 what you scale is: ";


}








private:
    int age;

    int weight;
    int height;
    int choice;



    char gender;
    int womenRate;
    int menRate;
};

#endif

/*Statistics Weight,height etc...................*/

