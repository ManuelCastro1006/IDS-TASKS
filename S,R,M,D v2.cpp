#include <iostream>

int main ()
{
    using namespace std;

    float val1, val2, suma, resta, multi, divi;

    cout<<"Escribe el primer valor:";
    cin>>val1;
    cout<<"Escribe el segundo valor:";
    cin>>val2;

    suma = val1 + val2;
    resta = val1 - val2;
    multi = val1 * val2;
    divi = val1 / val2;

    cout << "La suma es: " << suma << endl;
    cout << "La resta es: " << resta << endl;
    cout << "La multiplicacion es: " << multi << endl;
    cout << "La division es: " << divi << endl;

    return 0;
}