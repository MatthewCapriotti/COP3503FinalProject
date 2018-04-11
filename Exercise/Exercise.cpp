#include "Exercise.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

Exercise::Exercise() = default;

Exercise::Exercise(string exerciseName, string muscleTargeted, bool isCardio)
{
    this->exerciseName = exerciseName;
    this->muscleTargeted = muscleTargeted;
    this->isCardio = isCardio;
}

void Exercise::setName(string exerciseName) {this->exerciseName = exerciseName;}
void Exercise::setMuscle(string muscleTargeted) {this->muscleTargeted = muscleTargeted;}
void Exercise::setCardio(bool isCardio) {this->isCardio = isCardio;}

string Exercise::getName(){return exerciseName;}
string Exercise::getMuscle(){return muscleTargeted;}
bool Exercise::getCardio(){return isCardio;}