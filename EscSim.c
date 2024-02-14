#include <stdio.h>  
#include <stdlib.h>


typedef struct Escalonador{
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
} Escalonador;

typedef struct Fila{
    Escalonador *escalonador;
    struct Fila *prox;
} Fila;

Fila* criaLista(){
    Fila *novo = (Fila*)malloc(sizeof(Fila));
    novo->escalonador = NULL;
    novo->prox = NULL;
    return novo;
}

int FilaVazia(Fila *fila){
    return (fila->prox == NULL);
};

void push(Fila *fila, Processo *processo) {
    Fila prox -> processo;
}


int main (){


}