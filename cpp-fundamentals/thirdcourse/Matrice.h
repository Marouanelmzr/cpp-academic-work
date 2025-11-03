//
// Created by El haddad Mohamed on 13/10/2025.
//

#include <iostream>
using namespace std;
#include "Vecteur.h"

class Matrice
{

    int nblig;
    int nbcol;
    Vecteur **Mat;

public:
    Matrice(int lig, int col) // cstor par valeur
    {
        cout << " Cstror normal" << endl;
        nblig = lig;
        nbcol = col;
        Mat = new Vecteur *[nblig];
        for (int i = 0; i < nblig; i++)
        {
            Mat[i] = new Vecteur(nbcol);
        }
    }
    void Afficher() const
    {
        for (int i = 0; i < nblig; i++)
        {
            Mat[i]->Afficher();
        }
    }
    void Fill()
    {
        cout << " SAISIE DE PLUSIERS NOTES" << endl;
        for (int i = 0; i < nblig; i++)
        {
            cout << " NOTE POUR ETUDIANT " << i + 1 << " : " << endl;
            cin >> *Mat[i];
        }
    }
    Matrice(const Matrice &M) // recopie
    {
        nblig = M.nblig;
        nbcol = M.nbcol;
        Mat = nullptr;
        Mat = new Vecteur *[nblig];
        for (int i = 0; i < nblig; i++)
        {
            Mat[i] = new Vecteur(nbcol);
        }
        for (int i = 0; i < nblig; i++)
        {
            Mat[i] = M.Mat[i];
        }
    };
    ~Matrice() // destructeur
    {
        for (int i = 0; i < nblig; i++)
        {
            delete[] this->Mat[i];
        }
        delete[] Mat;
    }
    Vecteur &operator[](int i) const // d indexation
    {
        return *Mat[i];
    }
    friend ostream &operator<<(ostream &sortie, const Matrice &M) // sortie
    {
        cout << "[ ";
        for (int i = 0; i < M.nblig; i++)
            sortie << M[i]; // on peut faire M.Mat[i] ~ M[i] grace au cstor d indexation
        cout << "]" << endl;

        return sortie;
    }
    friend istream &operator>>(istream &entree, Matrice &M)
    {
        cout << " saisie des notes de " << M.nblig << "etudiants" << endl;
        for (int i = 0; i < M.nblig; i++)
        {
            entree >> M[i];
        }
        return entree;
    }
    Vecteur MoyParEtudiant()
    {
        Vecteur Moy(nblig);
        for (int i = 0; i < nblig; i++)
        {
            float S = 0;
            for (int j = 0; j < nbcol; j++)
            {
                S += (*Mat[i])[j];
            }
            Moy[i] = S / nbcol;
        }
        return Moy;
    }
};
