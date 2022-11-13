#ifndef NODO_H
#define NODO_H
#include"Producto.h"

class Nodo
{
    public:
        Nodo();
        Nodo(Producto data);

        Producto data;
        Nodo *prev;
        Nodo *next;
};

#endif // NODO_H
