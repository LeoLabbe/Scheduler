#pragma once


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
    TipoES* tipoES;
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
    int tempoAteExec;
    int tempoTermino;
    int tempoTerminoES;
    int esTerminado;
    struct Processo *prox;
    struct Processo *ant;
    ProcessoES* listaES;
} Processo;

typedef struct Fila{
    Processo *head;
    Processo *tail;
    int tam;
} Fila;

Processo* criarProcesso(int, int , int , TipoES* , int* , int );
void imprimirProcesso(Processo *);
void liberarProcesso(Processo *);

Fila* criaFila();
int FilaVazia(Fila *);
void push(Fila *, Processo* );
void pop(Fila *);
void imprimirFila(const char* , Fila *);
void liberarFila(Fila *);
void trocaFila(Fila *, Fila *);
