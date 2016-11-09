
struct Aresta{
    int peso;
    int V2;
    struct Aresta* prox;
};typedef struct Aresta aresta;

struct Vertice{
	int numero, pos_x, pos_y;
	char nome[20];
	aresta* prox;
};typedef struct Vertice vertice;

struct Grafo{
    int qtde_vertices, qtde_arestas;
    int *grau;
    vertice **lista;
};typedef struct Grafo grafo;

grafo *cria_grafo(int nro_vertices);
grafo *cria_e_preenche_G_lendo_arquivo();
aresta *cria_aresta(int P, int V2);
int percorre_verifica_cria_aresta(grafo *G, int V1, int V2, int P);
void insere_aresta(grafo *G, int V1, int V2, int P);
void preenche_arestas_lendo_arquivo(grafo *G);
int numVertices(grafo *G);
int busca(grafo *G, int V1, int V2);
int ehAdjacente(grafo *G, int V1, int V2);
