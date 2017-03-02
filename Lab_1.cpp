
#include <stdio.h>


int main() {
    int a,b,c,d,r,h,V;

    for (int i = 100; i < 106 ; ++i) {

        if(i=100){
            printf("%d                 Box (Cube) \n", i);
        }
        if(i=101){
            printf("%d                 Cylinder \n", i);
        }
        if(i=102){
            printf("%d                 Cone \n", i);
        }
        if(i=103){
            printf("%d                 Sphere \n", i);
        }
        if(i=104){
            printf("%d                 Ellipsoid \n", i);
        }
        if(i=105){
            printf("%d                Torus \n", i);
        }


    }

    printf("\n You gotta choose a component dude:\n");
    scanf("%d",&a);

    if(a==100){
        printf("Enter the one side of Box (Cube) \n");
        scanf("%d",&b);
        V=b*b*b;
        printf("%d",V);
    }


    if(a==101){
        printf("Enter r and h Cylinder \n");
        scanf("%d",&r);
        scanf("%d",&h);
        V=3*r*r*h;
        printf("%d",V);
    }
    if(a==102){
        printf("Enter r and h Cone \n");
        scanf("%d",&r);
        scanf("%d",&h);
        V=((3*r*r*h)/3);
        printf("%d",V);
    }
    if(a==103){
        printf("Enter r Sphere \n");
        scanf("%d",&r);

        V=(4/3)*3*r*r*r;
        printf("%d",V);
    }
    if(a==104){
        printf("Enter 3 items  Ellipsoid \n");

        scanf("%d",&b);
        scanf("%d",&c);
        scanf("%d",&d);
        V=(4/3)*3*b*c*d;
        printf("%d",V);
    }
    if(a==105){
        printf("Enter R and r Torus \n");
        scanf("%d",&h);
        scanf("%d",&r);
        V=2*9*h*r*r*r;
        printf("%d",V);
    }



    return 0;
}