// Agradecimento ao Ricardo Miguel 2017.....
// Exemplo de pesquisa em largura (BFS) num grafo nao dirigido
// (codigo adaptado do codigo em Java feito na teorica)
// (inclui calculo de distancias)
// (esta versao nao tem "garbage collection", ou seja, nao limpa no final a memoria)

#include <iostream>
#include <list>
#include <climits>
#include <set>
#define MAX 1505

using namespace std;

int n;
int matriz[MAX][MAX];

// Classe que representa um no
class Node {
public:
  list<int> adj;  // Lista de adjacencias
  bool visited;   // Valor booleano que indica se foi visitado numa pesquisa
  int distance;   // Distancia ao no origem da pesquisa

  Node() {        // Nao e preciso mais nada porque adj ja foi criada
  };              // mas queria mostrar que em C++ tambem existem construtores
};

// Classe que representa um grafo
class Graph {
public:
  int n;          // Numero de nos do grafo
  Node *nodes;    // Array para conter os nos

  Graph(int n) {
    this->n = n;
    nodes = new Node[n+1];  // +1 se os comecam em 1 ao inves de 0
  }

  void addLink(int a, int b) {
    nodes[a].adj.push_back(b);
    nodes[b].adj.push_back(a);
  }
  
  void bfs(int v) {
    list<int> q;
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    
    q.push_back(v);
    nodes[v].visited = true;
    nodes[v].distance = 0;
    matriz[v][v] = 0;

    while (q.size() > 0) {
      int u = q.front(); q.pop_front();
      for (auto w : nodes[u].adj)
      	if (!nodes[w].visited) {
      	  q.push_back(w);
      	  nodes[w].visited  = true;
      	  nodes[w].distance = nodes[u].distance + 1;
          matriz[v][w] = nodes[w].distance;
      	}
    }
  }
};

int excentricidade(int v){
  int max=0;
  for(int i=1; i<=n; i++){
    if(max<=matriz[v][i]) max = matriz[v][i];
  }
  return max;
}


int main() {
  int e, a, b;
  
  set<int> centrais;
  set<int> perifericos;

  cin >> n;
  Graph *g = new Graph(n);
  cin >> e;
  for (int i=0; i<e; i++) {
    cin >> a >> b;
    g->addLink(a, b);
  }

  // Pesquisa em largura a partir do no 1
  for(int i=1; i<=n; i++){
    g->bfs(i);
  }

  int diametro = 0;
  int extr = 0;
  int raio = INT_MAX;

  for(int i=1; i<=n; i++){
    extr = excentricidade(i);
    if(diametro<=extr) diametro = extr;
    if(raio >= extr) raio = extr;
  }

  cout << diametro << '\n';
  cout << raio << '\n';
  for(int i=1; i<=n; i++){
    extr = excentricidade(i);
    if(raio == extr) centrais.insert(i);
    if(diametro==extr) perifericos.insert(i);
  }

  int size = centrais.size();
  int incr=0;

  for(int i: centrais){
    incr++;
    if(size==incr) cout << i;
    else cout << i << " ";
  }
  putchar('\n');

  size = perifericos.size();
  incr=0;
  for(int i: perifericos){
    incr++;
    if(size==incr) cout << i;
    else cout << i << " ";
  }
  putchar('\n');

  return 0;
}
