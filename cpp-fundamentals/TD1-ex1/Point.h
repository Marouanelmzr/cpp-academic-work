#include <iostream>
using namespace std;

class Point
{
    // priver par defaut
    float x;
    float y;
    char *name;

public: // les cstor sont public pour etre utilisable
    // Pout acceder au cordonnes prives du point :
    float Getx();
    float Gety();
    char *Getname();

    void Afficher() const; // cela permetra aussi d appliquer la fct afficher a des point const ( et aussi des pts non cst )
    void Translation(float, float);
    void Positioner(float, float);
    void PositionnerPoint(Point);
    Point Milieu(Point);
    void Comparer(Point);
    Point Symetrique();
    void Distance();
    float Distance(Point);
    void Rotation(float);
    void Proches(Point, Point);

    void Echanger(Point &);

    // cstor par defaut
    Point();
    Point(float, float, char *);
    Point(const Point &Pt)
    { // le cstor par defaut de copy permet de copier un objet dans un autre
        // Point A;
        // Point A = B ; par exemple ici copy est utilisé
        x = Pt.x;
        y = Pt.y;
        name = Pt.name;
        cout << "Copy cstor" << endl;
        // il est aussi utiliser dans l'appelle d un objet dans une methode ou fonction
        // par exemple quand on fait A.Distance(B) B est d'abord copier dans une variable temporelle avant d etre traite dans la methode
        // pour eviter cela on peut faire un passage par reference la methode opere alors sur l'objet d origine
        // comme ceci : A.Distance(&B) alors ici on utilise plus le cstor par defaut copy car on opere sur B d origine directement
    }
    ~Point()
    {
        cout << "Destructor";
        // le destructeur est toujours appeler par defaut afin de supprimer les objet apres leur duree de vie
        // ou il peu aussi etre appele par ' Delete P; '
        // a la fin de chaque fonction (y compris main) les objet utiliser a l interieur sont detruit
        // ca vas de meme pour les objet utiliser et creer a l interieur de {}
        // et ca fonctionne par LAST IN FIRST OUT le dernier objet creer est le premier detruit
    };
};