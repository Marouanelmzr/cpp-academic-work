#include <iostream>
#include "ArticleSolde.h"
using namespace std;

class Facture
{
    static int NumFact;
    ArticleSolde **Achats;
    int count;
    bool ExistePas(Article const & A)
    {
        for (int i = 0; i < count; i++)
        {
            if (this->Achats[i]->GetArticle() == A)
            {
                return false;
            }
        }
        return true;
    };

public:
    Facture(int);
    void Ajouter(string, string, float, float);
    void Ajouter(Article const & , float Pourcentage);
    void Montant();
    void LesArticlesSoldes();
    void Afficher();
};