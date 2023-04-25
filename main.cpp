#include "DynamicArray.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    DynamicArray pa;
    std::cout << pa.getSize() << std::endl;
    int array[] = {1,2,3,4};
    DynamicArray pa1(array,4);
    DynamicArray pa2 = pa1;
    std::cout << pa2.getSize() << std::endl;

    // push back
    DynamicArray pa3;
    pa3.pushBack(pa1,5); // 1 2 3 4 5
    std::cout << pa3.getSize() << std::endl; // 5
    // insertar
    DynamicArray pa4;
    pa4.insertar(pa3,2,7); // 1 7 2 3 4 5
    std::cout << pa4.getSize() << std::endl; // 6   
    // eliminar
    DynamicArray pa5;
    pa5.eliminar(pa4,1); // 7 2 3 4 5
    std::cout << pa5.getSize() << std::endl; // 5

    DynamicArray *ptr = &pa2;
    std::cout << ptr->getSize() << std::endl;
    return 0;
}
