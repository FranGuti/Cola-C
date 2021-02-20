#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_cola_vacia(){
    printf("PRUEBAS COLA VACIA\n");
    cola_t* cola = cola_crear();

    print_test("La cola se creó correctamente", cola != NULL);
    print_test("Ver primero en una cola vacía es NULL", cola_ver_primero(cola) == NULL);
    print_test("La cola está vacía", cola_ver_primero(cola) == NULL);
    print_test("Desencolar una cola vacía devuelve NULL", cola_desencolar(cola) == NULL);
    cola_destruir(cola, NULL);
    print_test("La cola fue destruida", true);
}

void pruebas_unitarias(){
    printf("\nPRUEBAS UNITARIAS\n");
    cola_t* cola = cola_crear();
    int uno = 1;
    int* n1 = &uno;

    print_test("Encolo el número uno", cola_encolar(cola, n1));
    print_test("La cola no está vacía", !cola_esta_vacia(cola));
    print_test("Ver primero es igual a uno", cola_ver_primero(cola) == n1);
    print_test("Desencolar es igual a uno", cola_desencolar(cola) == n1);
    cola_destruir(cola, NULL);
}

void pruebas_elementos(){
    printf("\nPRUEBAS VARIOS ELEMENTOS\n");
    cola_t* cola = cola_crear();
    int uno = 1;
    int dos = 2;
    int tres = 3;
    int cuat = 4;
    int* n1 = &uno;
    int* n2 = &dos;
    int* n3 = &tres;
    int* n4 = &cuat;

    print_test("Encolo el número uno", cola_encolar(cola, n1));
    print_test("La cola no está vacía", !cola_esta_vacia(cola));
    print_test("Encolo el número dos", cola_encolar(cola, n2));
    print_test("La cola no está vacía", !cola_esta_vacia(cola));
    print_test("Encolo el número tres", cola_encolar(cola, n3));
    print_test("La cola no está vacía", !cola_esta_vacia(cola));
    print_test("Encolo el número cuatro", cola_encolar(cola, n4));
    print_test("La cola no está vacía", !cola_esta_vacia(cola));
    print_test("Ver primero es igual a uno", cola_ver_primero(cola) == n1);
    print_test("Desencolar es igual a uno", cola_desencolar(cola) == n1);
    print_test("La cola no está vacía", !cola_esta_vacia(cola));
    print_test("Ver primero es igual a dos", cola_ver_primero(cola) == n2);
    print_test("Desencolar es igual a dos", cola_desencolar(cola) == n2);
    print_test("La cola no está vacía", !cola_esta_vacia(cola));
    print_test("Ver primero es igual a tres", cola_ver_primero(cola) == n3);
    print_test("Desencolar es igual a tres", cola_desencolar(cola) == n3);
    print_test("La cola no está vacía", !cola_esta_vacia(cola));
    print_test("Ver primero es igual a cuatro", cola_ver_primero(cola) == n4);
    print_test("Desencolar es igual a cuatro", cola_desencolar(cola) == n4);
    print_test("La cola está vacía", cola_esta_vacia(cola));
    cola_destruir(cola, NULL);
}

bool pruebas_de_volumen(size_t tam){
    cola_t* cola = cola_crear();
    if(!cola){
        return false;
    }
    size_t* arreglo = malloc(sizeof(void*) * tam);
    bool estado = true;

    if (arreglo == NULL){
        cola_destruir(cola, NULL);
        return false;
    }

    for (size_t i = 0; i < tam; i++){
        arreglo[i] = i;
        if(!cola_encolar(cola, &arreglo[i])){
            estado = false;
        }
    }

    for (size_t i = 0; i < tam; i++){
        if((cola_ver_primero(cola) != &arreglo[i]) || (cola_desencolar(cola) != &arreglo[i])){
            estado = false;
        }
    }

    if(cola_ver_primero(cola) != NULL){
        estado = false;
    }

    cola_destruir(cola, (*free));
    free(arreglo);
    return estado;
}

void pruebas_cola_alumno(){
    pruebas_cola_vacia();
    pruebas_unitarias();
    pruebas_elementos();
    print_test("\nPRUEBAS DE VOLUMEN", pruebas_de_volumen(100000));
}
