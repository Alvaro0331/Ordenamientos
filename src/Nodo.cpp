#include "Nodo.h"

Nodo::Nodo()
{
    Producto();
    next=nullptr;
    prev=nullptr;
}

Nodo::Nodo(Producto data){
    this->data=data;
    next=nullptr;
    prev=nullptr;
}
