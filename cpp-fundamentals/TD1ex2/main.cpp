#include <iostream>
#include "Compte.h"
using namespace std;

// g++ Compte.cpp main.cpp -o main

int main()
{
    Compte c1((char *)"Ali", 5000);
    Compte c2((char *)"Sana", 2500);
    Compte c3((char *)"Karim", 3000);
    Compte c4((char *)"Marouane", 1000);

    c1.Consultation();
    c2.Consultation();
    c1.Depot(4000);
    c1.Virement(c2, 1000);

    Compte B[] = {c1, c2, c3};

    Bank Bank((char *)"Attijari wafa bank", B, 3);
    Bank.Ajout(c4);
    Bank.Verifie();
    Bank.Verifie(1002);
    Bank.Supprimer(1001);
    Bank.Verifie();

    return 0;
}