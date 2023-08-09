#include <stdio.h>
#include "Ej3.h"

int main() {
    TablaHashing * tabla = newTablaHashing(5);

    agregarEntrada(tabla, "estructuras"); // hash: 1
    agregarEntrada(tabla, "MatematicA"); // hash: 2
    agregarEntrada(tabla, "tipos de datos");   // hash: 3
    agregarEntrada(tabla, "algoritmos");  // hash: 4

    /* la entrada no existe */
    printf("La entrada %s", existe(tabla, "tipos de datos abstractos") ? "existe" : "no existe");

    /* 0 -> (null)
     *  1 -> estructuras
     *  2 -> MatematicA
     *  3 -> tipos de datos
     *  4 -> algoritmos  */
    imprimir(tabla);

    agregarEntrada(tabla, "tipos de datos abstractos"); // hash: 3 => colisión

    /* 0 -> tipos de datos abstractos
     *  1 -> estructuras
     *  2 -> MatematicA
     *  3 -> tipos de datos
     *  4 -> algoritmos  */
    imprimir(tabla);

    /* la entrada existe */
    printf("La entrada %s", existe(tabla, "tipos de datos abstractos") ? "existe" : "no existe");

    return 0;
}