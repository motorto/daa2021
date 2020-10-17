#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include <assert.h>

void binarySearch(int* lista,int low,int high, int key){ 
	/* este bsearch garante-nos que o low , vai estar no primeiro valor >= key 
		 restando calcular as diferencas de v[low] - key 
	*/
	while (low < high) {
		int middle = low + (high-low) / 2;
		if (lista[middle] >= key) high=middle;
		else	low=middle+1;
	}

	if(lista[low] - key == 0)	printf("%d\n",lista[low]);
	else if(abs(key - lista[low-1]) == abs(lista[low] - key)) printf("%d %d\n",lista[low-1] , lista[low] );
	else	printf("%d\n", abs(lista[low] - key) < abs(key - lista[low-1]) ? lista[low] : lista[low-1]);
}

int* sums(int* a,int n,int somaSize){
	int* b=malloc(sizeof(int) * somaSize);
	int pos=0;
	for (int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			b[pos++]=a[i]+a[j];

	b[pos++]=INT_MIN/2;
	b[pos++]=INT_MAX/2;

	return b;
}

int compInt (const void* p1, const void* p2){
	int* a = (int*) p1;
	int* b = (int*) p2;
	return *a - *b;
}

int main() {
	int n,q;
	scanf("%d",&n);
	int S[n];
	const int somaSize = (n * (n - 1) / 2) + 2; // combinacoes de n 2 a 2   +2 por causa das sentinelas;
	for(int i=0;i<n;i++)
		scanf("%d",&S[i]);

	int* somas = sums(S,n,somaSize);
	qsort(somas, somaSize, sizeof(int), compInt);

	scanf("%d",&q);
	int pergunta;
	for(int i=0;i<q;i++){
		scanf("%d",&pergunta);
		binarySearch(somas, 0, somaSize-1, pergunta);
	}

	return 0;
}
