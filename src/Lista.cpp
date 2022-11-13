#include "Lista.h"
#include<iostream>

using namespace std;

Lista::Lista()
{
    head=nullptr;
    tail=nullptr;
    cont=0;
}

void Lista::InsertarFinal(Producto d){
    Nodo *aux=new Nodo(d);

    if(head==nullptr){
        head=aux;
    }
    else{
        tail->next=aux;
        aux->prev=tail;
    }
    tail=aux;
    cont++;
}

void Lista::print(){
    Nodo *aux=head;

    if(head==nullptr){
        cout<<"Lista vacia"<<endl;
    }
    else{
        cout<<"\tLista de productos:\n"<<endl;
        while(aux){
            cout<<aux->data.ID<<" "<<aux->data.Name<<" $"<<aux->data.Price<<endl;
            aux=aux->next;
        }
    }
}
