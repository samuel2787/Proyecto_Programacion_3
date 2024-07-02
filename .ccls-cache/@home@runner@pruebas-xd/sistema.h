#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *fd;

struct productos {
    char nombre[20];
    int cantidad;
    float precio;
    float preciototal;

} pr;

void agregar(char *x) {
    
    char rpt;
    fd = fopen(x, "a");
    if (fd == NULL) {
        printf("Error al ubicar el archivo!!!\n");
        return;  
    }
    do {
        printf("\n\n");
        printf("Nombre   : "); scanf("%s", pr.nombre);
        printf("Cantidad : "); scanf("%d", &pr.cantidad);
        printf("Precio : "); scanf("%f", &pr.precio);

        fprintf(fd, "Nombre: %s", pr.nombre);
        fprintf(fd, "\tCantidad: %d", pr.cantidad);
        fprintf(fd, "\tPrecio: %.2f", pr.precio);
        pr.preciototal = pr.precio * pr.cantidad;
        fprintf(fd, "\tPrecio total: %.2f", pr.preciototal);
        fprintf(fd, "\n");
        printf("Ingresar más productos : Si(1) - No(0) -> ");
        scanf(" %c", &rpt);
        printf("\n");
    } while (rpt == '1');
    fclose(fd);
}

void editar(char *x) {
    FILE *temp;
    char nombre[20];
    int encontrado = 0;

    FILE *fd = fopen(x, "r");
    if (fd == NULL) {
        printf("Error al ubicar el archivo!!!\n");
        return;
    }

    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Error al crear archivo temporal!!!\n");
        fclose(fd);
        return;
    }

    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", nombre);

    while (fscanf(fd, "Nombre: %s\nCantidad: %d\nPrecio: %f\nPrecio total: %f\n", pr.nombre, &pr.cantidad, &pr.precio, &pr.preciototal) == 4) {
        if (strcmp(pr.nombre, nombre) == 0) {
            encontrado = 1;
            printf("\nProducto encontrado:\n");
            printf("Nombre   : %s\n", pr.nombre);
            printf("Cantidad : %d\n", pr.cantidad);
            printf("Precio   : %.2f\n", pr.precio);
            pr.preciototal = pr.precio * pr.cantidad;
            printf("Precio total : %.2f\n", pr.preciototal);

            
            printf("\nIngrese los nuevos datos:\n");
            printf("Nombre   : "); scanf("%s", pr.nombre);
            printf("Cantidad : "); scanf("%d", &pr.cantidad);
            printf("Precio   : "); scanf("%f", &pr.precio);
        }
        fprintf(temp, "Nombre: %s\n", pr.nombre);
        fprintf(temp, "Cantidad: %d\n", pr.cantidad);
        fprintf(temp, "Precio: %.2f\n", pr.precio);
        pr.preciototal = pr.precio * pr.cantidad;
        fprintf(temp, "Precio total: %.2f\n", pr.preciototal);
        fprintf(temp, "\n");
    }

    fclose(fd);
    fclose(temp);

    if (encontrado == 1) {
        remove(x);
        rename("temp.txt", x);
        printf("Producto actualizado correctamente.\n");
    } else {
        remove("temp.txt");
        printf("Producto no encontrado.\n");
    }
}

void eliminar(char *x) {

    FILE *temp;
    char nombre[20];
    int encontrado = 0;

    FILE *fd = fopen(x, "r");
    if (fd == NULL) {
        printf("Error al ubicar el archivo!!!\n");
        return;
    }

    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Error al crear archivo temporal!!!\n");
        fclose(fd);
        return;
    }

    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", nombre);

    while (fscanf(fd, "Nombre: %s\nCantidad: %d\nPrecio: %f\n", pr.nombre, &pr.cantidad, &pr.precio) == 3) {
        if (strcmp(pr.nombre, nombre) == 0) {
            encontrado = 1;
            printf("\nProducto eliminado:\n");
            printf("Nombre   : %s\n", pr.nombre);
            printf("Cantidad : %d\n", pr.cantidad);
            printf("Precio   : %.2f\n", pr.precio);
            pr.preciototal = pr.precio * pr.cantidad;
            printf("Precio   : %.2f\n", pr.preciototal);
        } else {
            fprintf(temp, "Nombre: %s\n", pr.nombre);
            fprintf(temp, "Cantidad: %d\n", pr.cantidad);
            fprintf(temp, "Precio: %.2f\n", pr.precio);
            pr.preciototal = pr.precio * pr.cantidad;
            fprintf(temp, "Precio total: %.2f\n", pr.preciototal);
            fprintf(temp, "\n");
        }
    }

    fclose(fd);
    fclose(temp);

    if (encontrado == 1) {
        remove(x);
        rename("temp.txt", x);
        printf("Producto eliminado correctamente.\n");
    } else {
        remove("temp.txt");
        printf("Producto no encontrado.\n");
    }
}


void visualizar(char *x){
    int c;
    fd = fopen(x, "r");

    if (fd == NULL){
        printf("Error al ubicar el archivo!!!\n");
        return;
    }
    printf("\n");
    printf("INVENTARIO");
    printf("\n");
    printf("\n");
    while((c=fgetc(fd))!=EOF){
        if (c=='\n'){
            printf("\n");
        }else{
            putchar(c);
        }
    }
    fclose(fd);
}