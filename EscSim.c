#include <stdio.h>  
#include <stdlib.h>


typedef struct Processo{
    int tempo;
    int prioridade;
    int id;
    int estado;
    int tempoChegada;
    int tempoExecucao;
    int tempoEspera;
    int tempoResposta;
    int tempoRetorno;
    int tempoFinal;
    int tempoRestante;
    int tempoInicio;
    int tempoFim;
    int tempoTotal;
    int tempoBloqueado
} Processo;

typedef struct Fila{
    Processo *data;
    struct Fila *prox;
} Fila;

Fila* criaLista(){
    Fila *novo = (Fila*)malloc(sizeof(Fila));
    novo->data = NULL;
    novo->prox = NULL;
    return novo;
}

int FilaVazia(Fila *fila){
    if (fila->prox == NULL){
        return 1;
    } else {
        return 0;
    }
};

void push(Fila *fila, Processo* processo) {
    if (FilaVazia(fila) == 1){
        Fila *novo = (Fila*)malloc(sizeof(Fila));
        novo->data = processo;
        novo->prox = NULL;
    }
        else{
            Fila *novo = (Fila*)malloc(sizeof(Fila));
            novo->data = processo;
            novo->prox = fila-> prox;
            fila->prox = novo;
        }
};


int main (){


};