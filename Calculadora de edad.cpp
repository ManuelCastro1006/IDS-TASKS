#include <iostream>

int main ()
{
    int edad;

    std::cout <<"Ingrese su edad porfavor:";
    std::cin>>edad;

    if (edad >=18)
    {
        std::cout<<"usted es mayor de edad" <<std::endl;
    } else{
        std::cout<<"Usted es menor de edad"<<std::endl;
    }
    return 0;
}