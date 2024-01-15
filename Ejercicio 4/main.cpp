#include <iostream>
#include <iomanip>
#include <string>


int leerAño();
int leerMes();
int leerDia();

int main(){
    int anio,mes,dia;
    anio = leerAño();
    mes = leerMes();
    dia = leerDia();
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(4) << anio << std::setw(2) << mes << std::setw(2) << dia;
    std::string fecha = ss.str();

    std::cout<<"La fecha en un solo numero de 8 digitos es: "<<fecha<<std::endl;
    return 0;

}

int leerAño(){
    int x;
        std::cout<<"Ingrese un año por favor: "<<std::endl;
        std::cin>>x;
        return x;
}

int leerMes(){
    int x;
        std::cout<<"Ingrese un mes(numerico): "<<std::endl;
        std::cin>>x;
        return x;
}

int leerDia(){
    int x;
        std::cout<<"Ahora ingrese un dia: "<<std::endl;
        std::cin>>x;
        return x;
}