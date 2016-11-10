#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

int main()
{
    //modificar nomes das funcoes para camelCase.
    //sempre releia o trabalho para atender a todos os requisitos
    int escolha;
    grafo *G;
    G = cria_e_preenche_G_lendo_arquivo();
    printf("num: %d str: %s latitude: %d longitude: %d\n", G->lista[0]->numero, G->lista[0]->nome, G->lista[0]->latitude, G->lista[0]->longitude);
    preenche_arestas_lendo_arquivo(G);
    printf("\n\n%d", G->lista[1]->prox->V2);
    printf("\n%d", grauVertice(G,1));
    printf("\n%d", ehAdjacente(G,8,1));
    return 0;
}
