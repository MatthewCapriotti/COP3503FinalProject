#include "Workout.h"
#include "../Exercise/Exercise.h"
#include "../Exercise/ExerciseAction.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

// Converts date format. Works with input from either format and will convert to the format that was not inputted
string Workout::convertDate(string dateToConvert)
{
    if(dateToConvert.find(',') == string::npos)
    {
        string month;
        string day;
        string year;

        switch(stoi(dateToConvert.substr(0,2)))
        {
            case 1:
                month = "January";
                break;
            case 2:
                month = "February";
                break;
            case 3:
                month = "March";
                break;
            case 4:
                month = "April";
                break;
            case 5:
                month = "May";
                break;
            case 6:
                month = "June";
                break;
            case 7:
                month = "July";
                break;
            case 8:
                month = "August";
                break;
            case 9:
                month = "September";
                break;
            case 10:
                month = "October";
                break;
            case 11:
                month = "November";
                break;
            case 12:
                month = "December";
                break;
            default:
                month = "Error";
        }

        day = to_string(stoi(dateToConvert.substr(2,2)));
        year = dateToConvert.substr(4);

        return (month + " " + day + ", " + year);
    }
    else
    {
        string month;
        string day;
        string year;

        if(dateToConvert.find("January") != string::npos)
            month = "01";
        else if(dateToConvert.find("February") != string::npos)
            month = "02";
        else if(dateToConvert.find("March") != string::npos)
            month = "03";
        else if(dateToConvert.find("April") != string::npos)
            month = "04";
        else if(dateToConvert.find("May") != string::npos)
            month = "05";
        else if(dateToConvert.find("June") != string::npos)
            month = "06";
        else if(dateToConvert.find("July") != string::npos)
            month = "07";
        else if(dateToConvert.find("August") != string::npos)
            month = "08";
        else if(dateToConvert.find("September") != string::npos)
            month = "09";
        else if(dateToConvert.find("October") != string::npos)
            month = "10";
        else if(dateToConvert.find("November") != string::npos)
            month = "11";
        else if(dateToConvert.find("December") != string::npos)
            month = "12";
        else
            month = "ERROR";

        size_t firstSpaceIndex = dateToConvert.find(' ');
        size_t lastSpaceIndex = dateToConvert.rfind(' ');

        if((lastSpaceIndex-firstSpaceIndex) == 3)
            day = "0" + dateToConvert.substr(firstSpaceIndex+1,1);
        if((lastSpaceIndex-firstSpaceIndex) == 4)
            day = dateToConvert.substr(firstSpaceIndex+1,2);

        year = dateToConvert.substr(lastSpaceIndex+1);
        return (month + day + year);
    }
}

Workout::Workout() = default;

Workout::Workout(string workoutDate, int workoutTime, vector<ExerciseAction> exActionVector)
{
    // Sets it so that the date is contained in "Month Day, Year" format, NOT "MMDDYYYY" format
    if(workoutDate.find(',') != string::npos)
        this->workoutDate = workoutDate;
    else
        this->workoutDate = convertDate(workoutDate);

    this->workoutTime = workoutTime;
    this->exActionVector = exActionVector;
}

void Workout::setDate(string workoutDate)
{
    // Sets it so that the date is contained in "Month Day, Year" format, NOT "MMDDYYYY" format
    if(workoutDate.find(',') != string::npos)
        this->workoutDate = workoutDate;
    else
        this->workoutDate = convertDate(workoutDate);
}

void Workout::setTime(int workoutTime)
{
    this->workoutTime = workoutTime;
}

void Workout::setVector(vector<ExerciseAction> exActionVector)
{
    this->exActionVector = exActionVector;
}

string Workout::getDate()
{
    return workoutDate;
}

int Workout::getTime()
{
    return workoutTime;
}

vector<ExerciseAction> Workout::getVector()
{
    return exActionVector;
}

