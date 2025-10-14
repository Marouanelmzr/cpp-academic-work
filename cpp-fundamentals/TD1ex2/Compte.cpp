#include <iostream>
#include <cmath>
#include "Compte.h"
#include <algorithm>
#include <cstring>
using namespace std;

// Initialisation du compteur à 1000
int Compte::compteur = 1000;

Compte::Compte(char *nom, float solde)
{
    this->numero = compteur++;
    this->nom = nom;
    this->solde = solde;
}
int Compte::Getnum()
{
    return this->numero;
}

void Compte::Creation()
{
    char *nom;
    float solde;

    cout << "Quel est votre nom" << endl;
    cin >> nom;
    cout << "Quel est votre solde" << endl;
    cin >> solde;

    Compte(nom, solde);
}
void Compte::Consultation()
{
    cout << "Compte de " << this->nom << " dispose du solde " << this->solde << endl;
}
void Compte::Retrait(float R)
{
    if (this->solde > R)
    {
        this->solde -= R;
        cout << "Retrait fait avec succes, votre nouveau solde est : " << this->solde << endl;
    }
    else
    {
        cout << "Votre solde n'est pas suffisant" << endl;
    }
}
void Compte::Depot(float D)
{
    this->solde += D;
    cout << "Depot fait avec succes, votre nouveau solde est : " << this->solde << endl;
}
void Compte::Virement(Compte &C, float V)
{
    if (this->solde > V)
    {
        Retrait(V);
        C.Depot(V);
        cout << "Virement effectuer avec succes " << endl;
    }
    else
    {
        cout << "Votre solde n'est pas suffisant" << endl;
    }
}

// BANK :
Bank::Bank(char *name, Compte *T, int taille)
{
    this->nom = name;
    this->clients = T;
    this->taille = taille;

    cout << "Votre banque " << nom << " as ete creer avec succes." << endl;
}
void Bank::Ajout(Compte C)
{

    Compte *newT = new Compte[taille + 1];
    for (int i = 0; i < taille; i++)
        newT[i] = clients[i];

    newT[taille] = C;

    this->clients = newT;
    this->taille++;

    cout << "Ajout fait avec succes" << endl;
}
void Bank::Supprimer(int num)
{
    int a = 0;
    for (int i = 0; i < taille; i++)
        if (clients[i].Getnum() == num)
        {
            for (int j = i; j < taille; j++)
                clients[j] = clients[j + 1];

            a = 1;
            taille -= 1;

            cout << "la suppression du compte numero " << num << " est fait avec succes." << endl;
        }

    if (a == 0)
    {
        cout << "le numero que vous demander n'existe pas dans cette banque." << endl;
    }
}
void Bank::Verifie(int num)
{
    int a = 0;
    for (int i = 0; i < taille; i++)
        if (clients[i].Getnum() == num)
        {
            clients[i].Consultation();
            a = 1;
        }

    if (a == 0)
    {
        cout << "le numero que vous demander n'existe pas dans cette banque." << endl;
    }
}
void Bank::Verifie()
{
    cout << "La liste des clients est : " << endl;
    for (int i = 0; i < taille; i++)
        clients[i].Consultation();
}