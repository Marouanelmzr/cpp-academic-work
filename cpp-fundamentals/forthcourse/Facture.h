#include "LigneFacture.h"

class Facture
{
    string numero;
    LigneFacture **Lignes;
    int count;
    int capacity;
    int Existedeja(string code)
    {
        for (int i = 0; i < count; i++)
        {
            if (Lignes[i]->Getart()->Get_code() == code)
                return i;
        }
        return -1; // seulement si aucun trouvé
    };

public:
    Facture(string numero, int capacity) : numero(numero), capacity(capacity)
    {
        Lignes = new LigneFacture *[capacity];
        count = 0;
    };
    bool Acheter(Article *article, int quantity)
    {
        if (count >= capacity)
            return false;

        int pos = Existedeja(article->Get_code());
        if (pos != -1)
        {
            // L'article existe déjà → on augmente juste la quantité
            int qte = Lignes[pos]->Getquantity();
            Lignes[pos]->Setquantity(qte + quantity);
            return true;
        }

        // Sinon, on ajoute une nouvelle ligne
        Lignes[count++] = new LigneFacture(article, quantity);
        return true;
    }

    friend ostream &operator<<(ostream &sortie, const Facture &Facture)
    {
        sortie << Facture.numero << Facture.count;
        for (int i = 0; i < Facture.count; i++)
        {
            sortie << *(Facture.Lignes[i]) << endl;
        }
        return sortie;
    };
};