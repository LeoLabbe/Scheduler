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

Fila* criaLista() {
    Fila *novo = (Fila*)malloc(sizeof(Fila));
    novo->head = NULL;
    novo->tail = NULL;
    novo->tam = 0;

    return novo;
}

int FilaVazia(Fila *fila) {
    if (fila->tam == 0){
        return 1;
    } else {
        return 0;
    }
}

void push(Fila *fila, Processo* processo) {
    if (FilaVazia(fila) == 1) {
        fila->head = processo;
        fila->tail = processo;
    } else {
        processo->prox = fila->tail;
        fila->tail = processo;
    }
    fila->tam++;
}

Processo* pop(Fila *fila) {
    if(FilaVazia(fila) == 1) {
        fprintf(stderr, "Fila vazia!");
    }
    Processo *p = fila->head;

    Processo *temp = fila->tail; 
    while(temp->prox != fila->head) {
        temp = temp->prox;
    }
    fila->head = temp;

    return p;
}

void liberarFila(Fila *fila) {
    Processo *p_atual = fila->tail;
    while(p_atual->prox != NULL) {
        Processo *p_temp = p_atual;
        p_atual->prox;
        free(p_temp);
    }

    free(fila);
}