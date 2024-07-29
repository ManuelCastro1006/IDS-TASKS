#include <iostream>
int main ()
{
    int val1, val2, suma, resta, multi;
    double divi;

    std::cout << "ingrese el primer valor ";
    std::cin >> val1;

    std::cout << "ingrese el segundo valor: ";
    std::cin >> val2;

    suma = val1 + val2;
    resta = val1 - val2;
    multi = val1 * val2;
    
    if (val2 != 0)
    {
        divi = static_cast< double > (val1) / val2;
    }
    
    std::cout << "La suma es: " << suma << std::endl;
    std::cout << "La resta es:" << resta << std::endl;
    std::cout << "La multiplicaclion es " << multi << std::endl;
    if (val2 == 0)
    {
       std::cout << "La division no se puede realizar, el divisor es 0" << std::endl;
    }else
    {
        std::cout << "La division es: " << divi << std::endl;
    }
    return 0;
}