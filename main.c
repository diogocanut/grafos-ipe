#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

int main()
{
    int x;
    grafo *G = cria_grafo(5);
    preenche_G_lendo_arquivo(G);
    printf("num: %d str: %s pos_x: %d pos_y: %d\n", G->lista[0]->numero, G->lista[0]->nome, G->lista[0]->pos_x, G->lista[0]->pos_y);
    preenche_arestas_lendo_arquivo(G);
    return 0;
}
