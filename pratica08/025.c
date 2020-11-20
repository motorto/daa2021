#include <stdio.h>
#include <stdbool.h>

#define MAX 105

int n;              // Numero de nos do grafo
bool adj[MAX][MAX]; // Matriz de adjacencias
bool visited[MAX];  // Que nos ja foram visitados?

void dfs(int v) {
  visited[v] = true;
  for (int i=1; i<=n; i++)
    if (adj[v][i] && !visited[i])
      dfs(i);
}

int main() {
  int edges, a, b;
 int count=0;

  scanf("%d", &n);
  scanf("%d", &edges);
  for (int i=0; i<edges; i++) {
    scanf("%d %d", &a, &b);
    adj[a][b] = adj[b][a] = true;
  }

 for (int i=1;i<=n;i++){
  if(!visited[i]){
   count++;
    dfs(i); // Pesquisa em profundidade a partir do no 1
  }
 }
  printf("%d\n",count);
  return 0;
}
