#ifndef LISTA_H
#define LISTA_H
#include"Nodo.h"

class Lista
{
    public:
        Lista();
        Nodo *head;
        Nodo *tail;
        int cont;
        //Insertar
        void InsertarFinal(Producto);
        //Mostrar
        void printTail(void);
        void printHead(void);
        void tamanio(void);
        //Ordenamientos
        void BubbleSort(Lista *lis);
        void SelectSort(Lista *lis);
        void InsertSort(Lista *lis);
        void QuickSort(Lista *lis);
        void MergeSort(Lista *lis,int);
        void ShellSort(Lista *lis,int);
};

#endif // LISTA_H
