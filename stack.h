#ifndef STACK_H
#define STACK_H
#include "arraylist.h"

typedef List Stack;

// Esta función crea una pila vacía y devuelve un puntero a la pila.
Stack *create_stack() { return create_list(); }

// Esta función inserta un nuevo elemento al inicio de la pila.
void push(Stack *stack, void *data) { pushFront(stack, data); }

// Esta función devuelve un puntero al primer elemento de la pila.
void *top(Stack *stack) { return first(stack); }

// Esta función elimina el primer elemento de la pila.
void *pop(Stack *stack) { return popFront(stack); }

#endif /* STACK_H */