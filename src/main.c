#include "../include/header.h"
#include "../include/Processo/processo.h"
#include "../include/Processo/processo.c"

int main (){

int i,n, id, tcpu, tchegada;
Processo* Vprocesso[10];


Fila* alta = criaFila();
Fila* baixa = criaFila();
Fila* ES = criaFila();



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

    Vprocesso[i] = criarProcesso(id, tcpu, tchegada);
    push(alta, Vprocesso[i]);
}

imprimirFila(alta);

return 0;



};