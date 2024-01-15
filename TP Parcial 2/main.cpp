#include <iostream>
#include <cstring>
using namespace std;

// Estructuras de datos
struct NodoCola {
    char nombre[41];
    NodoCola* sgte;
};

struct ColaPrioridad {
    int prioridad;
    NodoCola* frente;
    NodoCola* fin;
};

struct ColaDePrioridades {
    ColaPrioridad colas[5];
};

// Prototipos de funciones
ColaDePrioridades crearColaPrioridad();
void insertarEnPrioridad(ColaDePrioridades& colas, char* nombre, int prioridad);
NodoCola* elementoMinimo(ColaDePrioridades& colas);
char* quitarMinimo(ColaDePrioridades& colas);
bool colaVacia(ColaDePrioridades& colas, int prioridad);
bool prioridadVacia(ColaDePrioridades& colas);
void imprimirEstado(ColaDePrioridades& colas);

// Funciones

// Inicializa la estructura sin elementos según prioridad y categoría.
ColaDePrioridades crearColaPrioridad() {
    ColaDePrioridades colas;

    for (int i = 0; i < 5; ++i) {
        colas.colas[i].prioridad = i;
        colas.colas[i].frente = NULL;
        colas.colas[i].fin = NULL;
    }

    return colas;
}

// Añade un elemento según prioridad y categoría.
void insertarEnPrioridad(ColaDePrioridades& colas, char* nombre, int prioridad) {
    if (prioridad >= 0 && prioridad < 5) {
        NodoCola* nuevoNodo = new NodoCola;
        strcpy(nuevoNodo->nombre, nombre);
        nuevoNodo->sgte = NULL;

        if (colas.colas[prioridad].frente == NULL) {
            colas.colas[prioridad].frente = nuevoNodo;
            colas.colas[prioridad].fin = nuevoNodo;
        } else {
            colas.colas[prioridad].fin->sgte = nuevoNodo;
            colas.colas[prioridad].fin = nuevoNodo;
        }
    } else {
        cout << "Error: Prioridad fuera de rango." << endl;
    }
}

// Retorna el elemento de la cola con más alta prioridad, según categoría.
NodoCola* elementoMinimo(ColaDePrioridades& colas) {
    NodoCola* minimo = NULL;

    for (int i = 0; i < 5; ++i) {
        if (colas.colas[i].frente != NULL) {
            if (minimo == NULL || i < minimo->nombre[0]) {
                minimo = colas.colas[i].frente;
            }
        }
    }

    return minimo;
}

// Quita de la cola el elemento con más alta prioridad.
char* quitarMinimo(ColaDePrioridades& colas) {
    NodoCola* minimo = elementoMinimo(colas);

    if (minimo != NULL) {
        for (int i = 0; i < 5; ++i) {
            if (colas.colas[i].frente == minimo) {
                colas.colas[i].frente = minimo->sgte;
                if (colas.colas[i].frente == NULL) {
                    colas.colas[i].fin = NULL;
                }
                return minimo->nombre;
            }
        }
    } else {
        return nullptr;
    }
}

// Comprueba si una cola determinada no tiene elementos.
bool colaVacia(ColaDePrioridades& colas, int prioridad) {
    if (prioridad >= 0 && prioridad < 5) {
        return (colas.colas[prioridad].frente == NULL);
    } else {
        cout << "Error: Prioridad fuera de rango." << endl;
        return true; // Indicar error en caso de prioridad fuera de rango.
    }
}

// Comprueba si todas las colas de la estructura están vacías.
bool prioridadVacia(ColaDePrioridades& colas) {
    for (int i = 0; i < 5; ++i) {
        if (colas.colas[i].frente != NULL) {
            return false; // Hay al menos una cola no vacía.
        }
    }
    return true; // Todas las colas están vacías.
}

// Función para imprimir el estado actual de las colas.
void imprimirEstado(ColaDePrioridades& colas) {
    for (int i = 0; i < 5; ++i) {
        cout << "Cola de prioridad " << i << ": ";
        NodoCola* actual = colas.colas[i].frente;
        while (actual != NULL) {
            cout << actual->nombre << " ";
            actual = actual->sgte;
        }
        cout << endl;
    }
}

int main() {
    ColaDePrioridades colas = crearColaPrioridad();

    char opcion;
    do {
        cout << "1. Insertar paciente\n2. Atender paciente\n3. Ver estado de colas\n4. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                char nombre[41];
                int prioridad;
                cout << "Ingrese el nombre del paciente: ";
                cin.ignore(); // Limpiar el buffer del teclado
                cin.getline(nombre, sizeof(nombre));
                cout << "Ingrese la prioridad (0-4): ";
                cin >> prioridad;
                insertarEnPrioridad(colas, nombre, prioridad);
                break;

            case '2':
                if (!prioridadVacia(colas)) {
                    cout << "Atendiendo a: " << quitarMinimo(colas) << endl;
                } else {
                    cout << "No hay pacientes para atender." << endl;
                }
                break;

            case '3':
                imprimirEstado(colas);
                break;

            case '4':
                cout << "Saliendo del programa.\n";
                break;

            default:
                cout << "Opcion no válida. Intente de nuevo.\n";
        }

    } while (opcion != '4');

    return 0;
}

