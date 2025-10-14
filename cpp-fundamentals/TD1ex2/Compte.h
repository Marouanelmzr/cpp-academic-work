// Ecrire une classe compte pour géréer le compte bancaire d'un client. On devra y retrouver un certain nombre d'informations.

class Compte
{
private:
    int numero;
    char *nom;
    float solde;
    static int compteur;

public:
    int Getnum();

    void Creation();
    void Consultation();
    void Retrait(float);
    void Depot(float);
    void Virement(Compte &, float);

    Compte(char *, float);
    Compte() {};
};

// Et une classe bank qui permet de gere les compte clients.
class Bank
{
    char *nom;
    Compte *clients;
    int taille;

public:
    void Ajout(Compte);
    void Supprimer(int num);
    void Verifie(int num);
    void Verifie();
    Bank(char *, Compte *, int);
};