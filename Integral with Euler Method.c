#include <stdio.h>
#include <stdlib.h>
#include <math.h>
FILE *fp;

double function(double x,double y)
{
	return(exp(cos(x))-(y*sin(x)));
}

double euler(double x0,double y0,double h,double x)
{
	double a;
	for(;x0<=x;x0=x0+h)
	{
		a=function(x,y0);
		y0=y0+(h*(a));
	}
	return y0;
}

double error(double exact, double approx)
{
	return fabs((exact - approx)/exact)*100;
}

void main(void)
{
	double x0=0,y0=-2.5;
	double excatArray[]={-2.21707,-1.991773,-1.61093,-1.30546,-1.00941},*yos;
	int i,j;
	yos = malloc(3*5*sizeof(double));
	fp=fopen("output.txt","w");
	fprintf(fp,"X\tExact Value\tEuler(h=0.01)\tEuler(h=0.001)\tEuler(h=0.0001)\r\n");
	for(i=0;i<5;i++)
	{
		fprintf(fp,"%.2lf\t%.5lf\t",(i+1)/10.0,excatArray[i]);
		for(j=0;j<3;j++)
		{
			yos[i*3+j] = euler(x0,y0,pow(10,-j-2),(i+1)/10.0);
			fprintf(fp,"%.5lf\t",yos[i*3+j]);
		}
		fprintf(fp,"\r\n");
	}
	fprintf(fp,"\r\n\r\nX\t%%error(h=0.01)\t%%error(h=0.001)\t%%error(h=0.0001)\r\n");
	for(i=0;i<5;i++)
	{
		fprintf(fp,"%.2lf\t",(i+1)/10.0);
		for(j=0;j<3;j++)
		{
			fprintf(fp,"%.5lf \t",error(excatArray[i],yos[i*3+j]));
		}
		fprintf(fp,"\r\n");
	}
	fprintf(fp,"\t\t\t\t\tCandost YILDIRIM\n");
	fclose(fp);
}

