#include<stdio.h>


long long cache[1000][1000];

enum BOOL {FALSE,TRUE,OUT};

long long max(int a,int b){
	if (a>b) return a;
	return b;
}

long long solve(int size , int v[size][size],int i,int j){
	if (v[i][j] == FALSE ) return 0;
	if (i==size-1) return 1;
	if (cache[i][j] == -1)  cache[i][j] = solve(size,v,i+1,j) + solve(size,v,i+1,j+1);
	return cache[i][j];
}

int main()
{
	int n;
	scanf("%d",&n);
	int lista[n][n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			lista[i][j] = OUT;

	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++){
			lista[i][j] = TRUE;
			cache[i][j] = -1 ;
		}

	int pTortas;
	scanf("%d",&pTortas);
	for (int i=0;i<pTortas;i++) {
		int c , p;
		scanf("%d %d",&c,&p);
		lista[n-c][p-1] = FALSE; // por na posicao certa
	}
	printf("%lld\n",solve(n,lista,0,0));

	return 0;
}
