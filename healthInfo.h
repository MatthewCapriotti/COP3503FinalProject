#ifndef healthInfo
#define healthInfo
#include "User.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Calories : member{
public:
//Constructor
Calories()
{

    int age=0;
    int height=0;
    int weight=0;
}
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
    //https://www.bodybuilding.com/fun/randy46.htm
    switch(choice){
case 1:
    if(gender == 'M'){
       menCutRate = (menBMR() * 1.2);
       carbs = 1.5*weight;
       fat = 0.2 * weight;
       protein = 0.6 * weight;
    }
    else if(gender == 'F')
    {
        womenCutRate = womenBMR() * 1.2;
        carbs = 1.5*weight;
       fat = 0.2 * weight;
       protein = 0.6 * weight;
    }

    break;
case 2:
    if(gender == 'M'){
        menCutRate = menBMR() * 1.375;
        carbs = 1.8*weight;
        fat = 0.3 * weight;
        protein = 0.9 * weight;
    }
    else if(gender == 'F')
    {
        womenCutRate = womenBMR() * 1.375;
           carbs = 1.8*weight;
        fat = 0.3 * weight;
        protein = 0.9 * weight;
    }
    break;
case 3:
    if(gender == 'M'){
        menCutRate = menBMR() * 1.55;
          carbs = 1.9*weight;
       fat = 0.3* weight;
       protein = 0.9 * weight;
    }
    else if(gender == 'F')
    {
        womenCutRate = womenBMR() * 1.55;
        carbs = 1.9*weight;
       fat = 0.3* weight;
       protein = 0.9 * weight;
    }
    break;
case 4:
    if(gender == 'M'){
        menCutRate = menBMR() * 1.725;
          carbs = 2.5*weight;
       fat = 0.3 * weight;
       protein = 1 * weight;
    }
    else if(gender == 'F')
    {
 womenCutRate = womenBMR() * 1.725;
   carbs = 2.5*weight;
       fat = 0.3 * weight;
       protein = 1 * weight;
    }
    break;
case 5:
    if(gender == 'M'){
        menCutRate = menBMR() * 1.9;
          carbs = 3.5*weight;
       fat = 0.3 * weight;
       protein =1 * weight;
    }
    else if(gender == 'F')
    {
        womenCutRate = womenBMR() * 1.9;
         carbs = 3.5*weight;
       fat = 0.3 * weight;
       protein =1 * weight;
    }
    break;


    }
    if(gender=='M'){
        cout<< "Calories needed to cut is: "<< menCutRate<<endl;
    }else if(gender=='F'){
    cout<<" Calories needed to cut is : "<< womenCutRate<<endl;
    }
}
//Calorie Bulk
void calorieBulk(int choice, char gender){
    //1: Sedentary tending to spend much time seated; somewhat inactive.
    //2: active (light exercise two to three days a week)
    //3: Moderately active (moderate exercise four to six days per week):
    //http://www.healthylivingheavylifting.com/how-to-calculate-macros-for-bulking/
    //http://www.shapeyourenergy.com/how-to-calculate-your-calories-formula/
    switch(choice){
case 1:
    if(gender == 'M'){
       menBulkRate = (weight * 18);
    }
    else if(gender == 'F')
    {
        womenBulkRate = weight * 16;
    }
    break;
case 2:
    if(gender == 'M'){
        menBulkRate = weight*20;
    }
    else if(gender == 'F')
    {
        womenBulkRate = weight * 17;

    }
    break;
case 3:
    if(gender == 'M'){
        menBulkRate = weight * 22;
    }
    else if(gender == 'F')
    {
        womenBulkRate = weight * 18;
    }
    break;


    }
   if(gender=='M'){
        cout<< "Calories needed to Bulk is: "<< menBulkRate+500<<endl;
    }else if(gender=='F'){
    cout<<" Calories needed to Bulk is : "<< womenBulkRate+500<<endl;
    }
}
void activeCutMenu(){
    cout<<"How active are you?\n"<<endl;
cout<<"1: Sedentary tending to spend much time seated; somewhat inactive.\n"
    "2: Lightly active (light exercise one to three days a week)\n"
    "3: Moderately active (moderate exercise three to five days per week):\n"
    "4: Very active (vigorous exercise six to seven days a week):\n"
    "5: Extremely active (intense exercise or sports training six to seven days per week:\n";
    cout<<"\nEnter 1-5 what you scale is: ";


}
void activeBulkMenu(){
    cout<<"How active are you?\n"<<endl;
    cout<< "1: Sedentary tending to spend much time seated; somewhat inactive.\n"
    "2: active (light exercise two to three days a week)\n"
    "3: Moderately active (moderate exercise four to six days per week):\n";
    cout<<"\nEnter 1-3 what you scale is: ";


}
void recommendedFoods(char gainType){
//https://www.bodybuilding.com/fun/hugo41.htm
//https://www.mensjournal.com/food-drink/how-eat-bulk
//Bulking
//1.5 grams of protein per pound of bodyweight per day
// fat intake at 0.3 grams per pound.
if(gainType == 'B'){
        const size_t N = 6;
string a[N] = {"Chicken,", "Turkey,", "93% Lean Red Meats,", "Tuna,","Egg Whites,", "Salmon"};

     cout<<"Reccomended Foods for a bulk: \n"<<endl;
    vector<string> bulkingFood ( a, a + N );
    for(int i=0; i<bulkingFood.size(); ++i)
    std::cout << bulkingFood[i] << '\n';
}
//Cutting
if(gainType == 'C'){
          const size_t M = 12;
         string b[M]= {"chicken,", "pork tenderloin,", "lean cuts of beef,", "tuna,", "eggs,", "cottage cheese,", "greek yogurt,", "rice,", "potatoes,","sweet potatoes,", "pasta,", "1-2 fruits a day "};
          cout<<"Reccomended Foods for a cut: \n"<<endl;
    vector<string> cuttingFood (b, b+M);
      for(int i=0; i<cuttingFood.size(); ++i)
        std::cout << cuttingFood[i] << '\n';
}

}




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

