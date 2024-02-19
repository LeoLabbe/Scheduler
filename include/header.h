#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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


int executaProcesso(Filas* Fila, int tempoExecucao);
int getQuantRestanteProcessos(Filas* filas, Fila* Processos);
Filas* iniciaFilas();