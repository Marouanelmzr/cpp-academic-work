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

    float &operator[](int i) const
    {
        if (i > 0 && i < dim)
            return T[i];
    }

    Vecteur &operator=(const Vecteur &V)
    {
        cout << "Affectation :" << this << " from " << &V << endl;
        dim = V.dim;
        T = nullptr;
        T = new float[dim];
        for (int i = 0; i < dim; i++)
        {
            T[i] = V.T[i];
        }
        return (*this);
    }

    Vecteur operator+(const Vecteur &V)
    {
        Vecteur R(dim);
        if (dim == V.dim)
        {
            for (int i = 0; i < dim; i++)
                R[i] = V[i] + T[i];
        }
        return R;
    }
    float operator*(const Vecteur &A)
    {
        float s = 0;
        if (dim == A.dim)
        {
            for (int i = 0; i < dim; i++)
                s += A[i] * T[i];
        }
        return s;
    }

    Vecteur operator*(float x)
    {
        Vecteur V(dim);
        for (int i = 0; i < dim; i++)
            V[i] = x * T[i];
        return V;
    }
    friend Vecteur operator*(float val, const Vecteur &V)
    {
        // pas de this dans une fonction amie
        Vecteur A(V.dim);
        for (int i = 0; i < V.dim; i++)
        {
            A.T[i] = val * V.T[i];
        }
        return V;
    }

    // surcharge d'operator cout et cin (sortie / entree)

    friend ostream &operator<<(ostream &sortie, const Vecteur &V) // sortie
    {
        sortie << "[ ";
        for (int i = 0; i < V.dim; i++)
            sortie << V.T[i] << ",";
        sortie << "]" << endl;

        return sortie;
    }
    friend istream &operator>>(istream &entre, Vecteur &V) // entree
    {
        cout << "Saisie des notes :" << endl;
        for (int i = 0; i < V.dim; i++)
        {
            cout << "Note " << i + 1 << " : ";
            entre >> V.T[i];
        }

        return entre;
    }

    // surcharge de l'operator incrementation

    Vecteur operator++(int) // post incrementation
    {
        Vecteur A = (*this);
        for (int i = 0; i < dim; i++)
            T[i]++;
        return A;
    }
    Vecteur operator++() // pre incrementation
    {
        for (int i = 0; i < dim; i++)
            T[i]++;
        return (*this);
    }
};