#include <iostream>
using namespace std;

// Creer une classe complex qui permet le calcule basic de nombres complexes.

class complex
{

    double Re, Im;

public:
    complex(double Re = 0, double Im = 0);
    double GetRe();
    double GetIm();

    friend ostream &operator<<(ostream &, complex);
    complex operator+(complex);
    void operator+=(double);
    void operator+=(complex);
    bool operator==(complex);
    complex &operator=(double x);
};

// ostream& operator<<(ostream& os, complex&); on peut sortir la methode de la classe si on veux utiliser les get et ne pas utiliser friend