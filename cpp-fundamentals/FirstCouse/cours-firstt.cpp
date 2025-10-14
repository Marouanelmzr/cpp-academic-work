#include <iostream>
using namespace std;

struct Student
{
    char name[20];
    int age;
};

Student ReadStudent()
{
    Student St;

    cout << "Name :";
    cin >> ws;
    cin.getline(St.name, 20);
    cout << "Age :";
    cin >> St.age;

    return St;
}

void ReadByRef(Student &St)
{
    cout << "Name :";
    cin.getline(St.name, 20);
    cout << "Age :";
    cin >> St.age;
}

void ReadByAdress(Student *St)
{
    cout << "Name :";
    cin.getline((*St).name, 20);
    cout << "Age :";
    cin >> St->age;
}

void WriteStudent(const Student St)
{
    cout << St.name << " age de  " << St.age << endl;
}

Student *ReadAllStudent(int &Nbr)
{
    cout << "Combien d'eleve dans la classe ?" << endl;
    cin >> Nbr;

    Student *Classe;
    Classe = new Student[Nbr];

    cout << "entrons les informations de chaque etudiant" << endl;

    for (int i = 0; i < Nbr; i++)
    {
        Classe[i] = ReadStudent();
    }

    return Classe;
}

void WriteAllStudent(const Student *Classe, int Nbr)
{

    cout << "les etudiants de la classes sont :\n";
    for (int i = 0; i < Nbr; i++)
    {
        WriteStudent(Classe[i]);
    }
}

int main()
{

    int Nbr;
    Student *Classe;

    Classe = ReadAllStudent(Nbr);
    WriteAllStudent(Classe, Nbr);

    return 0;
}