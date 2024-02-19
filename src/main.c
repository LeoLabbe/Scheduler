#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "../include/header.h"
#include "../include/processo.h"
#include "processo.c"
#include "scheduler.c"

int main (){


Fila* filaProcesso;
Processo** Vprocesso;
TipoES* VES;
int* TempoES;

Vprocesso = (Processo**) malloc(sizeof(Processo*) * 3);
VES = (TipoES*) malloc(sizeof(TipoES) * 2);
TempoES = (int*) malloc(sizeof(int) * 2);

VES[0] = DISCO;
VES[1] = IMPRESSORA;

TempoES[0] = 1;
TempoES[1] = 3;


Vprocesso[0] = criarProcesso(1, 10, 0, VES, TempoES, 2);
Vprocesso[1] = criarProcesso(2, 10, 1, VES, TempoES, 2);
Vprocesso[2] = criarProcesso(3, 10, 2, VES, TempoES, 2);

filaProcesso = criaFila();

roundRobin(filaProcesso);

imprimirFila("Processos", filaProcesso);











//ENTRADA E SAÍDA BASEADO NA PREFERENCIA DO USUARIO
//LÓGICA AINDA INCOMPLETA

/*

int i,n, id, tcpu, tchegada, nES, tES;
printf("Diga o numero de processos (MAX 10): ");
scanf("%d", &n);

printf("\nDigite as infos dos processos:\n");

for (i = 0; i < n; i++) {
    printf("\nProcesso %d:\n", i);

    printf("Id: ");
    scanf("%d", &id);

    printf("Tempo de Uso da CPU: ");
    scanf("%d", &tcpu);

    printf("Tempo de chegada: ");
    scanf("%d", &tchegada);

    printf("Digite numero de operacoes de E/S (se nenhuma, digite 0):");
    scanf("%d", &nES);

    if(nES > 0){

        for(int j = 0; j<nES; j++){
        printf("Digite o tipo da E/S %d assim -> DISCO, FITA OU IMPRESSORA:", j + 1);
        scanf("%s", &tipo);

        printf("Digite o tempo de chegada dessa E/S:");
        scanf("%d", &tchegada);
        }
    }


    Vprocesso[i] = criarProcesso(id, tcpu, tchegada); */
 


return 0;



};