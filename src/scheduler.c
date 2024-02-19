#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "../include/processo.h"




Filas* iniciaFilas(){

	Filas* novasFilas = (Filas*) malloc(sizeof(Filas));

	novasFilas->Alta = criaFila();
	novasFilas->Baixa = criaFila();
	novasFilas->ES = criaFila();
	novasFilas->Terminados = criaFila();

	return novasFilas;
}


void checaChegadaDeProcesso(Fila* processos ,Filas* filas, int tempoExecucao){

	Processo* aux = processos -> head;
	Processo* temp;

	while(aux){
		if(aux->tempoChegada <= tempoExecucao){
			temp = aux -> prox;
			aux -> estado = PRONTO;
			trocaFila(processos, filas->Alta);

			aux = temp;
			continue;
		}

	break;

	}


}

bool getProcessoparaExec(Filas* filas, Processo** processoExec){

	Fila* alta = filas->Alta;
	Fila* baixa = filas->Baixa;
	bool filaAlta = false;
	if(alta->tam){
		*processoExec = alta->head;
		filaAlta = true;
	}
	else if(baixa->tam){
		*processoExec = baixa->head;
	}
	return filaAlta;
}

bool checaEntradaES(Processo* processoExec){

	int esTerminado = processoExec -> esTerminado;
	int esTotal = processoExec -> listaES ->totalES;
	int* tempoES = processoExec -> listaES -> tempoES;
	int tempoExecucao = processoExec -> tempoExecucao;

	if(!(esTerminado == esTotal)){
		if(tempoES[esTerminado == tempoExecucao])
			return true;
	}

	return false;

}

void trocaParaES(Fila* fila, Fila* ES){

	Processo* processo = fila->head;
	int esTerminado = processo ->esTerminado;
	TipoES* tipoES = processo -> listaES -> tipoES;
	
	processo -> estado = BLOQUEADO;

	switch (tipoES[esTerminado])
	{
	case DISCO:
		processo ->tempoAteExec + DISCO_TEMPO;
		break;

	case FITA:
		processo -> tempoAteExec + FITA_TEMPO;
		break;
	
	case IMPRESSORA:
		processo -> tempoAteExec + IMPRESSORA_TEMPO;
		break;
	
	}

	trocaFila(fila, ES);
}


void atualizaES(Filas* filas, int tempExecAtual){
	Fila* ES = filas ->ES;
	Processo* aux = ES ->head;

	while (aux)
	{
		aux -> tempoAteExec--;

	if(aux ->tempoAteExec == 0){
		trocaESparaExec(filas, aux ->pid);
	}

	aux = aux -> prox;
	}
	


}

void trocaESparaExec(Filas* filas, int pid){
	Fila* alta = filas -> Alta;
	Fila* baixa = filas -> Baixa;
	Fila* ES = filas -> ES;
	Processo* aux = ES -> head;
	TipoES* tipoES;
	int esTerminado;


	while(aux){

		if(aux -> pid == pid) {
			tipoES = aux ->listaES ->tipoES;
			esTerminado = aux -> esTerminado;

			aux -> tempoAteExec = 0;
			aux -> estado = PRONTO;

			switch (tipoES[esTerminado]){
				case DISCO:
				aux ->prioridade = BAIXA;
				troca(ES,baixa);
			break;

				case FITA:
				case IMPRESSORA:
				aux ->prioridade = ALTA;
				troca(ES,alta);
			break;
			}

			aux ->esTerminado++;
			break;
		}

		aux = aux ->prox;
	}
}


bool trocaTerminadoOuES(Filas* filas, Processo* processoParaExec){

	Fila* alta = filas -> Alta;
	Fila* baixa = filas -> Baixa;
	Fila* ES = filas -> ES;
	Fila* terminados = filas ->Terminados;
	bool prioridadeAlta = processoParaExec -> prioridade == ALTA;
	int pid = processoParaExec -> pid;

	if(checaFim(processoParaExec)){

		processoParaExec ->estado = TERMINADO;

		if(prioridadeAlta)
			trocaFila(alta,terminados);
		else
			trocaFila(baixa,terminados);

		return true;
	}


	if(checaEntradaES(processoParaExec)){
		if(prioridadeAlta)
			trocaFila(alta,ES);
		else
			trocaFila(baixa,ES);

	return true;
	}

	return false;

}

bool checaFim(Processo* processo){
	return (processo ->tempoExecucao == processo ->tempoCPU) && (processo ->esTerminado == processo ->listaES->totalES);
}

int getQuantRestanteProcessos(Filas* filas, Fila* Processos) {
	return filas -> Alta -> tam +
		filas -> Baixa -> tam +
		filas -> ES -> tam +
		Processos -> tam;
}


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
