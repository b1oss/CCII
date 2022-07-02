#include <iostream>

using namespace std;

template <typename T>

void mostrar(T* array, const int tam) {
    for (int i = 0; i < tam; i++)
    {
        cout << *(array + i) << " - ";
    }
    cout << endl;
}

template <typename T>
bool compararMenor(T x, T y) {
    return x <= y;
}

template <typename T>
bool compararMayor(T x, T y) {
    return x > y;
}

template <typename T>
void insertionSort(T *arreglo, const int tam, bool (*p)(T,T)) {
    for (int i = 0; i < tam; i++)
    {
        T temp = arreglo[i];
        int j = i - 1;
        while (j >= 0 && p(temp,arreglo[j]))
        {
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = temp;
    }
}

int main() {

    int cadena1[10] = {9,6,5,31,2,2,3,8,1,23};
    int opcion;
    cout << "\tMENU" << endl;
    cout << "1. Ordenado ascendente" << endl;
    cout << "2. Ordenado descendente" << endl;
    cin >> opcion;

    cout << "\nArreglo desordenado" << endl; 
    mostrar(cadena1,10);
    switch (opcion)
    {
    case 1: 
        cout << "\nArreglo ordenado ascendente" << endl;
        insertionSort(cadena1,10,compararMenor);
        mostrar(cadena1,10);
        break;
    case 2:
        cout << "\nArreglo ordenado descendente" << endl;
        insertionSort(cadena1,10,compararMayor);
        mostrar(cadena1,10);
        break;
    default:
        cout << "\nOpcion incorrecta." << endl;
        break;
    }

    return 0;
}