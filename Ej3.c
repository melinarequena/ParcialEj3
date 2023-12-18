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
    int i = posicion;
    //recorro la tabla desde (pos de hashing + 1) hasta el final
    while(i < tabla->tamanio){
        if(tabla->tabla[i] == NULL){
            tabla->tabla[i] = entrada;
            tabla->tamanio++;
            return;
        }
        i++;
    }
    //recorro desde pos (0) hasta (pos de hashing)
    i = 0;
    while(i != posicion){
        if(tabla->tabla[i] == NULL){
            tabla->tabla[i] = entrada;
            tabla->tamanio++;
        }
        i++;
    }
}



/* Desarrollar la función que devuelva si existe, o no
 *  un elemento dentro de la tabla de hashing */

int existe(TablaHashing *tabla, char *entrada) {
    // recorro desde (pos de hashing) hasta el final
    int pos = hash(entrada, tabla);
    while(pos < tabla->tamanio){
        if(tabla->tabla[pos] != NULL && strcmp( tabla->tabla[pos], entrada) == 0){
            return 1;
        }
        pos++;
    }
    // recorro desde pos (0) hasta (pos de hashing)
    pos = 0;
    while (pos != hash(entrada, tabla)){
        if(tabla->tabla[pos] != NULL && strcmp(tabla->tabla[pos], entrada) == 0){
            return 1;
        }
        pos++;
    }
    return 0;
}

    /* agregar código */




TablaHashing *newTablaHashing(int capacidad) {
    TablaHashing * aux = malloc(sizeof(TablaHashing));

    if (aux == NULL) {
        printf("No hay memoria disponible");
        exit (-1);
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
