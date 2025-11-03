#include <iostream>
#include "Article.h"
using namespace std;

Article::Article(string C, string N, float P)
{
    this->Code = C;
    this->Nom = N;
    this->Prix = P;
}
float Article::GetPrix() const
{
    return Prix;
}
string Article::GetCode() const // ajout necessaire
{ 
    return Code;
}
string Article::GetNom() const // ajout necessaire
{
    return Nom;
}
bool Article::operator==(Article const &A)
{
    if (this->Code == A.Code)
    {
        cout << "Ils sont egaux" << endl;
        return true;
    }
    else
    {
        cout << "Ils sont pas egaux" << endl;
        return false;
    }
}
void Article::Afficher() const
{
    cout << this->Code << " " << this->Nom << " " << this->Prix;
}