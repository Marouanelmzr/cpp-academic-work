#include "Student.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
int Student::count=0;

Student::Student(char * nom):code(++count){
    this->name = new char[strlen(nom)+1];
    strcpy(name,nom);
    Nbr++;
    
}
void Student::display(){
    cout << code << ":" << name << endl ;
}