// Agradecimento a Lara Moreira up201905281 mais uma vez :(

#include <cstdio>
#include <iostream>

using namespace std;

#define MAX 30

int N;
bool adj[MAX][MAX];
int distancia[MAX][MAX];


void floyd_warshall(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(i == j) distancia[i][j] = 1;
      else if(adj[i][j]) distancia[i][j] = 1;
      else distancia[i][j] = 0;
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      for(int k = 0; k < N; k++){
 if(adj[j][i] && adj[i][k]){
   distancia[j][k] = 1;
   adj[j][k] = true;
 }
      }
    }
  }
}

void imprimir(){
  for(int i = -1; i < N; i++){
    for(int j = -1; j < N; j++){
      if(i == -1){
 if(j == -1)printf(" ");
 else printf(" %c", (char)(j+'A'));
 //if(j != N) printf(" ");
      }
      else if(j == -1){
 printf("%c", (char)(i+'A'));
      }
      else{
        printf(" %d", distancia[i][j]);
 //if(j != N) printf(" ");
      }
    }
    putchar('\n');
  }
}

int main(){
  int k;
  char cidade1, cidade2;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    cin >> cidade1 >> k;
    for(int j = 0; j < k; j++){
      cin >> cidade2;
      adj[cidade1 - 'A'][cidade2 - 'A'] = true;
    }
  }


  floyd_warshall();

  imprimir();
  
  return 0;
}

