#include <string>
#include <iostream>
using namespace std;

class Article
{
    string code;
    string name;
    float price;

public:
    Article(string cd, string n, float px) : code(cd), name(n), price(px) {} // cstor par variables
    friend ostream &operator<<(ostream &sortie, const Article &art)          // surcharge de la sortie
    {
        sortie << art.code << " " << art.name << " " << art.price ;
        return sortie;
    }
    float Get_Price()
    {
        return price;
    }
    string Get_name()
    {
        return name;
    }
    string Get_code()
    {
        return code;
    }
};