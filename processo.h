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

Processo* criarProcesso();
void liberarProcesso(Processo *p);

#endif