#include <iostream>
#include <string>
#include "fHeader.h"
using namespace std;

int main(){

Calories c;
c.setAge(4);
cout << c.getAge();
 c.setBirthday();
 cout<<c.getAge();
return 0;
}
