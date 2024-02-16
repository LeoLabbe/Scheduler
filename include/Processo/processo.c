#include "../header.h"

Processo* criarProcesso(int tempoCPU, int prioridade, int pid) {
    Processo *p = (Processo*) malloc(sizeof(Processo));

    p->tempoCPU = tempoCPU;
    p->prioridade = prioridade;
    p->pid = pid;
    p->estado = NOVO;
    p->tempoChegada = NULL;
    p->tempoExecucao = 0;
    p->tempoTermino = NULL;
    p->prox = NULL;
    p->ant = NULL;

    return p;
}

void liberarProcesso(Processo *p) {
    free(p);
}

void imprimirProcesso(Processo *p) {
    printf("Tempo de CPU: %d", p->tempoCPU,
           "Priodidade: %d", p->prioridade,
           "PID: %d", p->pid,
           "Estado: %d", p->estado,
           "Tempo de chegada: %d", p->tempoChegada,
           "Tempo de execucao: %d", p->tempoExecucao,
           "Tempo de termino: %d", p->tempoTermino);
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
    fila->head = fila->head->ant;
    fila->tam--;

    return p;
}

void imprimirFila(Fila *fila) {
    Processo *p_atual = fila->head;

    printf("FILA: ");
    while(p_atual != NULL) {
        printf("%d | ", p_atual->pid);
        p_atual = p_atual->ant;
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