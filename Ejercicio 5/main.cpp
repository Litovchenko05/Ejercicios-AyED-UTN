#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int fecha, anio, mes, dia;

    cout<<"Ingrese una fecha del formato (AAAAMMDD): "<<endl;
    cin>>fecha;

    anio = fecha/10000;
    mes = (fecha/100) % 100;
    dia = fecha % 100;

    cout<<"Anio: "<<anio<<endl;
    
    cout<<"Mes: "<<setfill(0)<<setw(2)<<mes<<endl;
    cout<<"Dia "<<setfill(0)<<setw(2)<<dia<<endl;
    
    return 0; 
}