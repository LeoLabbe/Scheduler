#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "../include/processo.h"
#include "../include/header.h"
#include "processo.c"

void roundRobin(Fila* processos){

	int tempExecAtual = 0;

	Filas* filas = iniciaFilas();

	while(getQuantRestanteProcessos(filas, processos) > 0){
		if(processos -> tam > 0){
			checaChegadaDeProcesso(processos, filas, tempExecAtual);

			tempExecAtual += executaProcesso(filas, tempExecAtual);
		}
	}

};

	
int executaProcesso(Filas* Filas, int tempoExecucao){

	int tempoExecAtual = 0;
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
	else{
		atualizaES(Filas, tempoExecucao);
		return 1;
	}


	
	ProcessoExec->estado = EXECUTANDO;

	for(int i = 0; i < QUANTUM; i++) {
		transferido = trocaTerminadoOuES(Filas, ProcessoExec);

		if(transferido) {
			printf("O Processo com id: %d acabou...", ProcessoExec->pid);
		break;
		}
	    ProcessoExec -> tempoExecucao++;
		tempoExecAtual++;
		atualizaES(Filas, tempoExecucao + tempoExecAtual);

		imprimirFila("ALTA PRIORIDADE:", Filas ->Alta );
		imprimirFila("BAIXA PRIORIDADE:", Filas ->Alta );
		imprimirFila("E/S:", Filas ->Alta );
		imprimirFila("TERMINADOS:", Filas ->Alta );
}


	if(prioridadeAlta){
		ProcessoExec -> prioridade = BAIXA;
		trocaFila(alta, baixa);
	}
	else 
		trocaFila(baixa, baixa);

	ProcessoExec ->estado = PRONTO;

	return tempoExecAtual;

}



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
				trocaFila(ES,baixa);
			break;

				case FITA:
				case IMPRESSORA:
				aux ->prioridade = ALTA;
				trocaFila(ES,alta);
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

	if(checaFim(processoParaExec)){

		processoParaExec ->estado = TERMINADO;

		if(prioridadeAlta){
			trocaFila(alta,terminados);
			printf("O processo %d terminou!\n", processoParaExec->pid);
		}
		
		else
		{
			trocaFila(baixa,terminados);
			printf("O processo %d terminou!\n", processoParaExec->pid);
		}

		return true;
	}


	if(checaEntradaES(processoParaExec)){
		if(prioridadeAlta){
			trocaFila(alta,ES);
			printf("O processo %d solicitou E/S\n", processoParaExec->pid);
		}
		else{
			trocaFila(baixa,ES);
			printf("O processo %d solicitou E/S\n", processoParaExec->pid);
		}
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


