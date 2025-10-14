class Vecteur
{
    int dim;
    float *Tab;

public:
    Vecteur(int = 3);
    ~Vecteur();
    Vecteur(const Vecteur &);
    Vecteur &operator=(const Vecteur &V);
    void Remplir(float val);
    void Afficher() const;
    float Somme() const;
};
class Matrice
{
    int nblig;
    int nbcol;
    Vecteur **Mat;

public:
    Matrice(int lig = 2, int col = 3);
    ~Matrice();
    Matrice(const Matrice &);
    void Remplir(float val);
    void Afficher() const;
    float SommeTotale() const;
    Matrice Transpose() const;
};