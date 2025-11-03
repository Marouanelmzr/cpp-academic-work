#include <iostream>
using namespace std;

class Article
{

    string Code;
    string Nom;
    float Prix;

public:
    Article(string, string, float);
    float GetPrix() const;
    bool operator==(Article const &);
    void Afficher() const;
    string GetCode() const;
    string GetNom() const;
};