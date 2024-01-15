# include <iostream>
# include <stdlib.h>
# include <conio.h>
# include <string.h>
# include <fstream>

using namespace std;

// procedimientos con datos simples
struct Nodo {
int info;
Nodo *  sgte;
};

void push (Nodo* &pila, int x) {
    Nodo* p = new Nodo();
    p -> info =x;
    p -> sgte = pila;
    pila = p;
    return;
};

int pop (Nodo* &Pila){
    int x;
    Nodo* p = Pila;
    x = Pila -> info;
    Pila = p -> sgte;
	delete p;
    return x;
};

void queue (Nodo* &frente,Nodo*&fin, int x) {
// tiene puntero al frente que solo se modifica cuando se inserta en una cola vacia, el fin se modifica siempre
    Nodo* p = new Nodo();//pedir memoria
    p -> info =x;// guardar la informacion
    p -> sgte = NULL;// como el nodo va a ser el ultimo el siguiente es NULL, es decir no hay instancia para el siguiente
    if (frente == NULL) frente =p; else fin->sgte = p;//si la cola esta vacia el principio apunta al nuevo nodo, sino se enlaza del ultimo
    fin = p;//el nuevo nodo pasa a ser el ultimo
	return;
};

int unqueue (Nodo* &frente, Nodo*& fin){
    int x;
    Nodo* p = frente;
    x = frente -> info;
    frente = p -> sgte;
    if (frente == NULL) fin = NULL;//todo semetante a pop salvo esta linea, cuando la cola se vacia i frente == NULL fin debe apuntar a NULL
	delete p;
    return x;
};




// ARCHIVOS ------------------------
void crearArchivo(){
	
	ofstream archivo;
	string nombreArchivo, frase;
	
	cout<<"Ingrese el nombre del archivo que desea escribir: ";
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::out); // ESCRIBIMOS EN EL ARCHIVO
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
	cout<<"Ingrese el contenido del txt: ";
	getline(cin,frase);
	archivo<<frase;
	
	archivo.close();
};

void leerArchivo(){
	
	ifstream archivo;
	string nombreArchivo, texto; 
	
	cout<<"Ingrese el nombre del archivo que desea leer: ";
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::in);  // LEEMOS EL ARCHIVO
	
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo o no existe"<<endl;
		exit(1);
	}
	
	while(!archivo.eof()){
		getline(archivo,texto); 
		cout<<texto<<endl;      //COPIA Y MUESTRA CADA LINEA HASTA QUE SE ACABE
	}
	
	archivo.close();
};



int main (){
	//Nodo *nodo = NULL;
	
	crearArchivo();
	leerArchivo();
	
	
	return 0;
}S
