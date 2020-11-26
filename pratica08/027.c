#include<stdio.h>
#include<stdbool.h>

#define MAX  51
#define NaoVisitado 0
#define AZUL 1
#define VERMELHO 2

int nos,arestas,cor;
bool adj[MAX][MAX]; // matrix de adjacencias
int colored[MAX]; // matrix "pintada"

void reset(int n){
  for (int i = 0 ; i < n ; i++){
    for (int j = 0 ; j < n ; j++)
      adj[i][j] = false;
    colored[i] = NaoVisitado;
  }
}

bool paint(int x,int cor)
{
  int novaCor = ( cor == AZUL ) ? VERMELHO : AZUL ;
  if (colored[x] != NaoVisitado ){ 
    if(colored[x] != novaCor) return false;
    return true;
  }
  if (colored[x] == NaoVisitado) {
    colored[x] = novaCor;
    for (int i=0;i<nos;i++) {
      if ( adj[x][i] ) 
        if ( !paint(i,novaCor) ) return false;
     }
  }
  return true;
}

int main()
{
  int cases=0;
  scanf("%d",&cases);

  for (int a=0;a<cases;a++)
  {
  int tmpX,tmpY;
  scanf("%d%d",&nos,&arestas);

  for (int i=0;i<arestas;i++)
  {
    scanf("%d %d",&tmpY,&tmpX);
    tmpY--;
    tmpX--;
    adj[tmpY][tmpX] = true ;
    adj[tmpX][tmpY] = true ;
  }

  bool answer = paint(0,AZUL);

  if (answer) printf("sim\n");
  else printf("nao\n");

  reset(nos);
  }

  return 0;
}
