#include <cstdio>
#include <iostream>
#include <climits>
#include <list>
#include <set>

using namespace std;

#define MAX 1000 // Maxima quantidade de nos
string arrayNomes[MAX];
int indiceNomes=0;

typedef struct {
  list<pair<int, double>> adj;  // Lista de adjacencias
  bool visited;              // No ja foi visitado?
  double distance;              // Distancia ao no origem da pesquisa
} Node;

// Classe que representa um grafo
typedef struct {
  int n;           // Numero de nos do grafo
  Node nodes[MAX]; // Array para conter os nos
} Graph;

void addLink(Graph *g, int a, int b, double c) {
  g->nodes[a].adj.push_back({b,c});
}

// Algoritmo de Dijkstra
void dijkstra(Graph *g, int s) {

  //Inicializar nos como nao visitados e com distancia infinita
  for (int i=1; i<=g->n; i++) {
    g->nodes[i].distance = INT_MAX;
    g->nodes[i].visited  = false;
  }

  // Inicializar "fila" com no origem
  g->nodes[s].distance = 0;
  set<pair<double,int>> q; // By "default" um par e comparado pelo primeiro elemento
  q.insert({0, s});      // Criar um par (dist=0, no=s)

  // Ciclo principal do Dijkstra
  while (!q.empty()) {

    // Retirar no com menor distancia (o "primeiro" do set, que e uma BST)
    int u = q.begin()->second;
    q.erase(q.begin());
    g->nodes[u].visited = true;
    // printf("%d [dist=%lf]\n", u, g->nodes[u].distance);

    // Relaxar arestas do no retirado
    for (auto edge : g->nodes[u].adj) {
      int v = edge.first;
      double cost = edge.second;
      if (!g->nodes[v].visited && g->nodes[u].distance + cost < g->nodes[v].distance) {
        q.erase({g->nodes[v].distance, v});  // Apagar do set
        g->nodes[v].distance = g->nodes[u].distance + cost;
        q.insert({g->nodes[v].distance, v}); // Inserir com nova (e menor) distancia
      }
    }
  }
}

int find(string a) {
  for (int i = 0 ; i < indiceNomes ; i++) {
    if (arrayNomes[i] == a ) 
      return i;
  }
  arrayNomes[indiceNomes++] = a;
  return indiceNomes-1;
}


int main () {
  Graph *g = new Graph;
  int n,e; double tmpValue;
  string tmp1,tmp2;
  cin >> n >> e;
  g->n = n;
  cin >> tmp1 >> tmp2;
  find(tmp1); find(tmp2);
  for (int i = 0; i<e;i++){
    cin >> tmp1 >> tmp2 >> tmpValue;
    addLink(g, find(tmp1),find(tmp2),tmpValue);
    addLink(g, find(tmp2),find(tmp1),tmpValue);
    // cout << tmp1 << " " <<  tmp2 << " " <<  tmpValue << " " << indiceNomes << endl;
  }

  dijkstra(g,0);
  printf("%.1lf\n",g->nodes[1].distance);

  return 0;
}
