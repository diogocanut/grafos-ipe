#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafos.h"

grafo *cria_grafo(int nro_vertices){
    if(nro_vertices<0) return NULL;

    grafo *G = (grafo *) malloc(sizeof(grafo));
    if(G == NULL) return NULL;

    G->qtde_vertices = nro_vertices;
    G->qtde_arestas = 0;

    G->grau = (int *) calloc(nro_vertices, sizeof(int));
    if(G->grau == NULL){
        free(G);
        return NULL;
        }

    G->lista = (vertice **) malloc(nro_vertices*sizeof(vertice*));
    int i,k;
    for(i=0; i<nro_vertices; i++) {
        G->lista[i] = (vertice*) calloc(1,sizeof(vertice));
        G->lista[i]->prox=NULL;

        if (G->lista[i]  == NULL){
            for (k=0; k<i; k++)
                  free(G->lista[k]);
            free(G) ;
            return NULL;
       }
   }


    if(G->lista == NULL){
        free(G->grau); free(G); return NULL;
    }

    return G;

}

void preenche_G_lendo_arquivo(grafo *G){
    FILE *arq;
    char url[]="/home/knute/Documentos/C/grafos-ipe/vertices.txt";
    char ch;
    char str[80];
    char *p;


    arq=fopen(url, "r");
    if(arq==NULL)
        printf("Erro com o arquivo dos vertices, favor verificar\n");
    else{
        int i = 0, k = 0;
        while((ch=fgetc(arq))!=EOF){
            str[i] = ch;
            int j=0;
            if(ch == '\n'){
                str[i+1]='\0';
                i = 0;
                printf("%s", str);
                p = strtok(str, ";");

                while(p!=NULL){
                    printf("%s\n", p);
                    if (j==0){ G->lista[k]->numero = (int)p; }
                    printf("aoepoakea --- %d", G->lista[k]->numero);
                    if (j==1) strcpy(G->lista[k]->nome, p);
                    j++;
                    k++;

                    p = strtok(NULL, str);
                }

            }
            i++;



          }
        }
    }



int insere_aresta(grafo *G, int V1, int V2, int P){
    if(!(G!=NULL)&&(V1>0)&&(V2>0)){ return -1; }


    aresta *aux = G->lista[V1]->prox;
    if(aux->V2==V2) return 1;

    if(G->lista[V1]->prox!=NULL){
        while(aux!=NULL){
            if(aux->V2==V2) return 1;
            aux=aux->prox;
        }

    aresta *nova = (aresta *)malloc(sizeof(aresta));
    /* falta aqui test if , att qtde arestas, grau*/
    nova->peso=P;
    nova->prox=NULL;
    aux=nova;
    return 0;

    }

}
