#include <iostream>
#include <string>

#include <ctype.h>
#include "Info/Info.h"
#include "healthInfo.h"
using namespace std;
Calories::Calories(){
//weight = Info::weight ;
//height = Info::height;
 //int age = Info::userMember.getAge();
 weight = 0;
 age = 0;
 height =0;
}

int Calories::getAge() const
{
    return(age);
}

void Calories::setAge(const int A)
{
    this->age = A;
}

//Height
int  Calories::getHeight() const
{
    return(height);
}
void Calories::setHeight(const int H)
{
    this->height = H;
}
//Weight
int  Calories::getWeight()
{
    return(age);
}
void Calories::setWeight(int W)
{
    this->weight = W;
}
//Gender
string  Calories::getGender()
{
    return(gender);
}
void Calories::setGender( string G)
{

    this->gender = G;
}
//GainType
string Calories::getGainType()
{
    return(gender);
}
void Calories::setGainType( string G)
{

    this->gainType = G;
}
//Carbs
double Calories::getCarbs()
{
    return(carbs);
}
void Calories::setCarbs( double c)
{

    this->carbs = c;
}
// fat
double Calories::getFat()
{
    return(fat);
}
void Calories::setFat( double f)
{
this->fat =f;
}
//WomenBulk Rate
double Calories::getWomenBulkRate()
{
    return(womenBulkRate);
}
void Calories::setWomenBulkRate( double wB)
{
this->womenBulkRate = wB;
}
//Men Bulk Rate
double Calories::getMenBulkRate()
{
    return(menBulkRate);
}
void Calories::setMenBulkRate( double M)
{
this->menBulkRate = M;
}
//Women Cut Rate
double Calories::getWomenCutRate()
{
    return(womenCutRate);
}
void Calories::setWomenCutRate( double w)
{
    this->womenCutRate = w;
}
//Men Cut Rate
double Calories::getMenCutRate()
{
    return(menCutRate);
}
void Calories::setMenCutRate( double mC)
{
    this->menCutRate = mC;
}
double Calories::getProtein()
{
    return(protein);
}
void Calories::setProtein( double p){
this->protein = p;
}
//Calculate BMR
int Calories::womenBMR()
{
    return 655 + (4.35*weight)+(4.7*height)-(4.7*age);
}
int Calories:: menBMR()
{


    return 66 + (6.23*weight)+(12.7*height)-(6.8*age);
}

//Calories Needed to lose weight based on active state
void Calories:: caloriesCut(int choice, string gender){
    //1: Sedentary tending to spend much time seated; somewhat inactive.
    //2: Lightly active (light exercise one to three days a week)
    //3: Moderately active (moderate exercise three to five days per week):
    //4: Very active (vigorous exercise six to seven days a week):
    //5: Extremely active (intense exercise or sports training six to seven days per week):
    //https://www.bodybuilding.com/fun/randy46.htm
    switch(choice){
case 1:
    if(gender == "Male"){

        setMenCutRate(menBMR() * 1.2);
        setCarbs( (0.25 *(getMenCutRate()))/4);
        setFat((0.35 * (getMenCutRate()))/9);
        setProtein((0.4 * (getMenCutRate()))/4);
    }
    else if(gender == "Female")
    {
        setWomenCutRate(womenBMR() * 1.2);
        setCarbs( (0.25 *(getWomenCutRate()))/4);
        setFat( (0.35 * (getWomenCutRate()))/9);
        setProtein((0.4 * (getWomenCutRate()))/4);
    }

    break;
case 2:
    if(gender == "Male"){
      setMenCutRate(menBMR() * 0.85);
        setCarbs( (0.3 *(getMenCutRate()))/4);
        setFat( (0.3 * (getMenCutRate()))/9);
        setProtein((0.4 * (getMenCutRate()))/4);
    }
    else if(gender == "Female")
    {
        setWomenCutRate(womenBMR() * 1.0);
        setCarbs( (0.3 *(getWomenCutRate()))/4);
        setFat( (0.3 * (getWomenCutRate()))/9);
        setProtein((0.4 * (getWomenCutRate()))/4);
    }
    break;
case 3:
    if(gender == "Male"){
        setMenCutRate( menBMR() * 1.0);
        setCarbs( (0.35 *(getMenCutRate()))/4);
        setFat( (0.2 * (getMenCutRate()))/9);
        setProtein((0.45 * (getMenCutRate()))/4);
    }
    else if(gender == "Female")
    {

        setWomenCutRate(womenBMR() * 1.05);
        setCarbs( (0.35 *(getWomenCutRate()))/4);
        setFat( (0.2 * (getWomenCutRate()))/9);
        setProtein((0.45 * (getWomenCutRate()))/4);
    }
    break;
case 4:
    if(gender == "Male"){

        setMenCutRate(menBMR() * 1.15);
        setCarbs( (0.35 *(getMenCutRate()))/4);
        setFat( (0.15 * (getMenCutRate()))/9);
        setProtein((0.5 * (getMenCutRate()))/4);
    }
    else if(gender == "Female")
    {
        setWomenCutRate(womenBMR() * 1.2);
        setCarbs( (0.35 *(getWomenCutRate()))/4);
        setFat( (0.15 * (getWomenCutRate()))/9);
        setProtein((0.5 * (getWomenCutRate()))/4);
    }
    break;
case 5:

    if(gender == "Male"){
       setMenCutRate(menBMR() * 1.35);
        setCarbs( (0.2 *(getMenCutRate()))/4);
        setFat( (0.25 * (getMenCutRate()))/9);
        setProtein((0.55 * (getMenCutRate()))/4);

    }
    else if(gender == "Female")
    {
       setWomenCutRate(womenBMR() * 1.4);
        setCarbs( (0.2 *(getWomenCutRate()))/4);
        setFat( (0.25 * (getWomenCutRate()))/9);
        setProtein((0.55 * (getWomenCutRate()))/4);
    }
    break;


    }
    if(gender=="Male"){
        cout<< "Calories needed to cut is: "<< getMenCutRate()<<endl;
    }else if(gender=="Female"){
    cout<<" Calories needed to cut is : "<< getWomenCutRate()<<endl;
    }


}

//Calories needed to gain weight based on active state and gender
void Calories:: caloriesBulk(int choice, string gender){
    //Calories choice options:
    //1: Sedentary tending to spend much time seated; somewhat inactive.
    //2: Lightly active (light exercise two to three days a week)
    //3: Moderately active (moderate exercise four to six days per week):
    //Calculation for calories from the following resources:
    //http://www.healthylivingheavylifting.com/how-to-calculate-macros-for-bulking/
    //http://www.shapeyourenergy.com/how-to-calculate-your-calories-formula/

    switch(choice){
case 1:
    if(gender == "Male"){
        setMenBulkRate((menBMR() * 1.0) + 500);

        setCarbs( (0.4 *(getMenBulkRate()))/4);
        setFat( (0.2 * (getMenBulkRate()))/9);
        setProtein((0.4 * (getMenBulkRate()))/4);
    }
    else if(gender == "Female")
    {

        setWomenBulkRate((womenBMR() * 1.05) + 500);

        setCarbs( (0.4 *(getWomenBulkRate()))/4);
        setFat( (0.2 * (getWomenBulkRate()))/9);
        setProtein((0.4 * (getWomenBulkRate()))/4);
    }
    break;

case 2:
    if(gender == "Male"){

        setMenBulkRate((menBMR() * 1.1) + 500);

        setCarbs( (0.35 *(getMenBulkRate()))/4);
        setFat( (0.15 * (getMenBulkRate()))/9);
        setProtein((0.5 * (getMenBulkRate()))/4);
    }
    else if(gender == "Female")
    {
        setWomenBulkRate((womenBMR() * 1.15) + 500);

        setCarbs( (0.35 *(getWomenBulkRate()))/4);
        setFat( (0.15 * (getWomenBulkRate()))/9);
        setProtein((0.5 * (getWomenBulkRate()))/4);

    }
    break;
case 3:
    if(gender == "Male"){

        setMenBulkRate((menBMR() * 1.25) + 500);
        setCarbs( (0.25 *(getMenBulkRate()))/4);
        setFat( (0.15 * (getMenBulkRate()))/9);
        setProtein((0.6 * (getMenBulkRate()))/4);

    }
    else if(gender == "Female")
    {
        setWomenBulkRate((womenBMR() * 1.3) + 500);
        setCarbs( (0.25 *(getWomenBulkRate()))/4);
        setFat( (0.15 * (getWomenBulkRate()))/9);
        setProtein((0.6 * (getWomenBulkRate()))/4);
    }
    break;


    }
       if(gender=="Male"){
        cout<< "Calories needed to bulk is: "<< getMenBulkRate()<<endl;
    }else if(gender=="Female"){
    cout<<" Calories needed to bulk is : "<< getWomenBulkRate()<<endl;
    }


}
void Calories:: activeCutMenu(){
    cout<<"How active are you?\n"<<endl;
cout<<"1: Sedentary tending to spend much time seated; somewhat inactive.\n"
    "2: Lightly active (light exercise one to three days a week)\n"
    "3: Moderately active (moderate exercise three to five days per week):\n"
    "4: Very active (vigorous exercise six to seven days a week):\n"
    "5: Extremely active (intense exercise or sports training six to seven days per week:\n";
    cout<<"\nEnter 1-5 what you scale is: ";


}
void Calories:: activeBulkMenu(){
    cout<<"How active are you?\n"<<endl;
    cout<< "1: Sedentary tending to spend much time seated; somewhat inactive.\n"
    "2: active (light exercise two to three days a week)\n"
    "3: Moderately active (moderate exercise four to six days per week):\n";
    cout<<"\nEnter 1-3 what you scale is: ";


}
void Calories:: recommendedFoods(string gainType){
//https://www.bodybuilding.com/fun/hugo41.htm
//https://www.mensjournal.com/food-drink/how-eat-bulk
//Bulking
//1.5 grams of protein per pound of bodyweight per day
// fat intake at 0.3 grams per pound.
if(gainType == "Bulk"){
        const size_t N = 6;
string a[N] = {"Chicken,", "Turkey,", "93% Lean Red Meats,", "Tuna,","Egg Whites,", "Salmon"};

     cout<<"Reccomended Foods for a bulk: \n"<<endl;
    vector<string> bulkingFood ( a, a + N );
    for(int i=0; i<bulkingFood.size(); ++i)
    std::cout << bulkingFood[i] << '\n';
}
//Cutting
if(gainType == "Cut"){
          const size_t M = 12;
         string b[M]= {"chicken,", "pork tenderloin,", "lean cuts of beef,", "tuna,", "eggs,", "cottage cheese,", "greek yogurt,", "rice,", "potatoes,","sweet potatoes,", "pasta,", "1-2 fruits a day "};
          cout<<"Reccomended Foods for a cut: \n"<<endl;
    vector<string> cuttingFood (b, b+M);
      for(int i=0; i<cuttingFood.size(); ++i)
        std::cout << cuttingFood.at(i) << '\n';
}

}


//*** TESTING PURPOSES ONLY**//

/*
int main(){

int choice =0;
string gender;
int weight;
int age;
int height;
cout<<"Enter the you gender M/F: ";
cin>> gender;
cout<<"Enter the you Age: ";
cin>> age;
cout<<"Enter the you weight: ";
cin>> weight;
cout<<"Enter the you height: ";
cin>> height;

gender[0] = toupper(gender[0]);
Calories c;
c.setGender(gender);
if(gender=="Male" || gender =="Female"){
c.activeCutMenu();
cin>>choice;
}else{
cout<< "....Wrong";
}
//c.setAge(age);
c.setHeight(height);
c.setWeight(weight);


c.caloriesCut(choice,gender);
c.activeBulkMenu();
int choice2;
cin>>choice2;

c.caloriesBulk(choice2,gender);


return 0;
}
*/
