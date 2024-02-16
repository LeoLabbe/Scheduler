#include "header.h"
#include "process.h"


typedef enum{
    Disco,
    Impressora,
    Fita
} E_S;

typedef enum{
    
    Executando,
    Pronto,
    Encerrado,
    Bloqueado,
    Não_Vivo

} Estado;

typedef enum{
    LOW,
    HIGH
} Prioridade;


typedef struct Processo{
    int tempoCPU;
    Prioridade prioridade;
    int pid;
    int ppid; 
    Estado estado;
    int tempoChegada;
    int tempoExecucao;
    int tempoTermino;
    Processo* prox;
    Processo* ant;
} Processo;

typedef struct Processo_ES{
    E_S* tipoES;
    int* tempoES;
    int quantES;
    Prioridade prioridade;

} Processo_ES;

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