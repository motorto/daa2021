// Agradecimentos a Lara Moreira up201905281 por me ter epxlicado a solucao

#include <cstdio>
#include <climits>
#include <list>
#include <set>

using namespace std;

#define MAX 1000 // Maxima quantidade de nos
 
typedef struct {
  list<pair<int, int>> adj;  // Lista de adjacencias
  // bool visited;              // No ja foi visitado?
  int distance;              // Distancia ao no origem da pesquisa
} Node;

// Classe que representa um grafo
typedef struct {
  int n;           // Numero de nos do grafo
  Node nodes[MAX]; // Array para conter os nos
} Graph;

void addLink(Graph *g, int a, int b, int c) {
    g->nodes[a].adj.push_back({b,c});
}

// algoritmo de bellman ford

bool bellman_ford(Graph *g, int s) {
    
  //Inicializar nos como nao visitados e com distancia infinita
  for (int i = 0; i < g->n; i++) {
    g->nodes[i].distance = INT_MAX/2;
  }
    
  // Inicializar "fila" com no origem
  g->nodes[s].distance = 0;
    
  for (int i = 0; i < g->n; i++) {
    for(int j = 0; j < g->n; j++){
      for (auto edge : g->nodes[j].adj) {
 int v = edge.first;
 int cost = edge.second;
 if (g->nodes[j].distance + cost < g->nodes[v].distance) {
   g->nodes[v].distance = g->nodes[j].distance + cost;
 }
      }
    }
  }
  for(int i = 0; i < g->n; i++){
    for(auto e: g->nodes[i].adj){
      int V = e.first;
      int COST = e.second;
      if(g->nodes[i].distance + COST < g->nodes[V].distance)return true;
    }
  }
  return false;
}

int main() {
  int C, e, a, b, c;
  scanf("%d", &C);
  for(int i = 0; i < C; i++){
    Graph *g = new Graph;
    scanf("%d", &g->n);
    scanf("%d", &e);
    for(int j = 0; j < e; j++){
      scanf("%d %d %d", &a, &b, &c);
      addLink(g,a,b,c);
    }
    if(bellman_ford(g,0))printf("possivel\n");
    else printf("impossivel\n");
  }

  return 0;
}
