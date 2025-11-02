#include "Polynome.h"
#include <iostream>
using namespace std;
// g++ main.cpp -o main

int main()
{

    Monome A(1, 1);
    Monome B(-4, 3);
    Monome C(1, 4);
    Monome D = A * C;
    Monome E = C.Deriv();
    cout << D << endl;
    cout << E << endl;
    A.calcul(3);

    Polynome P(5);
    P + A;
    P + B;
    P + C;

    cout << P << endl;
    // ici le endl est necessaire pour l'execution correct
    // je sais pas exactement pourquoi mais sans ce endl les resultat du calcul suivant sont correct qu'une fois sur deux
    P.calcul(1);
    cout << *P[3] << endl;

    return 0;
}