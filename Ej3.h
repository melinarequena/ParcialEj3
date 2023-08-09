//
// Created by Administrador on 8/8/2023.
//

#ifndef PARCIALEJ3_EJ3_H
#define PARCIALEJ3_EJ3_H

typedef struct tabla {
    int capacidad;
    int tamanio;
    char ** tabla;
} TablaHashing;

TablaHashing * newTablaHashing(int capacidad);
int completa(TablaHashing * tabla);
void agregarEntrada(TablaHashing * tabla, char * entrada);
void redispersionLineal(TablaHashing *tabla, char *entrada, int posicion);
int existe(TablaHashing *tabla, char *entrada);
int hash(const char * entrada, TablaHashing * tabla);
void imprimir(TablaHashing * tabla);

#endif //PARCIALEJ3_EJ3_H
