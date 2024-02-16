#include "../include/header.h"
#include "../include/Processo/processo.h"

int main() {
    Fila *fila = criaFila();
    Processo *p1 = criarProcesso(15, BAIXA, 0);
    Processo *p2 = criarProcesso(10, ALTA, 1);
    Processo *p3 = criarProcesso(20, BAIXA, 2);
    Processo *p4 = criarProcesso(8, BAIXA, 3);

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
    pop(fila);

    return 0;
}