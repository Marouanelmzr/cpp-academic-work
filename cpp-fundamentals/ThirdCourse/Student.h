#include <iostream>


class Student{
    char* name;
    const int code;
    static int count;
    static int Nbr;
    public:
    Student(char * name);
    void display();
    //void setcode(int c){code=c} Interdit
    static int Countofstudents(){return Nbr;}
    ~Student(){
        delete [] name;
        Nbr--;
    }

};