#include "header.h"

Processo* criarProcesso(int tempoCPU, int prioridade, int pid) {
    Processo *p = (Processo*) malloc(sizeof(Processo));

    p->tempoCPU = tempoCPU;
    p->prioridade = prioridade;
    p->pid = pid;
    p->tempoChegada = NULL;
    p->tempoExecucao = 0;
    p->tempoTermino = NULL;
    p->prox = NULL;

    return p;
}

void liberarProcesso(Processo *p) {
    free(p);
}
