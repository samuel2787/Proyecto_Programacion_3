#include "sistema.h"
int main() {
    char *archivo;
    int op, fun;
    Continuar:
    printf("\n---------MENU---------\n");
    printf("A que inventario desea ingresar:");
    for(int i=0; i<3; i++){
        printf("\nInventario %d",i+1);
    }
    printf("\n");
    scanf(" %d", &op);  
    switch(op){
        case 1:
            archivo = "inventario1.txt";
            break;
        case 2:
            archivo = "inventario2.txt";
            break;
        case 3:
            archivo = "inventario3.txt";
            break;
    }
            do{
            printf("\nQué desea hacer: ");
            printf("\nIngresar producto (1) \nModificar producto (2) \nVisualizar (3) \nEliminar (4)\nVolver al menu (5)\nSalir (6)\n");
            scanf(" %d", &fun);
                switch (fun) {
                case 1:
                    agregar(archivo);                    
                    break;                    
                case 2:
                    editar(archivo);                    
                    break;                    
                case 3:
                    visualizar(archivo);
                    break;                    
                case 4:
                    eliminar(archivo);
                    break;                    
                case 5:
                    printf("\n Volviendo a el menu de inventarios...");
                    goto Continuar;
                case 6:
                    printf("\n Saliendo del programa...");
                     goto salir;
                default:
                    printf("Opción no válida\n");
                    break;
                }
            }
            while(fun!=6);
    salir:
    return 0;
}
