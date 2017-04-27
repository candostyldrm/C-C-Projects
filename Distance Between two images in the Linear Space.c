//
// Created by Candost on 11.04.2017.
//
// Candost Yildirim 
// ID: 190206025
//Quiz 1

// In this programme I used two functions as Trace and Norm
//In the norm function I did transpose and multiplication precesses
// In the main I use norm function to get distances
//I sorted distances as closest and farthest one
// The I used If conditions to get the right image

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int trace(float M[5][5]){
    int i,j;
    float toplam=0.0;

    for(i=0;i<5;i++)
        for(j=0;j<5;j++){

            if(i==j)
                toplam=toplam + M[i][j];
            else
                continue;
        }

    return(toplam);

}

int norm(float A[5][5],float B[5][5]){

    float M[5][5];
    float T[5][5];
    float S[5][5];
    int i,j,k;
    float traced,d;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            S[i][j]=A[i][j]-B[i][j];

    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            T[j][i]= S[i][j];



    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            for(k=0;k<5;k++)
                M[i][j]=T[i][k]+S[k][j];



    traced=trace(M);
    d=sqrt(traced);

    return (d);
}




int main (int argc , char *argv[])
{
    float A[5][5];
    float B1[5][5]={{255,241,27,106,255},{255,166,0,203,255},{244,55,68,247,255},{183,0,136,255,255},{252,94,0,168,255}};
    float B2[5][5]={{25,62,88,106,213},{50,111,123,203,255},{77,91,135,173,255},{105,127,173,255,0},{189,202,255,0,0}};
    float B3[5][5]={{255,145,73,51,0},{255,177,137,93,0},{196,135,102,0,0},{172,156,144,99,81},{159,117,93,67,53}};
    float B4[5][5]={{255,222,69,207,255,},{255,224,68,206,255},{222,67,206,255,246},{223,66,205,255,0},{245,74,172,255,254}};
    float B5[5][5]={{231,148,50,124,183},{242,79,187,210,150},{155,205,225,113,34},{95,157,245,82,118},{90,105,93,47,255}};
    int i,j,k;
    float closest,farthest;
   float dist[5];
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            A[i][j]= atof(argv[j+(i*5)]);


dist[0]=norm(A,B1);
    dist[1]=norm(A,B2);
    dist[2]=norm(A,B3);
    dist[3]=norm(A,B4);
    dist[4]=norm(A,B5);
closest=dist[0];
    farthest=dist[0];


    for (int i = 0; i < 5 ;i++) {
        if(dist[i]<closest)
            closest=dist[i];
        else
            continue;
    }
    for (int i = 0; i < 5 ;i++) {
        if(dist[i]<farthest)
            farthest=dist[i];
        else
            continue;
    }

    if (dist[0]==closest)
        printf("The image B1 is the Closest image and distance is %.2f \n",closest);
    if (dist[0]==farthest)
        printf("The image B1 is the Farthest image and distance is %.2f \n",farthest);
    if (dist[1]==closest)
        printf("The image B1 is the Closest image and distance is %.2f \n",closest);
    if (dist[1]==farthest)
        printf("The image B1 is the Farthest image and distance is %.2f \n",farthest);
    if (dist[2]==closest)
        printf("The image B1 is the Closest image and distance is %.2f \n",closest);
    if (dist[2]==farthest)
        printf("The image B1 is the Farthest image and distance is %.2f \n",farthest);
    if (dist[3]==closest)
        printf("The image B1 is the Closest image and distance is %.2f \n",closest);
    if (dist[3]==farthest)
        printf("The image B1 is the Farthest image and distance is %.2f \n",farthest);
    if (dist[4]==closest)
        printf("The image B1 is the Closest image and distance is %.2f \n",closest);
    if (dist[4]==farthest)
        printf("The image B1 is the Farthest image and distance is %.2f \n",farthest);




    return 0;

}
