
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
void preenche_G_lendo_arquivo(grafo *G);