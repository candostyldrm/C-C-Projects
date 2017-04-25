//
// Created by candost on 18.04.2017.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Equation(double x){
    return 8-log(x*x-2*x+4);
}

double trapezoidal(double (*function)(double),int a,int b,int N){
    double result,h;
    int i;
    result=function(a)/2;
    h=(b-a)/N;
    for(i=1;i<=N;i++){
        result+=function(a+i*h);
    }
    result-=function(b)/2;
    result=h*result;
    return result;
}

double simpson(double (*function)(double),int a,int b,int n){
    double answer,h;
    double x;
    int i;

    answer=function(a);
    h=(b-a)/n;

    for(i=1;i<=n;i++){
        x=a+i*h;
        answer+= 4*function(x-h/2) + 2*function(x);
    }

    answer=answer-function(b);


    return(h*answer/6);


}


int main()
{
    int a=0,b=12,n=8;
    double result,answer;


        answer= simpson(Equation,a,b,n);
        result = trapezoidal(Equation,a,b,n);
        printf("a\tb\tTrapezoidal\r\n%d\t%d\t%lf \n",a,b,result);
        printf("a\tb\tSimpson\r\n%d\t%d\t%lf",a,b,answer);

    return(0);
}
