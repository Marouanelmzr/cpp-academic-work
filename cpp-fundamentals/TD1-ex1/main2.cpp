#include <iostream>
#include <cmath>
#include "Vecteur.h"
using namespace std;
// g++ main2.cpp -o main

int main()
{
    Vecteur Notes;
    Notes.Afficher();
    Vecteur copy = Notes;
    copy.Afficher();
    Vecteur *Ptr;
    Ptr = new Vecteur(5);
    Ptr->Afficher();
    delete Ptr;
    Ptr = nullptr;
    Ptr = &Notes;
    Ptr->Afficher();

    return 0;
}