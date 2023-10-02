#include <stdio.h>
#include <stdlib.h>
#include "pq.h"

int main() {

// Se crea la cola, y se especifica la capacidad maxima que va a tener
// pq_create(num_nodos, es_min-heap?[0:no|1:si])
	PQ * pq = pq_create(20, 0);
	int i;
	double priority;

	printf("\nCapacity of pq: %d\n\n", pq_capacity(pq));


/*
  * El Nodo de Partida uno lo inserta con una Prioridad = 0
  * pq_insert(pq, id_nodo, prioridad)
  * La prioridad para el Min-Heap sera la distancia que uno ha calculado para cada uno de los nodos
  * Inicialmente se ingresa las prioridades de los demas nodos con un valor muy grande para indicar que es infinito'
  * Se va a usar un enum para indicar los ids de los nodos (se va a tener a parte esa informacion)
*/

  pq_insert(pq, 0, 0);
	pq_insert(pq, 1, 1000);
	pq_insert(pq, 2, 1000);
	pq_insert(pq, 3, 1000);
	pq_insert(pq, 4, 1000);





	// pq_insert(pq, 0, 7);
	// pq_insert(pq, 1, 11);
	// pq_insert(pq, 2, 50);
	// pq_insert(pq, 3, 12); // changed
	// pq_insert(pq, 4, 33);
	// pq_insert(pq, 5, 51);
	// pq_insert(pq, 6, 55);
	// pq_insert(pq, 7, 21);
	// pq_insert(pq, 8, 55);
	// pq_insert(pq, 9, 80);
	// pq_insert(pq, 10, 34);
	// pq_insert(pq, 11, 25);

	pq_change_priority(pq, 3, 53);
	pq_remove_by_id(pq, 3);
	pq_remove_by_id(pq, 1);

	// print the priority queue
	for (i=0; i<pq_capacity(pq); i++) {
		if (pq_contains(pq, i)) {
			pq_get_priority(pq, i, &priority);
			printf("<---> [%9lf] <-> ID: %d\n", priority, i);
		}
	}

	printf("\nSize of pq: %d\n", pq_size(pq));

	pq_free(pq);

	return 0;
}
