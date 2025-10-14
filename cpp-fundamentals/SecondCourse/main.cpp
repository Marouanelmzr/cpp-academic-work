#include <iostream>
#include "Point.h"
using namespace std;

void Afficher(Point A){
    cout << "fonction afficher" << A.Getabs() << "," << A.Getord() << endl;
}

// les valeurs par defaut initialiser dans les argument doivent etre situees a la fin
void Exemple(int a , int b=10){
    int s = a + b ;
    cout << a << "+" << b << "=" << s << endl;
}

int main(){
//    Point A;
//    Point *B;
//
//    B = &A;
//
//    A.Initialiser(10,20);
//    A.Afficher();
//
//    Afficher(A);
//    A.Distance(*B);

    // cstor

    Point P; // appel du constructeur par defaut
    P.Afficher();

    Point *A;
    Point *B;
    Point C(30,50);

    A = new Point(); 
    A -> Afficher();
    B = new Point(20,40);
    B -> Afficher();

    C.Afficher();

    C.Afficher("Le message a afficher");

    Exemple(5); // il complete par la valeur par defaut pour b
    Exemple(5,5); // on initialise le b donc la valeur par defaut n'es plus prise en compte


    return 0;
}