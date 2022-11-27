#include <iostream>
#include<windows.h>
#include"Producto.h"
#include"Nodo.h"
#include"Lista.h"

using namespace std;

int main()
{
    Producto prod;
    Lista *lis=new Lista();
    int opc;
    char opcOr;

    while(opc!=6){
        cout<<"\tMenu de una DLL aplicando metodos de ordenamiento"<<endl;
        cout<<"1.- Registrar un nuevo producto"<<endl;
        cout<<"2.- Imprimir la lista desde head"<<endl;
        cout<<"3.- Imprimir la lista desde tail"<<endl;
        cout<<"4.- Mostrar la cantidad de elementos guardados en la lista"<<endl;
        cout<<"5.- Ordenar la lista"<<endl;
        cout<<"6.- Salir del programa"<<endl;
        cout<<"Elige una opcion: ";
        fflush(stdin);
        cin>>opc;

        switch(opc){
        case 1:
            system("cls");
            cout<<"\tIngresa los siguientes datos:"<<endl;
            cout<<"Nombre del producto: ";
            fflush(stdin);
            cin>>prod.Name;
            cout<<"\nSKU: ";
            fflush(stdin);
            cin>>prod.ID;
            cout<<"\nPrecio del producto: ";
            fflush(stdin);
            cin>>prod.Price;
            lis->InsertarFinal(prod);
            system("cls");
            break;
        case 2:
            system("cls");
            lis->printHead();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            lis->printTail();
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            lis->tamanio();
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout<<"\tQue metodo de ordenamiento desea utilizar?"<<endl;
            cout<<"a.-Bubble"<<endl;
            cout<<"b.-Select"<<endl;
            cout<<"c.-Insert"<<endl;
            cout<<"d.-Quick"<<endl;
            cout<<"e.-Merge"<<endl;
            cout<<"f.-Shell"<<endl;
            cout<<"Escribe tu respuesta: ";
            fflush(stdin);
            cin>>opcOr;
            if(opcOr=='a'){
                cout<<endl;
                lis->BubbleSort(lis);
                cout<<"Lista ordenada, ingresa la opcion de ver lista para ver los cambios";
                system("pause");
                system("cls");
            }
            else if(opcOr=='b'){
                cout<<endl;
                lis->SelectSort(lis);
                cout<<"Lista ordenada, ingresa la opcion de ver lista para ver los cambios";
                system("pause");
                system("cls");
            }
            else if(opcOr=='c'){
                cout<<endl;
                lis->InsertSort(lis);
                cout<<"Lista ordenada, ingresa la opcion de ver lista para ver los cambios";
                system("pause");
                system("cls");
            }
            else if(opcOr=='d'){
                cout<<endl;
                lis->QuickSort(lis);
                cout<<"Lista ordenada, ingresa la opcion de ver lista para ver los cambios";
                system("pause");
                system("cls");
            }
            else if(opcOr=='e'){
                cout<<endl;
                lis->MergeSort(lis,lis->cont);
                cout<<"Lista ordenada, ingresa la opcion de ver lista para ver los cambios";
                system("pause");
                system("cls");
            }
            else if(opcOr=='f'){
                cout<<endl;
                lis->ShellSort(lis,lis->cont);
                cout<<"Lista ordenada, ingresa la opcion de ver lista para ver los cambios";
                system("pause");
                system("cls");
            }
            else{
                cout<<endl;
                cout<<"Opcion no valida"<<endl;
                system("pause");
                system("cls");
            }
        case 6:
            system("cls");
            cout<<"Que tenga un buen dia"<<endl;
            break;
        default:
            system("cls");
            cout<<"Opcion incorrecta, vuelve a untentarlo"<<endl;
            system("pause");
            system("cls");
        }
    }
    return 0;
}
