#ifndef PROCESSO_H
#define PROCESSO_H
#pragma once


#include "header.h"

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

typedef enum {
	DISCO,
	FITA,
	IMPRESSORA
} TipoES;

typedef struct ProcessoES {
	int* tempoES;     
	int totalES; 
}ProcessoES;

typedef struct Processo{
    int pid;
    int tempoCPU;
    Prioridade prioridade; 
    int ppid;
    Estados estado;
    int tempoChegada;
    int tempoExecucao;
    int tempoTermino;
    struct Processo *prox;
    struct Processo *ant;
    ProcessoES Es;
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
void pop(Fila *fila);
void imprimirFila(const char* nome_fila, Fila *f);
void liberarFila(Fila *fila);
void trocaFila(Fila *antiga, Fila *nova);

#endif