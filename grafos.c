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

grafo *cria_e_preenche_G_lendo_arquivo(){
    FILE *arq;
    char url[]="/home/knute/Documentos/C/grafos-ipe/vertices.txt";
    char str[80];
    char ch;


    arq=fopen(url, "r");
    if(arq==NULL){
        printf("Erro com o arquivo dos vertices, favor verificar\n");
        return NULL;
    }
    else{
        int numero, pos_x, pos_y, i=0, linha=1;
        char ch1, ch2, ch3;

        while(!feof(arq)){
            ch = fgetc(arq);
            if(ch == '\n'){
                linha++;
                printf("%d", linha);
                }
            }
        grafo *G = cria_grafo(linha);

        while(EOF != fscanf(arq, "%d%c %s%c %d%c %d", &numero, &ch1, str, &ch2, &pos_x, &ch3, &pos_y )){
            G->lista[i]->numero = numero;
            strcpy(G->lista[i]->nome, str);
            G->lista[i]->pos_x = pos_x;
            G->lista[i]->pos_y = pos_y;
            G->qtde_vertices++;
            i++;
            }

        return G;
    }

}

aresta *cria_aresta(int P, int V2){
    aresta *nova = (aresta *)malloc(sizeof(aresta));
    if(nova==NULL){
        free(nova);
        return NULL;
    }
    nova->peso=P;
    nova->V2 = V2;
    nova->prox=NULL;
    return nova;
}


int percorre_verifica_cria_aresta(grafo *G, int V1, int V2, int P){

    aresta *aux;
    aux = G->lista[V1]->prox;

    if(aux->V2==V2){
        return 1;
    }
    while(aux->prox!=NULL){
        if(aux->V2==V2){
        return 1;
        }
        aux = aux->prox;

    }
    aux->prox = cria_aresta(P, V2);
    return 0;
}

void insere_aresta(grafo *G, int V1, int V2, int P){
    G->grau[V1]++;
    if(G->lista[V1]->prox==NULL){
        G->lista[V1]->prox = cria_aresta(P, V2);

    }
    else{
        int x;
        x = percorre_verifica_cria_aresta(G,V1,V2,P);
        if(x==1){
            printf("Aresta ja existente, insercao nao realizada\n");
            G->grau[V1]--;
    }
  }
}

void preenche_arestas_lendo_arquivo(grafo *G){
    FILE *arq1;
    char url[]="/home/knute/Documentos/C/grafos-ipe/arestas.txt";

    arq1=fopen(url, "r");
    if(arq1==NULL)
        printf("Erro com o arquivo dos vertices, favor verificar\n");
    else{
        int V1, V2, P;
           while(EOF != fscanf(arq1, "%d %d %d", &V1, &V2, &P)){
                printf("v1=%d v2= %d v3= %d\n" ,V1, V2, P);
                insere_aresta(G,V1,V2,P);
                G->qtde_arestas++;
        }

    }
}

int numVertices(grafo *G){
    return G->qtde_vertices;
}


int grauVertice(grafo *G, int V){
    return G->grau[V];
}


int busca(grafo *G, int V1, int V2){
    if(G->grau[V1]==0) return 0;

    aresta *aux;
    aux = G->lista[V1]->prox;

    if(aux->V2==V2){
        return 1;
    }
    while(aux->prox!=NULL){
        if(aux->V2==V2){
        return 1;
        }
        aux = aux->prox;

    }
    return 0;
}


int ehAdjacente(grafo *G, int V1, int V2){
    int x,y;
    x = busca(G,V1,V2);
    y = busca(G,V2,V1);
    if(x==1||y==1) return 1;
    else return 0;

}

