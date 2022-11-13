#ifndef PRODUCTO_H
#define PRODUCTO_H
#include<string>


using namespace std;

class Producto
{
    public:
        Producto();
        Producto(string,float,int);

        string Name;
        float Price;
        int ID;

};

#endif // PRODUCTO_H
