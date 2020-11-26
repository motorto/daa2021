#include<stdio.h>
#include<stdbool.h>

#define MAX 101

int linhas,colunas;
char matrix[MAX][MAX];
bool visited[MAX][MAX];

int dfs(int y,int x)
{
  if ( y < 0 || y > linhas || x < 0 || x > colunas) return 0;
  if (visited[y][x]) return 0;
  if (matrix[y][x] == '#'){
    visited[y][x] = true;
    return 1 + dfs(y+1,x-1) + dfs(y+1,x) + dfs(y+1,x+1)
      + dfs(y,x-1) + dfs(y,x+1) + dfs (y-1,x-1) + 
      dfs (y-1,x) + dfs(y-1,x+1);
  }
  return 0;
}

int main(void)
{
  int max,count,cases=0;

  scanf("%d",&cases);
  for(int w=0;w<cases;w++){
    count=0;
    max=0;
    scanf("%d %d", &linhas,&colunas);

    for (int i=0; i<linhas; i++)
      scanf("%s",matrix[i]);

    for (int i=0;i<linhas;i++) 
      for (int j=0;j<colunas;j++) 
        visited[i][j] = false;

    for (int i=0; i<linhas; i++)
      for (int j=0;j<colunas;j++)
        if (matrix[i][j] == '#') {
          count = 0;
          count = dfs(i,j);
          if (count > max) max = count;
        }
    printf ("%d\n",max);
  }
  return 0;
}
