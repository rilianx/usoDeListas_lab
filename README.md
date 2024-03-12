

Ejercicios sobre el uso de Listas y Pilas
=====


---
**Antes de comenzar**

* Importe el repositorio desde su cuenta en repl.it (si no tiene siga [este tutorial](https://chartreuse-goal-d5c.notion.site/C-mo-comenzar-con-los-labs-b4dd8c7abc5a425d8f25e2eaa060e5b5?pvs=4))
* Sólo puede modificar el archivo `exercises.c` 
* Para testear sus códigos debe abrir un terminal (shell) y ejecutar el comando `./test.sh`
* Verifique que sus cambios se hayan subido a este repositorio
* **No está permitido usar comandos de git** (a menos que el profesor o ayudantes lo indiquen)
---

### EJERCICIOS

Para los primeros ejercicios usaremos un TDA Lista que tienen las siguiente operaciones:

````
List* create_list();
void* first(List *L);
void* next(List *L);
void pushFront(List *L, void *dato);
void pushBack(List *L, void *dato);
void pushCurrent(List *L, void *dato);
void *popFront(List *L);
void *popBack(List *L);
void *popCurrent(List *L);
int get_size(List *L);
````
Puedes ver lo que hace cada una de ellas en el archivo de cabecera `arraylist.h`. Debes utilizar el TDA **exclusivamente** por medio de estas operaciones.

1. Codifica la función `List* crea_lista()`. Esta función crea una Lista y agrega punteros a elementos del 1 al 10.
    Recuerda que la lista **almacena punteros**, por lo que debes **reservar memoria** a cada elemento que agregues. 
    Al finalizar retorna la lista creada.

2. Codifica la función `int sumaLista(List *L)` que reciba una lista de enteros (int*) y retorna la suma de sus elementos.

3. Codifica la función `void eliminaElementos(List*L, int elem)`. Esta función recibe una lista de punteros a int (int*) y un entero elem y debe eliminar todos los elementos de la lista que sean iguales a elem.
Asume que ``popCurrent`` luego de eliminar un elemento se
posiciona en el elemento anterior.

En los siguientes ejercicios **debes hace uso del TDA Pila** que tiene las siguientes operaciones:
````
// Esta función crea una pila vacía y devuelve un puntero a la pila.
Stack *create_stack();

// Esta función inserta un nuevo elemento al inicio de la pila.
void push(Stack *stack, void *data);

// Esta función devuelve un puntero al primer elemento de la pila.
void *top(Stack *stack);

// Esta función elimina el primer elemento de la pila.
void *pop(Stack *stack);
````

4. Codifica la función `void copia_pila(Stack* P1, Stack* P2)`. Esta función copia los punteros de la pila `P1` en la pila `P2`.
El orden de ambas pilas se debe mantener.
Se recomienda usar una **pila auxiliar**.

5. Codifica la función `int parentesisBalanceados(char *cadena)`. esta función verifica si la cadena de entrada tiene sus paréntesis balanceados. 
Retorna 1 si están balanceados, 0 en caso contrario.


> **Paréntesis balanceados** se refiere a una secuencia en la que cada tipo de paréntesis abierto (ya sean paréntesis redondos `()`, corchetes `[]`, o llaves `{}`) se cierra en el orden inverso al que se abrió. Esto asegura que todas las aperturas tienen su correspondiente cierre en el orden correcto. 
  Por ejemplo, la secuencia `([{}])` está balanceada porque cada paréntesis que se abre se cierra adecuadamente en reversa a su orden de apertura. 
  En contraste, `([)]` es un ejemplo de paréntesis desbalanceados, ya que aunque todos los tipos de paréntesis se abren y cierran, el orden no es el correcto: el corchete se cierra antes de cerrar el paréntesis que lo contiene inicialmente.
