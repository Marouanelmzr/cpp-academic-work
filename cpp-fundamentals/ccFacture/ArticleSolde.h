#include <iostream>
#include "Article.h"
using namespace std;

class ArticleSolde
{
    float Remise;
    Article *ArticleS;

public:
    ArticleSolde(string C, string N, float P, float Pourcentage)
    {
            this->ArticleS = new Article(C, N, P);
            this->Remise = Pourcentage;
    }
    float GetPrix() const
    {
        return (ArticleS->GetPrix() - ((ArticleS->GetPrix() * Remise) / 100));
    }
    Article GetArticle() const
    {
        return *ArticleS;
    }
    void Afficher() const
    {
        ArticleS->Afficher();
        cout << " Remise de " << Remise << "% " << this->GetPrix() << endl;
    }
    float GetPourcentage(){
        return Remise;
    }
};