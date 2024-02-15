#ifndef PROCESSO_H
#define PROCESSO_H
#include "header.h"

typedef struct Processo{
    int tempoCPU;
    int prioridade;
    int pid; 
    int estado;
    int tempoChegada;
    int tempoExecucao;
    int tempoTermino;
    Processo *prox
} Processo;


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