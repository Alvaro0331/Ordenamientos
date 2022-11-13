#include "Producto.h"

Producto::Producto()
{
    Name="Unknown";
    Price=0;
    ID=0;
}

Producto::Producto(string name,float price,int id){
    Name=name;
    Price=price;
    ID=id;
}
