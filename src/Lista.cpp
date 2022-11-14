#include "Lista.h"
#include<iostream>

using namespace std;

Lista::Lista()
{
    head=nullptr;
    tail=nullptr;
    cont=0;
}

void Lista::BubbleSort(Lista *lis){
    bool band=true;
    Nodo *sorted=tail;
    Producto aux;

    if(head==nullptr){
        cout<<"Lista vacia"<<endl;
    }
    else{
        while(band){
            band=false;
            Nodo *unsorted=head;
            while(unsorted!=sorted){
                if(unsorted->data.ID > unsorted->next->data.ID){
                    //Swap
                    aux=unsorted->data;
                    unsorted->data=unsorted->next->data;
                    unsorted->next->data=aux;

                    unsorted=unsorted->next;
                    band=true;

                }
                else{
                    unsorted=unsorted->next;
                }
            }
            sorted=sorted->prev;
        }
    }
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
