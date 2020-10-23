#include<stdio.h>
#include<stdlib.h>

struct trabalho
{
	int ordem; //ordem em que aparece
	double racio;
};

int compTrabalhos(const void *p1 , const void *p2)
{
	struct trabalho *a = (struct trabalho*) p1;
	struct trabalho *b = (struct trabalho*) p2;

	if (a->racio == b->racio) return (a->ordem - b->ordem);
	if (b->racio > a->racio) return 1;
	return -1;
}

int main()
{
	int n; scanf("%d",&n);
	struct trabalho lista[n];

	for(int i=0; i<n; i++){
		double dia,multa;
		scanf("%lf %lf",&dia,&multa);
		lista[i].ordem=i+1;
		lista[i].racio = multa / dia;
	}

	qsort(lista,n,sizeof(struct trabalho),compTrabalhos);

	for(int i=0; i<n; i++){
		printf("%d%c",lista[i].ordem , i==n-1 ? '\n' : ' ');
	}

	return 0;

}
