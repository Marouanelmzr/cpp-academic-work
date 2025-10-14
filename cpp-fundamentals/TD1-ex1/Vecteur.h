#include <iostream>
using namespace std;

class Vecteur
{
    int dim;
    float *T;

public:
    Vecteur(int n = 3)
    {
        this->dim = n;
        T = new float[dim];
        for (int i = 0; i < dim; i++)
            T[i] = i + 1;
    };
    Vecteur(const Vecteur &V)
    {
        dim = V.dim;
        T = nullptr;
        T = new float[dim];
        for (int i = 0; i < dim; i++)
            T[i] = V.T[i];
    };
    ~Vecteur()
    {
        cout << "Destor of " << this << " : " << endl;
        delete[] T;
    };

    void Afficher()
    {
        cout << "[ ";
        for (int i = 0; i < dim; i++)
            cout << T[i] << ",";
        cout << "]" << endl;
    }
};