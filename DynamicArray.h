#ifndef DYNAMYCARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
class DynamicArray
{
private:
    int *data;
    int size;
public:
    DynamicArray()
    {
        this->size = 0;
        this->data = new int[0];
    }
    DynamicArray(int arr[], int size)
    {
        this->size = size;
        this->data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = arr[i];
    }
    DynamicArray(const DynamicArray &o)
    {
        this->size = o.size;
        this->data = new int[o.size];
        for (int i = 0; i < size; i++)
            data[i] = o.data[i];
    }
    void pushBack(DynamicArray &p, int nuevo)
    {
        this->size = p.size + 1;
        delete[] data;
        this->data = new int[size];
        for (int i = 0; i < size; i++)
        {
            if (i < size - 1)
            {
                data[i] = p.data[i];
            }
            else
                data[i] = nuevo;
        }
        for (int i = 0; i < size; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    void insertar(DynamicArray &n, int dir, int nuevo)
    {
        this->size = n.size + 1;
        delete[] data;
        this->data = new int[size];
        
        for (int i = 0; i < size; i++)
        {
            if (i < dir - 1)
                data[i] = n.data[i];

            else if (i > dir - 1)
                data[i] = n.data[i - 1];

            else
                data[i] = nuevo;
        }

        for (int i = 0; i < size; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    void eliminar(DynamicArray &e, int dir)
    {
        this->size = e.size - 1;
        delete[] data;
        this->data = new int[size];
        for (int i = 0; i < size; i++)
        {
            
            if (i < dir - 1)
            {
                data[i] = e.data[i];
            }
            else if (i >= dir - 1)
            {
                data[i] = e.data[i + 1];
            }
        }
        for (int i = 0; i < size; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    int getSize() const
    {
        return size;
    }
    ~DynamicArray()
    {
        delete[] data;
        std::cout << "Eliminado correctamente.\n";
    }
};
#endif