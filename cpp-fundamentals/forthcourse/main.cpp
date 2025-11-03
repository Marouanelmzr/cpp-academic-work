#include "Facture.h";
#include <iostream>
using namespace std;

// g++ main.cpp -o main

int main()
{

    Article *article = new Article("A12", "Stylo", 5.5);
    LigneFacture LF(article, 10);
    cout << LF << endl;
    


    Facture F("F2025-01", 10);
    F.Acheter(new Article("S12", "Stylo", 12), 9);
    F.Acheter(new Article("S13", "cahier", 10), 10);
    F.Acheter(new Article("S14", "cartable", 15), 11);

    cout << F << endl;

    return 0;
}