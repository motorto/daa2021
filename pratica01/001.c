/* autor André Cerqueira */
/* 1 Outubro 2020 */
#include<stdio.h>

int main () {
	int n,tmp,count=0;
	scanf("%d",&n);

	for (int i=0; i<n;i++){
		scanf("%d",&tmp);
		if (tmp == 42) count++;
	}
	printf("%d\n",count);
	return 0;
}
