#include "stdio.h"
void main( )
{ 
	//FILE *fp;
	int i=1; 
	double x=500.0,s=1000.0,oil;
	//fp=fopen("data.dat","w");
	do
	{
		//fprintf(fp,"No=%-7dcoord=%10.6f\toil=%11.6f\n",i,s-x,500.0*i);
		printf("No=%-7dcoord=%10.6f\toil=%11.6f\n",i,s-x,500.0*i);
		s-=x;
		x=500.0/(2*i+1);
		i++;
	}while(s>=x);
	oil=500.0*(i-1)+2*s*(i-1)+s;
	//fprintf(fp,"No=%-7dcoord=%10.6f\toil=%11.6f\n",i,0.0,oil);
	//fprintf(fp,"最少的总油耗为：%lf升.\n",oil);
	printf("No=%-7dcoord=%10.6f\toil=%11.6f\n",i,0.0,oil);
	printf("最少的总油耗为：%lf升.\n",oil);
	//fclose(fp);
}
