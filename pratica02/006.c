/*
Autor:André Cerqueira
Data: 2020/10/17

Agradecimento à colega Tatiana Araujo , por me ter explicado a resolução do exercicio
*/

#include <stdio.h>

double solve(double qx,double qy,double ql,double c1,double c2,double cr){

	double qx2 = qx + ql;
	double qy2 = qy + ql;
	double resposta = 0;

	if
		(
		(qx - c1) * (qx - c1) + (qy - c2) * (qy - c2) < cr*cr &&
		(qx - c1) * (qx - c1) + (qy2 - c2) * (qy2 - c2) < cr*cr &&
		(qx2 - c1) * (qx2 - c1) + (qy - c2) * (qy - c2) < cr*cr &&
		(qx2 - c1) * (qx2 - c1) + (qy2 - c2) * (qy2 - c2) < cr*cr
		)
		return ql * ql; //quadrado dentro do circulo

	if
		(
			(c1 + cr) < (qx + ql) &&
			(c1 - cr) > qx &&
			(c2 + cr) < (qy + ql) &&
			(c2 - cr) > qy
			)
		return  3.1415926535897 * cr * cr; // circulo dento do quadrado

	if
		(
		(qx - c1) * (qx - c1) + (qy - c2) * (qy - c2) > cr*cr &&
		(qx - c1) * (qx - c1) + (qy2 - c2) * (qy2 - c2) > cr*cr &&
		(qx2 - c1) * (qx2 - c1) + (qy - c2) * (qy - c2) > cr*cr &&
		(qx2 - c1) * (qx2 - c1) + (qy2 - c2) * (qy2 - c2) > cr*cr &&
		!(c1 > qx && c1 < qx2) &&
		!(c2 > qy && c2 < qy2)
		)
		return 0; // não se intersetam

	if(ql>=0.001){
		ql /= 2;
		resposta += solve(qx, qy + ql, ql, c1, c2, cr);
		resposta += solve(qx + ql, qy + ql, ql, c1, c2, cr);
		resposta += solve(qx, qy, ql, c1, c2, cr);
		resposta += solve(qx + ql, qy, ql, c1, c2, cr);
	}

	return resposta;
}

int main() {
	int n;
	double qx,qy,ql;
	double c1,c2,cr;

	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%lf %lf %lf",&qx,&qy,&ql);
		scanf("%lf %lf %lf",&c1,&c2,&cr); 
		printf("%.2lf\n", solve(qx,qy,ql,c1,c2,cr));
	}
	return 0;
}
