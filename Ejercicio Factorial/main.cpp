#include <iostream>
using namespace std;

int leerNumero();
int factorial(int x);

int main(){
    int n;
    while((n=leerNumero())>0){
    cout<<"El factorial de "<<n<< " es: "<<factorial(n)<<endl<<endl;
    }
    return 0;
}

    int leerNumero(){
        int x;
        cout<<"Ingrese un numero por favor: "<<endl;
        cin>>x;
        return x;
}
    int factorial(int x){
        int f=1;
        for (int i=1; i<=x; i++){
            f*=i; 
    }
        return f;
}