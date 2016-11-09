#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

int main()
{
    //modificar nomes das funcoes para camelCase.

    grafo *G;
    G = cria_e_preenche_G_lendo_arquivo();
    printf("num: %d str: %s pos_x: %d pos_y: %d\n", G->lista[0]->numero, G->lista[0]->nome, G->lista[0]->pos_x, G->lista[0]->pos_y);
    preenche_arestas_lendo_arquivo(G);
    printf("\n\n%d", G->lista[0]->prox->prox->peso);
    printf("\n%d", grauVertice(G,0));
    printf("\n%d", ehAdjacente(G,1,0));
    return 0;
}
