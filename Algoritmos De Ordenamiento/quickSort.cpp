#include <iostream>

using namespace std;

template <typename T>
void mostrarArreglo(T *cadena, int tamanio) {
    for (int i = 0; i < tamanio; i++)
    {
        cout << cadena[i] << " - ";
    }
    cout << endl;
}

// Recoge los datos de la funcion particion para intercambiar los valores de los elementos
// mediante el puntero a funcion "void (*c)(T*,T*)"
template <typename T>
void cambiar(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

//Compara cada elemento de la cadena con el pivote
template <typename T>
int particion(T *array, int menor, int mayor,void (*c)(T*,T*)) {
    T pivote = array[mayor];
    int i = (menor - 1);
    
    for (int j = menor; j < mayor; j++)
    {
        if (array[j] <= pivote)
        {
            i++;

            c(&array[i],&array[j]);
        }
    }

    c(&array[i + 1], &array[mayor]);
    return (i + 1);
}

template <typename T>
void quickSort(T *array, int menor, int mayor) {
    if (menor < mayor)
    {
        T pi = particion(array,menor,mayor,cambiar);
        quickSort(array,menor,pi - 1);
        quickSort(array,pi + 1,mayor);
    }
}

int main() {

    int cadena[] = {1,5,3,7,8,2,9,6};
    int tam = sizeof(cadena) / sizeof(cadena[0]);
    char cadena1[5] = {'h','o','l','a','!'};
    cout << "\nARREGLO DESORDENADO\n";
    mostrarArreglo(cadena,tam);

    quickSort(cadena,0,tam - 1);

    cout << "\nARREGLO ORDENADO\n";
    mostrarArreglo(cadena,tam);

    cout << "\nMOSTRAR CARACTERES DESORDENADOS\n";
    mostrarArreglo(cadena1,5);

    cout << "\nCARACTERES ORDENADOS\n";
    quickSort(cadena1,0,4);
    mostrarArreglo(cadena1,5);

    return 0;
}