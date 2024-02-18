#include <stdio.h>
#include "../include/header.h"
#include "../include/processo.c"

int main (){

int i,n, id, tcpu, tchegada, nES, tES;
Processo* Vprocesso[10];
TipoES* VES[20];
TipoES tipo;

Fila* alta = criaFila("ALTA");
Fila* baixa = criaFila("BAIXA");
Fila* ES = criaFila("ES");



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


    Vprocesso[i] = criarProcesso(id, tcpu, tchegada);
    push(alta, Vprocesso[i]);
    imprimirFila("ALTA",alta);
}


trocaFila(alta, baixa);

imprimirFila("BAIXA",baixa);

return 0;



};