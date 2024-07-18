#include <iostream>
int main ()
{
    int edad;
    printf("ingrese su edad: ");
    scanf("%d", &edad);

    if (edad >= 18){
        printf("Usted es mayor de edad");
    }else {
        printf("usted es menor de edad");
    }
    return 0;
}