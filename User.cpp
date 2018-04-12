#include <iostream>
#include <stdexcept>
#include <string>
#include "User.h"

member::member()
{
    name = "EMPTY";
    username = "mEMPTY";
    password = "EMPTY";
    email = "EMPTY";
    phoneNum = "EMPTY";
    city = "EMPTY";
    state = "EMPTY";
    zipcode = "EMPTY";
}

member::member(std::string username, std::string password, std::string name, 
                int age, char gender, std::string email, 
                std::string city, std::string state, std::string zipcode)
{
    this->username = "m" + username;
    this->password = password;
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->email = email;
    this->city = city;
    this->state = state;
    this->zipcode = zipcode;
}

std::string member::getUsername()
{
    return username;
}
std::string member::getPassword()
{
    return password;
}
std::string member::getName()
{
    return name;
}
int member::getAge()
{
    return age;
}
char member::getGender()
{
    
}
std::string member::getEmail()
{
    return email;
}
std::string member::getPhoneNum()
{
    return phoneNum;
}
std::string member::getCity()
{
    return city;
}
std::string member::getState()
{
    return state;
}
std::string member::getZipCode()
{
    return zipcode;
}
void member::setPassword(std::string newPassword)
{
    password = newPassword;
}
void member::setName(std::string name)
{
    this->name = name;
}
void member::setAge(int age)
{
    this->age = age;
}
void member::setGender(char gender)
{
    this->gender = gender;
}
void member::setUsername(std::string username)
{
    this->username = username;
}
void member::setEmail(std::string newEmail)
{
    this->email = newEmail;
}
void member::setPhoneNum(std::string newPhoneNum)
{
    this->phoneNum = newPhoneNum;
}
void member::setCity(std::string newCity)
{
    this->city = newCity;
}
void member::setState(std::string newState)
{
    this->state = newState;
}
void member::setZipCode(std::string newZipCode)
{
    this->zipcode = newZipCode;
}

admin::admin()
{
    name = "EMPTY";
    username = "aEMPTY";
    password = "EMPTY";
    email = "EMPTY";
    phoneNum = "EMPTY";
}

admin::admin(std::string username, std::string password, std::string name, std::string email, std::string phoneNum)
{
    this->name = name;
    this->username = username;
    this->password = password;
    this->email = email;
    this->phoneNum = phoneNum;
}

std::string admin::getUsername()
{
    return username;
}
std::string admin::getPassword()
{
    return password;
}
void admin::setPassword(std::string newPassword)
{
    this->password = newPassword;
}
// void admin::removeUser(std::string memberUsername)
// {

// }