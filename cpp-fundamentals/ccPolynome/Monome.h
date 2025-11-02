#include <iostream>
using namespace std;

class Monome
{
    int n;
    float a;

public:
    Monome(float coef, int deg)
    {
        this->n = deg;
        this->a = coef;
    }
    bool operator==(Monome const &b)
    {
        if (this->n == b.n && this->a == b.a)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Monome operator*(Monome const &Mon)
    {
        int x = this->n + Mon.n;
        float y = this->a * Mon.a;
        Monome Res(y, x);

        return Res;
    }
    Monome Deriv()
    {
        int x;
        float y;
        y = n * a;
        x = n - 1;
        Monome Res(y, x);

        return Res;
    }
    Monome &operator=(Monome const &M)
    {
        this->a = M.a;
        this->n = M.n;
    }
    friend ostream &operator<<(ostream &sortie, Monome Z)
    {
        if (Z.a < 0)
        {
            sortie << "- " << -Z.a << "x^" << Z.n;
        }
        else if (Z.a == 0)
        {
            sortie << "0";
        }
        else if (Z.a == 1 && Z.n != 1)
        {
            sortie << "+ " << "x^" << Z.n;
        }
        else if (Z.a == 1 && Z.n == 1)
        {
            sortie << "+ " << "x";
        }
        else
        {
            sortie << "+ " << Z.a << "x^" << Z.n;
        }
        return sortie;
    }
    int GetDeg() const
    {
        return n;
    }
    float GetCoeff() const
    {
        return a;
    }
    void SetDeg(int d)
    {
        n = d;
    }
    void SetCoeff(float c)
    {
        a = c;
    }

    // cc 2016 17

    float calcul(float x)
    {
        float x_puis = x;
        for (int i = 0; i < this->n - 1; i++)
        {
            x_puis = x_puis * x;
        }
        float res;
        res = a * x_puis;
        if (res >= 0)
            cout << *this << " ( tel que x = " << x << " ) = " << res << endl;
        else
            cout << *this << " ( tel que x = " << x << " ) = - " << -res << endl;
        // si on veut utiliser la sortie de la classe dans une methode
        // this est l'adresse de la classe donc faut la passer avec *this

        return res;
    }
};