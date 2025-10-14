#include <iostream>
#include <cmath>
#include "Point.h"
#include <algorithm>
using namespace std;

// les cstor par defauts
Point::Point()
{
    x = 0;
    y = 0;
    name = "nom";
}
Point::Point(float x, float y, char *name)
{
    this->x = x;
    this->y = y;
    this->name = name;
}

// les methodes du point
float Point::Getx()
{
    float x;
    x = this->x;
    return x;
}
float Point::Gety()
{
    float y;
    y = this->y;
    return y;
}
char *Point::Getname()
{
    return this->name;
}
void Point::Afficher() const // une fct const ne change pas les attribut elle permet uniquement d afficher, calculer ..
{
    cout << name << " : ( " << x << " , " << y << " )" << endl;
}
void Point::Translation(float x, float y)
{
    this->x += x;
    this->y += y;
    cout << "Translation : " << name << " : ( " << this->x << " , " << this->y << " )" << endl;
}
void Point::Positioner(float x, float y)
{
    this->x = x;
    this->y = y;
    cout << "Reposionnement : " << name << " : ( " << this->x << " , " << this->y << " )" << endl;
}
void Point::PositionnerPoint(Point P)
{
    this->x = P.Getx();
    this->y = P.Gety();
    cout << "Reposionnement de Point : " << name << " : ( " << this->x << " , " << this->y << " )" << endl;
}
Point Point::Milieu(Point P)
{
    float mx;
    float my;
    mx = (this->x + P.Getx()) / 2;
    my = (this->y + P.Gety()) / 2;

    Point Milieu(mx, my, "Milieu");

    return Milieu;
}
void Point::Comparer(Point P)
{
    if (this->x == P.Getx() || this->y == P.Gety())
    {
        cout << "Oui les deux Points " << this->name << " et " << P.Getname() << " sont identiques" << endl;
    }
    else
    {
        cout << "Non les deux Points " << this->name << " et " << P.Getname() << " ne sont pas identiques" << endl;
    }
}
Point Point::Symetrique()
{
    float symx;
    float symy;
    symx = -this->x;
    symy = -this->y;
    Point P(symx, symy, "Sym");

    cout << "le symetrique de " << this->name << " est ( " << P.Getx() << " , " << P.Gety() << ")" << endl;

    return P;
}
void Point::Distance()
{
    float mil;
    mil = sqrt((this->x) * (this->x) + (this->y) * (this->y));
    cout << "La distance a l origine de : " << name << " est " << mil << endl;
}
float Point::Distance(Point P)
{
    float dx;
    float dy;
    float mil;
    dx = (this->x) - P.Getx();
    dy = (this->y) - P.Gety();
    mil = sqrt(dx * dx + dy * dy);

    cout << "La distance entre : " << this->name << " et " << P.Getname() << " est " << mil << endl;

    return mil;
}
void Point::Rotation(float R)
{

    this->x = this->x * cos(R) - this->y * sin(R);
    this->y = this->y * cos(R) + this->x * sin(R);

    cout << "La Rotation est faite : " << name << " : ( " << this->x << " , " << this->y << " )" << endl;
}
void Point::Proches(Point A, Point B)
{
    float d1;
    float d2;
    float d3;

    d1 = Distance(A);
    d2 = Distance(B);
    d3 = A.Distance(B);
    float min_val = min(d1, min(d2, d3));

    if (d1 == min_val)
    {
        cout << "les point les plus proches sont " << this->name << " et " << A.Getname() << endl;
    }
    else if (d2 == min_val)
    {
        cout << "les point les plus proches sont " << this->name << " et " << B.Getname() << endl;
    }
    else if (d3 == min_val)
    {
        cout << "les point les plus proches sont " << A.Getname() << " et " << B.Getname() << endl;
    }
    else
    {
        cout << "ils sont eloignes de la meme distance" << endl;
    }
}

void Point::Echanger(Point &P)
{ // on passe par par & adresse afin de pouvoir le modifier meme a l exterieur de la classe
    // sinon ca ne marche pas et seulement le point sur le quel la methode est appeler sera modifier ( erreur )
    float a;
    float b;
    a = this->x;
    b = this->y;
    Positioner(P.x, P.y);
    P.Positioner(a, b);
}