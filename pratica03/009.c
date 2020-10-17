#include<stdio.h>
#include<stdlib.h>

#define N 10001

struct DNA {
	char letter;  
	int frequency;
	int firstAppeerence;
};

static int compDNA(void const * p1 , void const * p2){
	struct DNA *a = (struct DNA*) p1;
	struct DNA *b = (struct DNA*) p2;

	if ( a->frequency < b->frequency) return 1;
	if ( a->frequency > b->frequency) return -1;
	if ( a->firstAppeerence < b->firstAppeerence) return -1; 
	if ( a->firstAppeerence > b->firstAppeerence) return 1;
	return 0;
}

int main () {
	struct DNA lista[26];
	char buffer[N] ;

	scanf("%s",buffer);

	for( int i = 0 ; i<26 ; i++) {
		lista[i].frequency = 0;
		lista[i].letter = 'A' + i ;
	}

	for( int i = 0 ; buffer[i] ; i++) { 
		int pos = buffer[i] - 'A' ;
		if (lista[pos].frequency == 0 )
			lista[pos].firstAppeerence = i ;
		lista[pos].frequency++;
	}

	qsort(lista,26,sizeof(struct DNA),compDNA);

	for( int i = 0 ; lista[i].frequency != 0 ; i++) {
		printf("%c %d\n" , lista[i].letter , lista[i].frequency);
	}

	return 0;
}
