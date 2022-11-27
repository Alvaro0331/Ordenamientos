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

void Lista::MergeSort(Lista *lis,int tam){
    Lista *derecha=new Lista();
    Lista *izquierda=new Lista();
    Nodo *aux=lis->head;
    int media=lis->cont/2;
    int dif=tam%2;
    int i,j;

    if(lis->cont>1){
        i=0;
        while(i<media and aux){
            izquierda->InsertarFinal(aux->data);
            i++;
            aux=aux->next;
        }
        j=0;
        while(j<media+dif and aux){
            derecha->InsertarFinal(aux->data);
            j++;
            aux=aux->next;
        }
        MergeSort(izquierda,izquierda->cont);
        MergeSort(derecha,derecha->cont);

        //Merge process
        Nodo *izq=izquierda->head;
        Nodo *der=derecha->head;
        aux=lis->head;
        i=0;

        while(aux && izq && der){
            if((izq->data.ID) < (der->data.ID)){
                aux->data=izq->data;
                izq=izq->next;
                aux=aux->next;
            }
            else{
                aux->data=der->data;
                aux=aux->next;
                der=der->next;
            }
        }
        //Guardar derecha e izquierda
         if(izq){
            while(izq){
                aux->data=izq->data;
                izq=izq->next;
                aux=aux->next;
            }
         }
         if(der){
            while(der){
                aux->data=der->data;
                der=der->next;
                aux=aux->next;
            }
         }
    }
}

void Lista::ShellSort(Lista *lis,int cont){
    Nodo *unsorted=head;
    Nodo *comp=head;
    Producto aux;
    int mov,gap=cont/2;
    //Apoyo para comparar la parte anterior
    Nodo *uns;
    int mov2;
    bool band=true;

    if(head==nullptr){
        cout<<"Lista vacia"<<endl;
    }
    else{
        while(gap>1 and band){
            band=false;
            mov=0;
            while(mov<gap){
                unsorted=unsorted->next;
                mov++;
            }
            while(unsorted){
                if((comp->data.ID)>(unsorted->data.ID)){
                    aux=comp->data;
                    comp->data=unsorted->data;
                    unsorted->data=aux;
                    band=true;
                    //Comparo la parte anterior
                    if(band){
                        mov2=0;
                        uns=comp;
                        while(mov2<gap and uns){
                            uns=uns->prev;
                            mov2++;
                        }
                        if(uns and (uns->data.ID) > (comp->data.ID)){
                            aux=uns->data;
                            uns->data=comp->data;
                            comp->data=aux;
                        }
                    }
                }
                unsorted=unsorted->next;
                comp=comp->next;
            }
            gap=gap/2;
        }
        //InsertSort(lis);
    }
}
