#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "./include/processo.h"



int executaProcesso(Filas* Filas, int tempoExecucao){

int tempExecAtual = 0;
Fila* alta = Filas->Alta;
Fila* baixa = Filas->Baixa;
bool prioridadeAlta, transferido;
Processo* ProcessoExec;

if(alta->tam){
    ProcessoExec = alta->head;
    prioridadeAlta = true;
}else if (baixa->tam){
    ProcessoExec = baixa->head;
}

ProcessoExec->estado = EXECUTANDO;

for(int i = 0; i < QUANTUM; i++) {
		transferido = TerminadoOuES(Filas, ProcessoExec);

		if(transferido) {
			// Write process info if it reached the end of it's life
			
			break;
		}
	    
		// Updates IO queue in real time
		ProcessoExec -> tempoExecucao++;
		tempExecAtual++;

}

};
