#include <iostream>
#include <string>

char obtenerPrimeraVocalInterna (const std::string& str) {
    for (size_t i = 1; i < str.length(); ++i) {
        char c = str[i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        return c;
        }
    }
    return 'X';
}

std::string calcularRFC (const std::string& nombre, const std::string& appat, const std::string& apmat, const std::string& fecha) {
    std::string rfc;

    char letrainicial = appat[0];
    char primeraVocalInterna = obtenerPrimeraVocalInterna(appat);
    char inicialmaterno = (!apmat.empty()) ? apmat[0] : 'X';
    char inicialnombre = nombre[0];
    std::string anio = fecha.substr(2, 2);
    std::string mes = fecha.substr(5, 2);
    std::string dia = fecha.substr(8, 2);

    rfc = letrainicial;
    rfc += primeraVocalInterna;
    rfc += inicialmaterno;
    rfc += inicialnombre;
    rfc += anio;
    rfc += mes;
    rfc += dia;

    return rfc;
} 
int main (){
    std::string nombre, appat, apmat, fecha;

    std::cout << "Ingrese el nombre: ";
    std::getline(std::cin, nombre);

    std::cout << "Ingrese el apellido paterno: ";
    std::getline(std::cin, appat);

    std::cout << "Ingrese el apellido materno: ";
    std::getline(std::cin, apmat);

    std::cout << "Ingrese la fecha de nacimiento (YYYY/MM/DD): ";
    std::getline(std::cin, fecha);

    std::string rfc = calcularRFC(nombre, appat, apmat, fecha);

    std::cout << "El RFC calculado es: " << rfc << std::endl;

    return 0;

}