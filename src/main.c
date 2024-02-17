#include "../include/header.h"

int main (){

int i,n, id, tcpu, tchegada;

Fila* alta = criaFila();
Fila* baixa = criaFila();
Fila* ES = criaFila();



printf("Diga o número de processos(MAX 10):");
scanf("%d", &n);

printf("\nDigite as informações dos processos:");

for(i=0; i < n ; i++){
printf("Processo %d", i);

printf("Id:");
scanf("%d", &id);

printf("Tempo de Uso da CPU:");
scanf("%d", &tcpu);

printf("Tempo de chegada:");
scanf("%d", &tchegada);

criarProcesso(id, tcpu, tchegada);

}




return 0;
};