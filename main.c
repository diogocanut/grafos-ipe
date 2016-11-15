#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

int main()
{
    //modificar nomes das funcoes para camelCase.
    //sempre releia o trabalho para atender a todos os requisitos
    int escolha, V1, V2;
    grafo *G;
    printf("Realizando leitura do grafo\n");
    G = cria_e_preenche_G_lendo_arquivo();
    preenche_arestas_lendo_arquivo(G);
    sleep(3);

    do{
    printf("\n\n1- Consultar numero de verticies que compoe o grafo\n");
    printf("2- Checar o grau de um dado vertice\n");
    printf("3- Checar adjacencia entre 2 vertices\n");
    printf("4- Sair\n\n");
    scanf("%d", &escolha);

        switch(escolha){
        case 1:
            printf("A quantidade de vertices e: %d\n", numVertices(G));
            break;

        case 2:
            printf("Digite qual vertice deseja checar\n\n");;
            scanf("%d", &V1);
            printf("O grau do vertice %d e %d\n", V1, grauVertice(G,V1));
            break;

        case 3:
            printf("Digite os vertices V1 e V2:\n\n");
            scanf("%d %d", &V1, &V2);
            if(ehAdjacente(G,V1,V2)==1){
                printf("Sao adjancentes\n");
            }
            else printf("Nao sao adjacentes\n");
        }

    }while(escolha!=4);





    return 0;
}
