#include<stdio.h>
#include<stdlib.h>

void sums(int *lista,int *size){
	for(int i=1;i<*size;i++){
		lista[i]+=lista[i-1];
	}
}

int main(){
	int N, cases;
	scanf("%d", &N);
	int lista[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &lista[i]);
	}
	sums(lista,&N);
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		int min,max;
		scanf("%d%d",&min,&max);

		printf("%d\n", min == 1 ? lista[max-1] : lista[max-1]-lista[min-2]); 
		/* É um operador ternario foo ? a : b é o mesmo que 
			 if (foo) a 
			 else b
		*/
	}
	return 0;
}
