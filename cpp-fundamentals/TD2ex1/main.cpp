#include "Matrice.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    Vecteur A;
    A.Afficher();
    A.Somme();
    A.Remplir(7);
    A.Afficher();
    Vecteur B = A;
    B.Afficher();

    // MATRICE

    Matrice M;
    M.Afficher();
    M.Remplir(2);
    M.Afficher();
    M.SommeTotale();
    Matrice C = M;
    C.Afficher();
    Matrice T = C.Transpose();
    T.Afficher();

    return 0;
}