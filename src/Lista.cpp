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

void Lista::printTail(){
    Nodo *aux=tail;
    if(head==nullptr){
        cout<<"Lista vacia"<<endl;
    }
    else{
        while(aux){
            cout<<aux->data.ID<<" "<<aux->data.Name<<" $"<<aux->data.Price<<endl;
            aux=aux->prev;
        }
    }
}

void Lista::printHead(){
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

void Lista::tamanio(){
    cout<<"La lista tiene "<<cont<<" guardados"<<endl;
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

void Lista::SelectSort(Lista *lis){
    Nodo *sorted=head;
    Producto aux;
    if(head==nullptr){
        cout<<"Lista vacia"<<endl;
    }
    else{
        while(sorted!=tail){
            Nodo *unsorted=sorted->next;
            Nodo *mini=sorted;
            while(unsorted){
                if(unsorted->data.ID < mini->data.ID){
                    mini=unsorted;
                }
                else{
                    unsorted=unsorted->next;
                }
            }
            aux=sorted->data;
            sorted->data=mini->data;
            mini->data=aux;

            sorted=sorted->next;
        }
    }
}

void Lista::InsertSort(Lista *lis){
    Nodo *sorted=head;
    Nodo *aux;
    Nodo *unsorted;
    if(head==nullptr){cout<<"Lista vacia"<<endl;}
    else{
        while(sorted!=tail){
            unsorted=sorted->next;
            aux=sorted;
            while(aux and aux->data.ID > unsorted->data.ID){
                aux=aux->prev;
            }
            unsorted->prev->next=unsorted->next;
            unsorted->next->prev=unsorted->prev;

            if(aux==nullptr){
                unsorted->next=head;
                head->prev=unsorted;
                head=unsorted;
            }
            else{
                unsorted->prev=aux->prev;
                unsorted->next=aux;
                aux->prev->next=unsorted;
                aux->prev=unsorted;
            }
            printHead();
            sorted=sorted->next;
        }
    }
}

void Lista::QuickSort(Lista *lis){
    Nodo *piv;
    Nodo *pivSave;
    Nodo *aux;

    Lista *mayor=new Lista;
    Lista *menor=new Lista;

    if(lis->head){
        piv=lis->head;
        pivSave=new Nodo (lis->head->data);
        aux=lis->head->next;

        while(aux){
            if((aux->data.ID)< (piv->data.ID)){
                menor->InsertarFinal(aux->data);
            }
            else{
                mayor->InsertarFinal(aux->data);
            }
            aux=aux->next;
        }

        QuickSort(menor);
        QuickSort(mayor);

        //Menor
        aux=lis->head;
        Nodo *low=menor->head;
        while(low){
            aux->data=low->data;
            aux=aux->next;
            low=low->next;
        }
        //Pivote
        {
            aux->data=pivSave->data;
            aux=aux->next;
        }
        //Mayor
        Nodo *up=mayor->head;
        while(up){
            aux->data=up->data;
            aux=aux->next;
            up=up->next;
        }
    }
}

void Lista::ShellSort(Lista *lis,int cont){
    Nodo *unsorted=head;
    Nodo *comp=head;
    Producto aux;
    int gap,mov;
    bool band=true;

    if(head==nullptr){
        cout<<"Lista vacia"<<endl;
    }
    else{
        while(gap>1 and band){
            band=false;
            gap=cont/2;
            mov=0;
            while(mov<cont-gap){
                unsorted=unsorted->next;
                mov++;
            }
            while(unsorted){
                if((comp->data.ID)>(unsorted->data.ID)){
                    aux=comp->data;
                    comp->data=unsorted->data;
                    unsorted->data=aux;
                    band=true;
                }
                unsorted=unsorted->next;
                comp=comp->next;
            }
            gap=gap/2;
        }
    }
}
