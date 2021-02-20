#include "cola.h"
#include <stdbool.h>
#include <stdlib.h>

/* ******************************************************************
 * Alumno: Francisco Gutierrez                                      *
 * Padrón: 103543                                                   *
 * Corrector: Rodrigo Souto                                         *
 * *****************************************************************/

/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

typedef struct nodo{
	void* dato;
	struct nodo* sig;
}nodo_t;

struct cola{
	nodo_t* prim;
	nodo_t* ult;
};

/* ******************************************************************
 *                    AUXILIARES DE LOS NODOS
 * *****************************************************************/

nodo_t* nodo_crear(void* dato, nodo_t* sig){
	nodo_t* nodo = malloc(sizeof(nodo_t));
	if(nodo == NULL){
		return NULL;
	}
	nodo->dato = dato;
	nodo->sig = sig;
	return nodo;
}


/* ******************************************************************
 *                    PRIMITIVAS DE LA COLA
 * *****************************************************************/

cola_t* cola_crear(void){
	cola_t* cola = malloc(sizeof(cola_t));
	if(cola == NULL){
		return NULL;
	}
	cola->prim = NULL;
	cola->ult = NULL;
	return cola;
}

void cola_destruir(cola_t *cola, void destruir_dato(void*)){
	nodo_t* act = cola->prim;
	nodo_t* sig;
	while(act){
		if(destruir_dato){
			destruir_dato(act->dato);
		}
		sig = act->sig;
		free(act);
		act = sig;
	}
	free(cola);
}


bool cola_esta_vacia(const cola_t *cola){
	return cola->prim == NULL;
}

bool cola_encolar(cola_t *cola, void* valor){
	nodo_t* nuevo = nodo_crear(valor, NULL);
	if(nuevo == NULL){
		return false;
	}
	if(cola_esta_vacia(cola)){
		cola->prim = nuevo;
	}
	else{
		cola->ult->sig = nuevo;
	}
	cola->ult = nuevo;
	return true;
}

void* cola_ver_primero(const cola_t *cola){
	if(cola->prim == NULL){
		return NULL;
	}
	return cola->prim->dato;
}

void* cola_desencolar(cola_t *cola){
	if(cola_esta_vacia(cola)){
		return NULL;
	}
	if(cola->prim == cola->ult){
		cola->ult = NULL;        //En caso de que haya un solo elemento, ult ahora debe apuntar a NULL
	}
	nodo_t* nodo = cola->prim;
	cola->prim = nodo->sig;      //Avanzo prim al siguiente del primero anterior
	void* dato = nodo->dato;
	free(nodo);
	return dato;
}