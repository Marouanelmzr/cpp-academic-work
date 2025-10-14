// Declaration de la classe Point

class Point
{

    float abs;
    float ord;

public:
    void Initialiser(float, float);
    void Afficher();
    void Afficher(char *);
    float Getabs() { return abs; };
    float Getord() { return ord; };
    float Distance(Point);

    // un ctor est une methode qui a le meme nom que la classe et n'as pas de type de retour
    Point();             // ctor par defaut
    Point(float, float); // ctor a deux argument
};