#include "arraylist.h"
#include <stdio.h>
#include <stdlib.h>


struct List {
  void* data[100];
  int current;
  int size;
};

typedef List List;

List* create_list() {
  List* L = (List*)malloc(sizeof(List));
  L->current = 0;
  L->size = 0;
  return L;
}

void* first(List *L) {
  if(L->size == 0) {
    return NULL;
  }
  L->current = 0;
  return L->data[L->current];
}

void* next(List *L) {
  if(L->current < L->size - 1) {
    L->current++;
    return L->data[L->current];
  }
  return NULL;
}

void pushFront(List *L, void *dato) {
  if(L->size == 0) {
    L->data[0] = dato;
    L->size++;
    return;
  }
  for(int i = L->size; i > 0; i--) {
    L->data[i] = L->data[i - 1];
  }
  L->data[0] = dato;
  L->size++;
}

void pushBack(List *L, void *dato) {
  L->data[L->size] = dato;
  L->size++;
}

void pushCurrent(List *L, void *dato) {
  if(L->size == 0) {
    L->data[0] = dato;
    L->size++;
    return;
  }
  for(int i = L->size; i > L->current; i--) {
    L->data[i] = L->data[i - 1];
  }
  L->data[L->current + 1] = dato;
  L->size++;
}

void* popFront(List *L) {
  if(L->size == 0) {
    return NULL;
  }
  void* dato = L->data[0];
  for(int i = 0; i < L->size - 1; i++) {
    L->data[i] = L->data[i + 1];
  }
  L->size--;
  return dato;
}

void* popBack(List *L) {
  if(L->size == 0) {
    return NULL;
  }
  void* dato = L->data[L->size - 1];
  L->size--;
  return dato;
}

void* popCurrent(List *L) {
  if(L->size == 0) {
    return NULL;
  }
  void* dato = L->data[L->current];
  for(int i = L->current; i < L->size - 1; i++) {
    L->data[i] = L->data[i + 1];
  }
  L->size--;
  L->current--;
  return dato;
}

int get_size(List *L) {
  return L->size;
}
