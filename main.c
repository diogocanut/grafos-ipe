#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

int main()
{
    grafo *G = cria_grafo(5);
    preenche_G_lendo_arquivo(G);
    printf("Hello world!\n");

    return 0;
}
