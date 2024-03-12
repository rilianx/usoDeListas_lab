#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();
   int *dato;
   for(int i = 1; i <= 10; i++) {
      dato = (int*)malloc(sizeof(int));
      *dato = i;
      pushBack(L, dato);
   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int *dato;
   int suma = 0;
   dato = (int*)first(L);
   while(dato != NULL) {
      suma += *dato;
      dato = (int*)next(L);
   }
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int *dato;
   dato = (int*)first(L);
   while(dato != NULL) {
      if(*dato == elem){
         popCurrent(L);
         //break;
      }
      dato = (int*)next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* Paux = create_stack();
   void *dato;
   while((dato = pop(P1)) != NULL) {
      push(Paux, dato);
   }
   while((dato = pop(Paux)) != NULL) {
      push(P1, dato);
      push(P2, dato);
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   Stack* S = create_stack();
   char *dato;
   int balanceados = 1;
   dato = cadena;
   while(*dato != '\0' && balanceados) {
      if(*dato == '(') {
         push(S, dato);
      } else if(*dato == ')') {
         if(top(S) == NULL || *(char*)top(S) != '('){
            balanceados = 0;
            break;
         } else {
            pop(S);
         }
      }

      if(*dato == '{') {
         push(S, dato);
      } else if(*dato == '}') {
         if(top(S) == NULL || *(char*)top(S) != '{'){
            balanceados = 0;
            break;
         } else {
            pop(S);
         }
      }

      if(*dato == '[') {
         push(S, dato);
      } else if(*dato == ']') {
         if(top(S) == NULL || *(char*)top(S) != '['){
            balanceados = 0;
            break;
         } else {
            pop(S);
         }
      }
      
      dato++;
   }

   if(top(S) != NULL) 
      balanceados = 0;
   
   return balanceados;
}

