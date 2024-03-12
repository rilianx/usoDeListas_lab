#ifndef LIST_H
#define LIST_H

typedef struct List List;

// Esta función crea una lista vacía y devuelve un puntero a la lista.
List* create_list();

// Esta función devuelve un puntero al primer elemento de la lista.
void* first(List *L);

// Esta función mueve el puntero de la lista al siguiente elemento y devuelve un
// puntero a dicho elemento.
void* next(List *L);

// Esta función inserta un nuevo elemento al inicio de la lista.
void pushFront(List *L, void *dato);

// Esta función inserta un nuevo elemento al final de la lista.
void pushBack(List *L, void *dato);

// Esta función inserta un nuevo elemento a continuación del actual de la lista.
void pushCurrent(List *L, void *dato);

// Esta función elimina el primer elemento de la lista.
void *popFront(List *L);

// Esta función elimina el último elemento de la lista.
void *popBack(List *L);

// Esta función elimina el elemento actual de la lista.
void *popCurrent(List *L);

// Esta función devuelve el tamaño de la lista.
int get_size(List *L);

#endif