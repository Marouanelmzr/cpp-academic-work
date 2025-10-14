#include <iostream>
#include <cmath>
#include "complex.h"
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    complex a = complex(1, 2);
    cout << a;
    complex b = 3;
    cout << b;
    complex c = a + 3.5;
    cout << c;
    c += 2.5;
    cout << c;
    a += b;
    cout << a;
    if (a == b)
        cout << "ils sont egaux";
    else
        cout << "ils ne sont pas egaux";

    return 0;
}