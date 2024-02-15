#ifndef FILA_H
#define FILA_H
#include "header.h"

typedef struct Fila{
    Processo *head;
    Processo *tail;
    int tam;
} Fila;

Fila* criaLista();
int FilaVazia(Fila *fila);
void push(Fila *fila, Processo* processo);
Processo* pop(Fila *fila);
void liberarFila(Fila *fila);

#endif