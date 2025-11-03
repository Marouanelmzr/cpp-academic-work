#include <iostream>
#include <cmath>
#include "Matrice.h"
using namespace std;
// g++ main.cpp -o main

int main()
{

    Vecteur A;
    Vecteur B;
    Vecteur W;

    A.Afficher();
    cout << B;

    B = ++A;
    cout << B;

    // cin >> W; //  operator>> (cin,W);
    // W.Afficher();

    Matrice M(2, 3);
    M.Fill();
    cout << M;
    Matrice Q(2, 3);
    cin >> Q;
    cout << Q;

    Vecteur Moy = Q.MoyParEtudiant();
    Moy.Afficher();

    return 0;
}