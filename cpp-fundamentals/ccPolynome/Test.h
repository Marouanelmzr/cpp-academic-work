#include <iostream>
using namespace std;
class Test{
    static inline int count=0 ;

    public:
    Test(){
        cout << "cstr , count :" << ++count << endl;
    }
    Test(int i){cout << "cstr " << i <<" , count :" << ++count << endl;}
    Test(const Test &t){cout << "cstor recopie" <<" , count :" << ++count << endl;}
    ~Test(){cout << "Dstror" <<" , count :" << --count << endl;}

};