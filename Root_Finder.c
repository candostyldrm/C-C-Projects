#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 10
double array[MAXSIZE];
int power;

double function(double x){
	int i;
	double polySum;
	 polySum = array[0];
    for ( i = 1; i <= power; i++)
    {
        polySum = polySum * x + array[i];
    }	
   
     return polySum;
}

void find_interval(){
	double xstart=-6.0,xend=6.0,stepsize=0.03,xleft,xright;
	int found_root=1;
	xleft=xstart;
	xright=xleft+stepsize;
	while(xleft<xend && function(xleft)*function(xright)>0)
	{
		xleft = xright;
		xright += stepsize;
		if(xright>xend) 
			xright = xend;		
		if(function(xleft)*function(xright)<0){
			printf("%f %f\n",xleft , xright);	
				xleft = xright;
				xright += stepsize;
		}
	}
}
	

int main(){
	
    int i;
    printf("Enter the order of the polynomial \n");
    scanf("%d", &power);
    /*  Read the coefficients into an array */
    printf("Enter %d coefficients \n", power + 1);
    for (i = 0; i <= power; i++)
    {
        scanf("%lf", &array[i]);
    }
    find_interval();
    
		
}
	


