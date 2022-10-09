#include<iostream>
#include<stdio.h>

using namespace std;

struct Producto{
    int codigo;
    char nombre[50];
    int cantidad;
    float precio;
    char tipo[50];
    char percha[20];
};

void ingresarProducto(struct Producto prods[], int nproductos);
void venderProducto(struct Producto prods[],int id,int cantidad, int n);
void mostrarProductos(struct Producto prods[], int nproductos);

int main(){
    int opcion, nproductos;
    int id, cantidad,cantidadacum=0;
    struct Producto productos[20];
    for(;;){
        cout << "\t\tMENU PRINCIPAL" << endl;
        cout << "1. Ingresar productos."<<endl;
        cout << "2. Vender un producto." << endl;
        cout << "3. Salir." << endl;
        cout << "Ingrese la opcion que desea: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                cout << "Cuanto productos ingresara? : ";
                cin >> nproductos;
                cantidadacum=cantidadacum+nproductos;
                ingresarProducto(productos,nproductos);
                break;
            case 2:
                cout << "Productos." << endl;
                mostrarProductos(productos,nproductos);
                cout << "Ingrese la cantidad que desea vender: ";
                cin >> cantidad;
                cout << endl << "Ingrese el codigo a vender: ";
                cin >> id;
                venderProducto(productos,id,cantidad,nproductos);
                break;
            case 3:
                cout << "Saliendo." << endl;
                exit(0);
            default:
                cout << "Opcion invalida, intentelo de nuevo." << endl;
        }
    }
    return 0;
}

void ingresarProducto(struct Producto prods[], int nproductos, int cantidadacum){
    for(int i = 0; i < nproductos; i++){
        cout << "Codigo: ";
        cin >> prods[i].codigo;
        int numero=prods[i].codigo;
        for(int j = 0; j < cantidadacum; j++){
        while(prods[j].codigo == numero){
        	cout << "INGRESA OTRO CODIGO, YA EXISTE: ";
        	 cin >> prods[i].codigo;
		} }
	
        cout << "Cantidad: ";
        cin >> prods[i].cantidad;
        cout << "Precio unitario: ";
        cin >> prods[i].precio;
        fflush(stdin);
        cout << "Ingrese el tipo de producto: ";
        cin.getline(prods[i].tipo,50);
        cout << "Nombre del producto: ";
        cin.getline(prods[i].nombre,50);
        cout << "Percha del producto: ";
        cin.getline(prods[i].percha,20);
}
}

void venderProducto(struct Producto prods[],int id,int cantidad, int n){
    float vendido;
    struct Producto prod_vendido;
    bool existe = false;
    for(int i = 0; i < n; i++){
        if(prods[i].codigo == id){
            if (prods[i].cantidad >= cantidad){
                prods[i].cantidad -= cantidad;
                prod_vendido = prods[i];
                vendido = cantidad * prods[i].precio;
                existe = true;
            }
            break;
        }
    }
    if(existe){
        cout << "Se vendio " << cantidad << " de " << prod_vendido.nombre << " en " << vendido << " $." << endl;
    }else{
        cout << "Hubo problema a la hora de realizar la venta, intentelo de nuevo por favor. " << endl;
    }
}

void mostrarProductos(struct Producto prods[], int nproductos){
    for(int i = 0; i < nproductos; i++){
        cout << "\tProducto Numero " << (i+1) << endl;
        cout << "Codigo: " << prods[i].codigo << endl;
        cout << "Nombre: " << prods[i].nombre << endl;
        cout << "Cantidad: " << prods[i].cantidad << endl;
        cout << "Precio Unidad: " << prods[i].precio << endl << endl;
    }
}





