#include "Facture.h"
#include <iostream>
using namespace std;

// g++ main.cpp Article.cpp Facture.cpp -o main

int main()
{

    Facture F(4);
    Article A("art1", "LAIT", 9);
    Article B("art2", "SUCRE", 12);

    F.Ajouter(A, 0);
    F.Ajouter(B, 25);
    F.Afficher();
    F.Montant();

    return 0;
}