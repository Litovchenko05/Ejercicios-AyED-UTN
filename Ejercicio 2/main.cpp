#include <iostream>

using namespace std;
float funcionSuma(float x, float y);
float funcionResta(float x, float y);
float funcionProducto(float x, float y);
void funcionCociente(float x, float y);

int main(){
    float a,b;
    cout<<"Ingrese el primer numero: "<<endl;
    cin>>a;
    cout<<"Ingrese el segundo numero: "<<endl;
    cin>>b;
    cout<<"Sus resultados son: "<<endl;
    cout<<"Suma: "<<funcionSuma(a,b)<<endl;
    cout<<"Resta: "<<funcionResta(a,b)<<endl;
    cout<<"Producto: "<<funcionProducto(a,b)<<endl;
    funcionCociente(a,b);

    return 0;
}

float funcionSuma(float x, float y){
    float suma = x + y;
    return suma;
}

float funcionResta(float x, float y){
    float resta = x - y;
    return resta;
}

float funcionProducto(float x, float y){
    float producto = x * y;
    return producto;
}

void funcionCociente(float x, float y){
    if(y>0){
        float cociente = x / y;
        cout<<"Cociente:S "<<cociente<<endl;
    }else{
        cout<<"La división por 0 no está definida"<<endl;
    }    
}