/* autor André Cerqueira */
/* 1 Outubro 2020 */

#include<stdio.h>

int sumDigits(int n){
	int sum=0;


	while (n != 0){
		sum += n % 10;
		n/=10;
	}
	return sum;
}

int solve(int n , int k){
	for (++n ;;n++){
		if ( sumDigits(n) == k ) return n;
	}
	return -1;
}

int main() {
	int casos;
	int n,k;

	scanf("%d",&casos);


	for (int i=0;i<casos;i++){
		scanf("%d %d",&n,&k);
		printf("%d\n",solve(n,k));
	}
	return 0;
}
