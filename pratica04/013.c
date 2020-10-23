#include<stdio.h>
#include<stdlib.h>

struct segmentos {
	int inicio,fim;
};

int compSegmentos( const void* p1, const void* p2){
	/*
		 função para o qsort da biblioteca
	*/
	struct segmentos* a = (struct segmentos*) p1;
	struct segmentos* b = (struct segmentos*) p2;

	if ( a->inicio - b-> inicio == 0 ) {
		int sizeA = a->fim - a->inicio;
		int sizeB = b->fim - b->inicio;
		return sizeA - sizeB;
	}
	return a->inicio - b-> inicio;
}

int findMaior(struct segmentos *lista , int size,int end){ 
	/* 
		 encontra o segmento com o tamanho maior desde
		 o end actual até ao fim do segmento
	*/
	int indice=0 , dif = 0 , biggestDif = 0;
	for(int i=0;i<size;i++){
		if(lista[i].inicio <= end){
			dif = lista[i].fim - end;
			if (dif >= biggestDif){
				biggestDif = dif;
				indice=i;
			}
		}
	}
	return indice;
}

int solve(struct segmentos *lista,int size,int maximo) {
	int count=0,i=0,end=0;
	while(end<maximo){
		i = findMaior(lista,size,end);
		end=lista[i].fim;
		count++;
	}
	return count;
}

int main() {
	int m, n;
	scanf("%d %d", &m, &n);

	struct segmentos lista[n];

	for (int i = 0; i < n; i++)
		scanf("%d %d", &lista[i].inicio, &lista[i].fim);

	qsort(lista, n, sizeof(struct segmentos), compSegmentos);

	printf("%d\n",solve(lista, n, m));

	return 0;
}
