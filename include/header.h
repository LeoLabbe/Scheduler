#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "processo.h"


#define QUANTUM 4
#define MAX_PROCESS 10
#define MAX_TIME 6000
#define DISCO_TEMPO 3      
#define FITA_TEMPO 5      
#define IMPRESSORA_TEMPO 10

typedef struct filas {
	Fila* Alta;
	Fila* Baixa;
	Fila* ES;
	Fila* Terminados;
}Filas;


int executaProcesso(Fila*, Filas*, int);
void roundRobin(Fila*);
int getQuantRestanteProcessos(Filas*, Fila*);
Filas* iniciaFilas();
void checaChegadaDeProcesso(Fila*  ,Filas*, int);
bool getProcessoparaExec(Filas* , Processo**);
bool checaEntradaES(Processo* );
void trocaParaES(Fila*, Fila* );
void atualizaES(Filas* , int );
void trocaESparaExec(Filas* , int );
bool trocaTerminadoOuES(Filas*, Processo*);
bool checaFim(Processo*);


