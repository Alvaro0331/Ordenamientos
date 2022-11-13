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

        void InsertarFinal(Producto);
        void print(void);


};

#endif // LISTA_H
