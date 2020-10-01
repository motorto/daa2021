/* autor André Cerqueira */
/* 1 Outubro 2020 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int generation (char *tmp){ /* descobre a geração da matricula e devolve o numero de 
casos das matriculas anteriores*/
	const int casos=5290000; // 10^4 * 23^2
	if ( isalpha(tmp[0]) ) {
		if ( isalpha(tmp[7]) ) return casos*3; // Geração 4
		else return 0; // Geração 1
	}
	else {
		if ( isalpha(tmp[7]) ) return casos*1; // Geração 2
		else return casos*2; // Geração 3
	}
}

int solve(char *a){
	int base=1;
	int res = generation(a);

	 /* Começa a contar da direita para a esquerda, */
		/* cada digito tem 10vezes , letra 23vezes */

	for (int i = 7 ; i>=0 ; i--) {
		if (isdigit(a[i])) {
			res += (a[i] - '0') * base ;
			base*=10;
		}
	}
	for (int i = 7 ; i>=0 ; i--) {
		if (isalpha(a[i])) {
			int value = a[i] - 'A';
			if ( a[i] > 'K') value--;
			if ( a[i] > 'W') value--;
			if ( a[i] > 'Y') value--;
			res+= value * base;
			base *=23;
		}
	}
	return res;
}

int main() {
	int cases; scanf("%d",&cases);
	char tmp [20];
	fgets(tmp,20,stdin);
	for (int i=0; i < cases; i++){
		fgets(tmp,20,stdin);
		char *a; char *b;
		a = strtok(tmp , " ");
		b = strtok(NULL, "\n");
		printf("%d\n",abs( solve(b) - solve(a) ));
	}
	return 0;
}
