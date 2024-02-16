#ifndef PROCESSO_H
#define PROCESSO_H
#include "../header.h"

typedef enum {
    NOVO,
    PRONTO,
    BLOQUEADO,
    EXECUTANDO,
    TERMINADO
} Estados;

typedef enum {
    ALTA,
    BAIXA
} Prioridade;

typedef struct Processo{
    int tempoCPU;
    int prioridade;
    int pid; 
    int ppid;
    int estado;
    int tempoChegada;
    int tempoExecucao;
    int tempoTermino;
    struct Processo *prox;
    struct Processo *ant;
} Processo;

typedef struct Fila{
    Processo *head;
    Processo *tail;
    int tam;
} Fila;

Processo* criarProcesso(int tempoCPU, int prioridade, int pid);
void imprimirProcesso(Processo *p);
void liberarProcesso(Processo *p);

Fila* criaFila();
int FilaVazia(Fila *fila);
void push(Fila *fila, Processo* processo);
Processo* pop(Fila *fila);
void imprimirFila(Fila *f);
void liberarFila(Fila *fila);

#endif