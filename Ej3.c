//
// Created by Administrador on 8/8/2023.
//

#include "Ej3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Desarrollar la función que resuelva una colisión a través
 *  de una redispersión lineal, es decir, que busque la siguiente
 *  posición disponible disponible en la tabla de hash */

void redispersionLineal(TablaHashing *tabla, char *entrada, int posicion) {
   int i=1;
    while(posicion+i < tabla->tamanio && tabla->tabla[posicion+i] != NULL){
        i++;
    }
    if(tabla->tabla[posicion+i] == NULL){
        strcpy(tabla->tabla[posicion+i], entrada);
    }else{
        i=0;
        while(i != posicion && tabla->tabla[i] != NULL){
            i++;
        }
        if(tabla->tabla[i] == NULL){
            strcpy(tabla->tabla[i], entrada);
        }
        /*else{
            printf("No hay mas lugar\n");
        }
        NO ES NECESARIO UN ELSE PORQUE YA EN agregarEntrada HAY UN TABL COMPLETA
         */
    }


}



/* Desarrollar la función que devuelva si existe, o no
 *  un elemento dentro de la tabla de hashing */

int existe(TablaHashing *tabla, char *entrada) {
    int posicion = hash(entrada, tabla);
    if(strcmp(entrada, tabla->tabla[posicion]) == 0){
        return 1; //Existe
    }else{
        int i=1;
        while(i+posicion < tabla->tamanio && strcmp(tabla->tabla[i+posicion], entrada) != 0){
            i++;
        }
        if(tabla->tabla[i+posicion] != NULL && strcmp(tabla->tabla[i+posicion], entrada) == 0){
            return 1; //Existe
        }else{
            i=0;
            while(i < posicion){
                if(tabla->tabla[i] != NULL && strcmp(tabla->tabla[i], entrada) == 0){
                    return 1; //existe
                }else{
                    i++;
                }
            }
        }
            return 0; //no existe
    }
}

    /* agregar código */




TablaHashing *newTablaHashing(int capacidad) {
    TablaHashing * aux = malloc(sizeof(TablaHashing));

    if (aux == NULL) {
        printf("No hay memoria disponible");
        exit -1;
    }

    aux->capacidad = capacidad;
    aux->tamanio = 0;
    aux->tabla = malloc(sizeof(char *) * capacidad);
    for(int i=0; i<capacidad; i++){
        aux->tabla[i] = NULL;
    }
    return aux;
}

int hash(const char *entrada, TablaHashing *tabla) {
    int suma = 0;

    for (int i = 0; entrada[i] != '\0'; ++i) {
        suma += entrada[i];
    }

    return suma % tabla->capacidad;
}

void agregarEntrada(TablaHashing *tabla, char *entrada) {

    if ( completa(tabla) ) {
        printf("La tabla esta completa.\n");
        return;
    }

    int posicion = hash(entrada, tabla);

    if (tabla->tabla[posicion] == NULL) {
        tabla->tabla[posicion] = entrada;
        tabla->tamanio++;
    } else {
        redispersionLineal(tabla, entrada, posicion);
    }

}

int completa(TablaHashing *tabla) {
    return tabla->capacidad == tabla->tamanio;
}

void imprimir(TablaHashing *tabla) {

    printf("Tabla de hashing:\n");
    for (int i = 0; i < tabla->capacidad; ++i) {
        printf("%d -> %s\n", i, tabla->tabla[i]);
    }

}
