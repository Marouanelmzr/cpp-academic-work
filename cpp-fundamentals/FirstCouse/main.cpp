#include <iostream>
using namespace std ;
struct Student {
    char name[20];
    int age;
};
Student ReadStudent() {
    Student St ;
    cout << "Name : " ;
    cin >> ws ;
    cin.getline(St.name,20);
    cout << "Age : " ; cin >> St.age ;
    return St;}
void ReadByRef(  Student & St ) { // Passage par référence obligatoire
    cout << "Name : " ;
    cin.getline(St.name,20);
    cout << "Age : " ; cin >> St.age ;}
void ReadByAdresse(  Student * St ) {
    cout << "Name : " ;
    cin.getline(St->name,20);
    cout << "Age : " ; cin >> St->age ;}
void WriteStudent(Student student) {
    cout << student.name << " age de  " ;
    cout<< student.age << " ans " << endl ;
}
Student* ReadAllStudent(int& Nbre) {
    Student* Classe ;
    cout << " count of students :";
    cin >> Nbre ;
    // Allocation de l'espace pour Nbre Student
    Classe = new Student[Nbre] ;
    cout << " SAISIE DES ETUDIANTS \n";
    for(int i = 0 ; i < Nbre ; i++) {
        Classe[i]=ReadStudent() ;
    }
    return Classe ;
}
void WriteAllStudent(Student* Classe, int Nbre) {
    cout << "LISTE DES ETUDIANTS \n";
    for(int i = 0 ; i < Nbre ; i++) {
        WriteStudent(Classe[i]) ;
    } }
int main() {
 /*Student Etu{"ALI",20};
   //Etu= ReadStudent();
    // WriteStudent(Etu);
    // //ReadByRef(Etu);
    // ReadByAdresse(&Etu);
    // WriteStudent(Etu);*/
    Student* GINF1 ;
    int taille ;
    GINF1 = ReadAllStudent(taille) ;
    WriteAllStudent(GINF1,taille);
    return 0;
}
