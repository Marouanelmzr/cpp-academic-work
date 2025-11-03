#include "Article.h"

class LigneFacture
{
    Article *art;
    int quantity;
    float Total() const
    {
        return art->Get_Price() * quantity;
    }

public:
    LigneFacture(string code, string name, float price, int quantity)
    { // car c pas un tableau d'article different (on vas pas juste creer un tableau d article)
        // il pointe simplement vers un seul article en precisant sa quantite dans la meme facture
        art = new Article(code, name, price);
        this->quantity = quantity;
    };
    /*
    LigneFacture(Article *item, int quantity)
    {
        this->art = item;
        this->quantity = quantity;
    };

    Cette maniere de faire est la meme que la suivante :
    */
    LigneFacture(Article *item, int quantity) : art(item), quantity(quantity) {};
    // ou bien on peux utiliser LigneFacture(string code, string name, float price, int quantity)
    // mais la il faudra creer des getter
    // pour acceder a ce qu'il y'as a l'interieur de item
    // LigneFacture(Article *item, int qte) : LigneFacture(item->Get_code(), item->Get_name(), item->Get_Price(), qte) {}
    friend ostream &operator<<(ostream &sortie, const LigneFacture &Ligne)
    {
        sortie << *(Ligne.art) << " " << Ligne.quantity << " " << Ligne.Total();
        return sortie;
    };
    Article *Getart() const
    {
        return art;
    }
    void Setquantity(int qte)
    {
        quantity = qte;
    }
    int Getquantity() const
    {
        return quantity;
    }
};