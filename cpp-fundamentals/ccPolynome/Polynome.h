#include "Monome.h";
#include <iostream>
using namespace std;

class Polynome
{
    int deg;
    Monome **Poly;

public:
    Polynome(int n) : deg(n)
    {
        Poly = new Monome *[deg];
        for (int i = 0; i < deg; i++)
        {
            Poly[i] = new Monome(0, i);
        }
    };
    void operator+(const Monome &M)
    {
        if (M.GetDeg() > deg)
        {
            cout << "impossible" << endl;
        }
        else
        {
            int pos = M.GetDeg();
            float coef = Poly[pos]->GetCoeff() + M.GetCoeff();
            Poly[pos]->SetCoeff(coef);
            cout << "Addition reussie" << endl;
        }
    }
    friend ostream &operator<<(ostream &sortie, const Polynome &P)
    {
        for (int i = 0; i < P.deg; i++)
        {
            if (P.Poly[i]->GetCoeff() != 0)
            {
                sortie << *P.Poly[i] << " ";
            }
        }
        return sortie;
    }
    void calcul(float x)
    {
        float Res;
        for (int i = 0; i < deg; i++)
        {
            Res += Poly[i]->calcul(x);
        }
        if (Res >= 0)
            cout << *this << " ( tel que x = " << x << " ) = " << Res << endl;
        else
            cout << *this << " ( tel que x = " << x << " ) = - " << -Res << endl;
    }
    Monome *operator[](int pos) const // const est necessaire au cas ou le polynome qu on veux afficher est cst
    // on as deux cas de l'operateur d'indexation
    // 1. on return un Monome 'return *P[i]' alors dans la synthaxe 'Monome &operator[]'
    // alors l'utilisation de ce dernier ce passe : cout << P[i] car c est deja un monome mais on peut pas return de nullptr dans ce cas
    // 2. on return un Pointeur vers un Monome 'return P[i]' alors dans la synthaxe 'Monome *operator[]'
    // dans ce dernier on peux return un nullptr (pointeur null) mais dans l'utilisation : cout << *P[i] car c'est un pointeur
    {
        if (Poly[pos]->GetCoeff() != 0)
        {
            return Poly[pos];
        }
        return nullptr;
    }
};