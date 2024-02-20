#pragma once

#include "../include/processo.h"
#include "../include/header.h"

Processo* criarProcesso(int pid, int tempoCPU, int tempoChegada, TipoES* VES, int* TempoES, int nES) {
    Processo *p = (Processo*) malloc(sizeof(Processo));
    ProcessoES* listaES;

    p->tempoCPU = tempoCPU;
    p->prioridade = ALTA;
    p->pid = pid;
    p->estado = NOVO;
    p->tempoChegada = tempoChegada;
    p->tempoExecucao = 0;
    p->tempoTermino = NULL;
    p->esTerminado = 0;
    p->prox = NULL;
    p->ant = NULL;

    p->listaES = (ProcessoES*) malloc(sizeof(ProcessoES));
    listaES = p->listaES;
    listaES->tipoES = (TipoES*) malloc(sizeof(TipoES) * nES);
    listaES->tempoES = (int*) malloc(sizeof(int) * nES);

    for(int i = 0; i < nES; i++) {
		listaES -> tipoES[i] = VES[i];
		listaES -> tempoES[i] = TempoES[i];
	}
	listaES -> totalES = nES;
    return p;
}

void liberarProcesso(Processo *p) {
    free(p);
}

void imprimirProcesso(Processo *p) {

    printf("PID: %d\n", p->pid);
    printf("Tempo de CPU: %d\n", p->tempoCPU);
    printf("Prioridade: %d\n", p->prioridade);
    printf("Estado: %d\n", p->estado);
    printf("Tempo de chegada: %d\n", p->tempoChegada);
    printf("Tempo de execucao: %d\n", p->tempoExecucao);
    printf("Tempo de termino: %d\n", p->tempoTermino);
}



Fila* criaFila() {
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

void reset(Processo* process) {
	process -> prox = NULL;
	process -> ant = NULL;
}

void push(Fila *fila, Processo* processo) {
    if (fila->tam >= 10){
        printf("Fila cheia");
    }

    if (FilaVazia(fila) == 1) {
        fila->head = processo;
        fila->tail = processo;
    } else {
        processo->ant = fila->tail;
        processo->prox = NULL;
        fila->tail->prox = processo;
        fila->tail = processo;
    }
    fila->tam++;
}

void pop(Fila *fila) {
    if(FilaVazia(fila) == 1) {
        fprintf(stderr, "Fila vazia!");
    }
    Processo *p = fila->head;
    fila->head = fila->head->prox;
    fila->head->ant = NULL;

    reset(p);

    fila->tam--;

    return;
}


void imprimirFila(const char* nome_fila,Fila *fila) {
    Processo *p_atual = fila->head;
    

    printf("FILA %s:", nome_fila);
    while(p_atual != NULL) {
        printf("%d | ", p_atual->pid);
        p_atual = p_atual->prox;
    } printf("\n");
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

void trocaFila(Fila *antiga, Fila*nova) 
{
    push(nova, antiga->head);
    pop(antiga);
}