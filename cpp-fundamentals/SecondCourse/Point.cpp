#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

// definier la methode afficher 
void Point::Afficher(){
    cout << "methode afficher :" << "(" << abs << "," << ord  << ")" << endl;
}

void Point::Initialiser(float abs, float ord){
    this->abs = abs; // this-> represente l adresse de l instance sur la quel la methode est appelle
    this->ord = ord;
}

float Point::Distance(Point B){
    float dx = abs - B.Getabs();
    float dy = ord - B.Getord();
    float result = sqrt( dx*dx + dy*dy );

    cout << "Distance = " << result << endl;

    return result;
}

void Point::Afficher(char *Text){
    cout << Text << endl;
}

Point::Point(){
    abs = 10;
    ord = 20;
    cout << "cstor par defaut" << endl;
}

Point::Point(float abs, float ord){

    this->abs = abs;
    this->ord = ord;

}