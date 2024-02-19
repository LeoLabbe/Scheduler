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


void roundRobin(Fila* processos);
int executaProcesso(Filas* Fila, int tempoExecucao);
int getQuantRestanteProcessos(Filas* filas, Fila* Processos);
Filas* iniciaFilas();
void checaChegadaDeProcesso(Fila* processos ,Filas* filas, int tempoExecucao);
bool getProcessoparaExec(Filas* filas, Processo** processoExec);
bool checaEntradaES(Processo* processoExec);
void trocaParaES(Fila* fila, Fila* ES);
void atualizaES(Filas* filas, int tempExecAtual);
void trocaESparaExec(Filas* filas, int pid);
bool trocaTerminadoOuES(Filas* filas, Processo* processoParaExec);
bool checaFim(Processo* processo);


