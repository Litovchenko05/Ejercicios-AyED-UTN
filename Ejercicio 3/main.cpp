#include <iostream>

using namespace std;
float promedio(float x, float y, float z);

int main(){
    float num1, num2, num3;
    cout<<"Ingrese el primer precio: "<<endl;
    cin>>num1;
    cout<<"Ingrese el segundo precio: "<<endl;
    cin>>num2;
    cout<<"Ingrese el tercer y ultimo precio: "<<endl;
    cin>>num3;
    cout<<"El promedio de los precios es: $"<<promedio(num1, num2, num3)<<endl;
    return 0;
}

float promedio(float x, float y, float z){
    float resultado = (x + y + z)/3;
    return resultado;
}