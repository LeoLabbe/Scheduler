#include "../include/header.h"
#include "../include/Processo/processo.h"
#include "../include/Processo/processo.c"
int main() {
    Fila *fila = criaFila();
    Processo *p1 = criarProcesso(15, 10, 0);
    Processo *p2 = criarProcesso(10, 10, 1);
    Processo *p3 = criarProcesso(20, 10, 2);
    Processo *p4 = criarProcesso(8, 0, 3);

    push(fila, p1);
    push(fila, p2);
    push(fila, p3);
    push(fila, p4);

    imprimirFila(fila);
    pop(fila);
    imprimirFila(fila);
    pop(fila);
    imprimirFila(fila);
    pop(fila);
    imprimirFila(fila);

    

    return 0;
}