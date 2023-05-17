#ifndef DYNAMYCARRAY_H
#define DYNAMICARRAY_H
#include <iostream>

template<typename T>
class DynamicArray
{
private:
    T* data;
    int size;
public:
    DynamicArray()
    {
        this->size = 0;
        this->data = new T[0];
    }
    DynamicArray(T arr[], int size)
    {
        this->size = size;
        this->data = new T[size];
        for (int i = 0; i < size; i++)
            data[i] = arr[i];
    }
    DynamicArray(const DynamicArray& o)
    {
        this->size = o.size;
        this->data = new T[o.size];
        for (int i = 0; i < size; i++)
            data[i] = o.data[i];
    }
    void pushBack(T nuevo)
    {
        T* tmp = new T[size + 1];
        for (int i = 0; i < size; i++)
        {
            tmp[i] = data[i];
        }

        tmp[size] = nuevo;
        delete[] data;

        data = tmp;
        size++;
        delete[] tmp;

        for (int i = 0; i < size; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    void insertar(int dir, T nuevo)
    {
        dir -= 1;
        T* tmp = new T[size + 1];
        size++;
        for (int i = 0; i < dir; i++)
        {
            if (i < dir)
            {
                tmp[i] = data[i];
            }
            else if (i > dir)
            {
                tmp[i] = data[i - 1];
            }
            else {
                tmp[i] = nuevo;
            }
        }

        delete[] data;
        data = tmp;
        delete[] tmp;

        for (int i = 0; i < size; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    void eliminar(int dir)
    {
        T* tmp = new T[size - 1];
        size--;
        for (int i = 0; i < size; i++)
        {

            if (i < dir - 1)
            {
                tmp[i] = data[i];
            }
            else if (i >= dir - 1)
            {
                tmp[i] = data[i + 1];
            }
        }
        delete[] data;
        data = tmp;
        delete[] tmp;
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