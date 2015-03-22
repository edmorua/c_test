#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
/**
 * Creas un nuevo nodo.
 */
struct node_struct* newNode(int v){
	struct node_struct* n = (struct node_struct*)malloc(sizeof(struct node_struct));
	assert(n != NULL);
	n->value = v;
	n->next = NULL;
	return n;
}
/**
 * Borras un nodo
 */
void deletNode(struct node_struct *n){
	free(n);
}
/**
 * imprime la lista de nodos.
 */
void print_list(struct node_struct* l){
	if(l != NULL){
		printf("[");
		for(; l != NULL; l = l->next){
			printf("%d%c ", l->value, l->next != NULL ? ',' :']' );
		}
		printf("\n");
	}
	else
		printf("none\n");
}
/**
 * Da la longitud de la lista de forma iterativa.
 */
int len_iter(struct node_struct* n){
	/*generamos espacio en la memoria para aux*/
	struct node_struct* aux = (struct node_struct*) malloc (sizeof(struct node_struct*)); 
	int count;
	count = 0;
	aux = n; //ponemos lo de n en aux.
	while (aux){
		count = count +1; //incrementamos el contador hasta que acabemos de recorrer la lista.
		aux = aux->next; //pasamos al siguiente nodo.
	}
	return count;
}
/**
 * Da la longitud de la lista de forma recursiva.
 */
int len_rec(struct node_struct* n){
	if(n == NULL) //caso base de la recursion
		return 0;
	else
		return 1 + len_rec(n->next); //si no es nula regresamos 1 mas lo del resto de la lista.
}
/**
* Da el valor maximo almacenado en la lista n.
*/
int max (struct node_struct* n){
	/*generamos espacio en la memorua para aux*/
	struct node_struct* aux =(struct node_struct*) malloc(sizeof(struct node_struct*));
	int max; 
	aux = n; //ponemos lo de n en aux.
	max = aux->value; //ponemos el valor de la cabeza en max.
	while(aux){
		if(aux->value > max)
			max = aux->value; //mientras recorremos la lista si hay alguno mas grande que max actualizamos.
		aux = aux->next;
	}
	return max; //regresamos max
}
/**
 * Invierte la lista n.
 */
struct node_struct* inversa(struct node_struct* n){
	/*Generamos espacio en la memoria para el nodo auxiliar*/
	struct node_struct* aux = (struct node_struct*) malloc(sizeof(struct node_struct*)); //sirve para no alterar la lista.
	struct node_struct* inversa = NULL; //ponemos en NULL a la lista que sera la inversa de n.
	aux = n; //guardamos lo de n en aux.
	while(aux){
		struct node_struct* aux2; // nodo auxiliar 2
		aux2 = newNode(aux->value);//agregas el valor de aux en aux2
		aux2->next = inversa; //el siguiente de aux sera la inversa
		inversa = aux2; //actualizas la inversa al nodo aux
		aux = aux->next; //recorremos aux.
	}
	return inversa; //lista inversa
}

