#include "Matrice.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
// g++ Matrice.cpp main.cpp -o main

// Creer une classe matrice qui affiche une matrice a partir de vecteurs .

Vecteur::Vecteur(int n)
{
    dim = n;
    Tab = nullptr;
    Tab = new float[dim];
    for (int i = 0; i < dim; i++)
        Tab[i] = i + 1;
}
Vecteur::~Vecteur()
{
    cout << "\n appel dstor" << this << endl;
    delete[] Tab;
}
Vecteur::Vecteur(const Vecteur &V)
{
    cout << "\n appel copy" << this << endl;
    Tab = nullptr;
    dim = V.dim;
    Tab = new float[dim];
    for (int i = 0; i < dim; i++)
        Tab[i] = V.Tab[i];
}
// opérateur d'affectation (deep copy)
Vecteur &Vecteur::operator=(const Vecteur &V)
{
    delete[] Tab; // libère l'ancien
    dim = V.dim;
    Tab = new float[dim];
    for (int i = 0; i < dim; i++)
        Tab[i] = V.Tab[i];

    return *this;
}

void Vecteur::Remplir(float val)
{
    // delete[] Tab;
    // Tab = new float[dim];
    for (int i = 0; i < dim; i++)
        Tab[i] = val;
}
void Vecteur::Afficher() const
{
    cout << "[ ";
    for (int i = 0; i < dim; i++)
        cout << Tab[i] << ",";
    cout << "]";
}
float Vecteur::Somme() const
{
    float sum = 0;
    for (int i = 0; i < dim; i++)
        sum += Tab[i];

    cout << "\n la somme du vecteur est " << sum << endl;
    return sum;
}

// MATRICE

Matrice::Matrice(int lig, int col)
{
    nblig = lig;
    nbcol = col;
    Mat = new Vecteur *[nblig];
    for (int i = 0; i < nblig; i++)
    {
        Mat[i] = new Vecteur[nbcol]; // pour resoudre la sur dimension il suffit de faire ici 
        // new Vecteur(nbcol) ce qui vas creer un vecteur par ligne a la place d un tableau de vecteur.
        for (int j = 0; j < nbcol; j++)
        {
            Mat[i][j] = Vecteur(1); // Ma maniere de resoudre cette exercice n'est pas totalement correct 
            // je creer 3 dimensions c donc une surdimension 
        }
    }
}
Matrice::~Matrice()
{
    cout << "appel dstror mat" << endl;
    delete[] Mat;
}
Matrice::Matrice(const Matrice &M)
{
    cout << " cstor copy mat" << endl;
    Mat = nullptr;
    delete[] Mat;
    nblig = M.nblig;
    nbcol = M.nbcol;
    Mat = new Vecteur *[nblig];
    for (int i = 0; i < nblig; i++)
    {
        Mat[i] = new Vecteur[nbcol];
    }
    for (int i = 0; i < nblig; i++)
    {
        for (int j = 0; j < nbcol; j++)
        {
            Mat[i][j] = M.Mat[i][j];
        }
    }
}
void Matrice::Remplir(float val)
{
    for (int i = 0; i < nblig; i++)
    {
        for (int j = 0; j < nbcol; j++)
            Mat[i][j].Remplir(val);
    }
}
void Matrice::Afficher() const
{
    cout << endl;
    cout << "Afficher la Matrice :" << endl;
    for (int i = 0; i < nblig; i++)
    {
        for (int j = 0; j < nbcol; j++)
        {
            Mat[i][j].Afficher();
        }
        cout << endl;
    }
}
float Matrice::SommeTotale() const
{
    float sum = 0;
    for (int i = 0; i < nblig; i++)
        for (int j = 0; j < nbcol; j++)
            sum += Mat[i][j].Somme();
    cout << "la somme de la Matrice est " << sum << endl;

    return sum;
}
Matrice Matrice::Transpose() const
{
    Matrice M(this->nbcol, this->nblig);
    for (int i = 0; i < nblig; i++)
    {
        for (int j = 0; j < nbcol; j++)
        {
            M.Mat[j][i] = Mat[i][j];
        }
    }

    return M;
}
