#include <iostream>
#include "Facture.h"
using namespace std;

int Facture::NumFact = 100;

Facture::Facture(int n)
{
    if (n > 0)
    {
        
        Achats = new ArticleSolde *[n];
        ++NumFact;
        count = 0;
    }
}
void Facture::Ajouter(string C, string N, float P, float Pourcentage)
{
    ArticleSolde *NewAchat = new ArticleSolde(C, N, P, Pourcentage);
    if (ExistePas(NewAchat->GetArticle()))
    {
        this->Achats[count] = NewAchat;
        count++;
    }
    else
    {
        cout << "L'article existe deja" << endl;
    }
}
void Facture::Ajouter(Article const &A, float Pourcentage)
{
    Ajouter(A.GetCode(), A.GetNom(), A.GetPrix(), Pourcentage);
}
void Facture::Montant()
{
    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += Achats[i]->GetPrix();
    }
    cout << "Totale : " << sum << endl;
}
void Facture::LesArticlesSoldes()
{
    cout << "Les Articles soldès sont :" << endl;
    for (int i = 0; i < count; i++)
    {
        if (Achats[i]->GetPourcentage() != 0)
        {
            Achats[i]->Afficher();
        }
    }
    cout << "----------" << endl;
}
void Facture::Afficher()
{
    cout << "Factures : -------" << endl;
    for (int i = 0; i < count; i++)
    {
        Achats[i]->Afficher();
    }
    cout << "----------" << endl;
}