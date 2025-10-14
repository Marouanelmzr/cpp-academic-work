#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;
// g++ Point.cpp main.cpp -o main

int main()
{

    Point A(1, 1, "A");
    Point B(2, 2, "B");
    Point C(3, 3, "C");

    // pointeur ? cours
    Point D;                              // ceci est un point par defaut
    Point *E;                             // ceci est un pointeur vers un point mais rien ne lui est assigné
    E = new Point(5, 5, "E");             // on assigne au pointeur un point de parametre 5,5,E
    Point lesPts[4];                      // ceci est un tableau de point qui utilise le cstor par defaut Point() pour chaque point du tableau
    Point *AdrLesPts[4];                  // ceci est un tableau de pointeur vers point mais chaque case du tableau ne pointe vers rien pour le moment
                                          // c un tableau dynamique
    AdrLesPts[0] = new Point(6, 6, "P1"); // on assigne au premier pointeur du tableau dynamique le point de parametre 6,6,P1
    AdrLesPts[1] = new Point();           // on assigne au deuxieme pointeur les parametre par defaut du cstor par defaut Point()
    D.Afficher();
    E->Afficher(); // puisque c un pointeur on doit d'abord acceder au point qu il pointe avant d y appliquer la methode (*E).Afficher();

    A.Afficher();
    B.Afficher();
    C.Afficher();
    B.Translation(10, 0); // Translation horizentale de 10
    A.Positioner(3, 8);
    C.PositionnerPoint(B);
    A.Distance();
    A.Distance(B);
    Point Milieu = A.Milieu(C);
    Milieu.Afficher();
    B.Comparer(C);
    Point Sym = C.Symetrique();
    Sym.Afficher();
    A.Rotation(45);
    A.Proches(B, C);

    return 0;
}