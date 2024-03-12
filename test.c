#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "exercises.c"
#include "arraylist.c"


char * _strdup2(const char * str) {
    char * aux = (char *)malloc(strlen(str) + 1);
    strcpy(aux, str);
    return aux;
}

char msg[300];
int test_id = -1;


int success(){
  printf("SUCCESS\n");
  exit(0);
}

void err_msg(char* msg){
    //if(test_id!=-1) return;
    printf("   [FAILED] ");
    printf("%s\n",msg);
    //print_trace();
}

void ok_msg(char* msg){
    //if(test_id!=-1) return;
    printf ("   [OK] ");
    printf("%s\n",msg);
}

void info_msg(char* msg){
    //if(test_id!=-1) return;
    printf ("   [ INFO ] %s\n",msg);
}

int test_suite(int(*test)(), char* msg, int max_score, int id, int req_id){
    if(test_id==-1 || test_id==id){
        printf("\n%s\n", msg);
        int score=test();

        if(id==req_id && score == max_score) success();

        printf("   partial_score: %d/%d\n", score, max_score); 
        
        return score;
    }
    return 0;
}




/*************  TESTS  ******************/
int test_crea_lista(){
    List* L = crea_lista();

    int *dato;
    int suma = 0;
    dato = (int*)first(L);

    printf("   [info] Lista: [");
    while(dato != NULL) {
       printf("%d ", *dato);
       suma += *dato;
       dato = (int*)next(L); 
    }
    printf("]\n");

    if(suma!=55){
        sprintf(msg,"suma=%d",suma);
        err_msg(msg);
        return 0;
    }
    ok_msg("crea_lista");
    return 10;  
}

int test_suma_lista(){
    List* L = create_list();
    // push random numbers between 0 and 19
    int *dato; int suma = 0;
    printf("   [info] Lista inicial: [");
    int i=rand()%20;
    while(i!=0) {
       dato = (int*)malloc(sizeof(int));
       *dato = i;
       suma += i;
       printf("%d ", *dato);
       pushBack(L, dato);
       i=rand()%20;
    }
    printf("]\n");

    int suma2 = sumaLista(L);
    printf("   [info] suma=%d\n",suma2);
    if(suma!=suma2){
        sprintf(msg,"suma real=%d, suma calculada por la funcion=%d",suma, suma2);
        err_msg(msg);
        return 0;
    }

    ok_msg("suma_lista");
    return 10;
}

int test_elimina_elemento(){
    List* L = create_list();
    List* L_rem = create_list();

    int elem = rand()%5;


    int *dato;
    printf("   [info] Lista: [");
    int i=rand()%10;
    for (int j = 0; j < 30; j++) {
       dato = (int*)malloc(sizeof(int));
       *dato = i;
       printf("%d ", *dato);
       pushBack(L, dato);
       if (i!=elem) pushBack(L_rem, dato);
       i=rand()%5;
    }
    printf("]\n");

    eliminaElementos(L, elem);
    //compara L con L2
    dato = (int*)first(L);
    int *dato_rem = (int*)first(L_rem);
    printf("   [info] Lista (luego de eliminar los %d): [", elem);
    int success = 1;
    while(dato != NULL) {
       if(*dato != *dato_rem){
           success = 0;
       }
       printf("%d ", *dato);
       dato = (int*)next(L);

       if(success) dato_rem = (int*)next(L_rem);
    }
    printf("]\n");

    if(!success){
        err_msg("No se eliminaron los elementos correctamente");
        return 0;
    }

    ok_msg("funcion elimina_elementos");
    return 20;
}

int test_copia_pila(){
    Stack* P1 = create_stack();
    Stack* P2 = create_stack();
    Stack* Paux = create_stack();
    void *dato;
    int i = 0;
    printf("   [info] Pila P1 (inicial): [");
    while(i<10) {
       dato = (int*)malloc(sizeof(int));
       *(int*)dato = rand()%5;
       printf("%d ", *(int*)dato);
       push(P1, dato);
       push(Paux, dato);
       i++;
    }
    printf("]\n");

    copia_pila(P1, P2);
    dato = top(P1);
    void* dato2 = top(P2);
    void* dato3 = top(Paux);
    //3 stack with the same elements
    int success = 1;
    Stack* P2copy = create_stack();
    Stack* P1copy = create_stack();
    while(dato2 != NULL || dato != NULL) {

        dato2 = pop(P2);
        dato = pop(P1);
        dato3 = pop(Paux);

        if(dato3 != dato || dato3 != dato2)
            success = 0;

       if (dato2 != NULL) push(P2copy, dato2);
       if (dato != NULL) push(P1copy, dato);
    }

    if (dato != NULL || dato2 != NULL || dato3 != NULL)
        success = 0;
    

    printf("   [info] Pila P1 (final): ");
    imprime_y_vacia_pila(P1copy);

    printf("   [info] Pila P2 (final): ");
    imprime_y_vacia_pila(P2copy);
    if(!success){
        err_msg("No se copiaron los elementos correctamente");
        return 0;
    }

    ok_msg("funcion copia_pila");
    return 10;
}

int test_parentesis_balanceados(){
    char* s = _strdup2("((()))");
    printf("   [info] Cadena: %s\n", s);
    if(!parentesisBalanceados(s)){
        err_msg("retorna 0 para cadena balanceada");
        return 0;
    }
    ok_msg("balanceados");

    s = _strdup2("((())");
    printf("   [info] Cadena: %s\n", s);
    if(parentesisBalanceados(s)){
        err_msg("retorna 1 para cadena no balanceada");
        return 0;
    }
    ok_msg("no balanceados");

    s = _strdup2("{([])}");
    printf("   [info] Cadena: %s\n", s);
    if(!parentesisBalanceados(s)){
        err_msg("retorna 0 para cadena balanceada");
        return 10;
    }
    ok_msg("balanceados");

    s = _strdup2("{[}]");
    printf("   [info] Cadena: %s\n", s);
    if(parentesisBalanceados(s)){
        err_msg("retorna 1 para cadena no balanceada");
        return 10;
    }
    ok_msg("no balanceados");



    ok_msg("funcion parentesis_balanceados");
    return 20;
}

int main( int argc, char *argv[] ) {
    
    if(argc>1) test_id=atoi(argv[1]);
    srand(time(NULL));

    int total_score=0;
    total_score+=test_suite(test_crea_lista, "   Test Crea Lista...", 10, 0, test_id);
    total_score+=test_suite(test_suma_lista, "   Test Suma Lista...", 10, 1, test_id);
    total_score+=test_suite(test_elimina_elemento, "   Test Elimina Elementos...", 20, 2, test_id);
    total_score+=test_suite(test_copia_pila, "   Test Copia Pila...", 10, 3, test_id);
    total_score+=test_suite(test_parentesis_balanceados, "   Test Parentesis Balanceados...", 20, 4, test_id);

    if(argc==1)
      printf("\ntotal_score: %d/70\n", total_score);

    

    return 0;
}
