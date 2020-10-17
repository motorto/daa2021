#include <stdio.h>
#include <stdlib.h>

int possivel(int *v,int n,int middle,int partitions){ 
  /*
     Percorre o array e verifica se é possivel
     criar K particoes todas com a soma <= MIDDLE
  */
  int tmp = 1; //contador de particoes
  int sum = 0; 
  for (int i=0; i<n;i++){
    sum+=v[i];
    if(sum > middle){
      sum = 0;
      i--;
      tmp++;
    }
    if(tmp > partitions){
      return 0;
    }
  }
  return 1;
}

int binarySearch(int* v ,int size, int low , int high,int partitions)
{
  /*
     Aplica pesquisa binary para todos os valores possiveis
     de 1 ate ao somatorio dos valores de v 
     Para descobrir o menor valor possivel para K particoes
  */
  while (low < high) {
    int middle = low + (high - low) / 2;
    if (possivel(v,size,middle,partitions) == 1){
      high = middle;
    }
    else
      low = middle + 1;
  }
  return low;
}

int somatorio(int* v,int n)
{
  int s = 0;
  for (int i=0;i<n;i++){
    s += v[i];
  }
  return s;
}

int main()
{
  int n, q;
  scanf("%d", &n);

  int lista[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &lista[i]);

  scanf("%d", &q);
  int p; //particoes
  for (int i = 0; i < q; i++){
    scanf("%d", &p);
    printf("%d\n", binarySearch(lista,n,1, somatorio(lista,n), p));
  }

  return 0;
}
