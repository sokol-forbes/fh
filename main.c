#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void map(int n);

int main()
{
srand(time(NULL));
    int n;
    printf("Enter size of side!\n");
    scanf("%d",&n);
    //int labirint[n][n];
    map(n);
    return 0;
}

map(int size)
{
   int **lab, i,k=0,n=100,mp=0;
//определение размерности N и M
lab = (int**)malloc(size* sizeof(int*));
for(i = 0; i < size; ++i)
    lab[i] = (int*)malloc(size* sizeof(int));


   // int lab[size][size];
    //int distanceX[1000];
    //int distanceY[1000];

     int *distanceX = (int*)malloc(n *sizeof(int));
    int *distanceY=NULL;
    distanceY=(int*)malloc(100);

    int X=4;
    int Y=5;

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            lab[i][j]=(rand()%2);
        }
    }
    lab[4][5]=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
    printf("%d ",lab[i][j]);
        }
        printf("\n");
    }
    for(int z=0;;z++)
    {
        if(lab[X][Y]==0)
     {
       if(lab[X-1][Y]==0&&mp!=2) //left
       {
           X=X-1;
           distanceX[z]=X;
           distanceY[z]=Y;
           k++;
           mp=1;
           continue;

       }
       if(lab[X+1][Y]==0&&mp!=1) //right
       {
           X=X+1;
           distanceX[z]=X;
           distanceY[z]=Y;
           k++;
           mp=2;
           continue;

       }
       if(lab[X][Y-1]==0&&mp!=4) //up
       {
           Y=Y-1;
           distanceX[z]=X;
           distanceY[z]=Y;
           k++;
           mp=3;
           continue;

       }
       if(lab[X][Y+1]==0&&mp!=3) //down
       {
           Y=Y+1;
           distanceX[z]=X;
           distanceY[z]=Y;
           k++;
           mp=4;
           continue;

       }

if(X==0||Y==0||X==size||Y==size)
     {
     printf("%s","you win");
     for(int i=0;i<k;i++)
     {
         printf("%d\t",distanceX[k]);
         printf("%d\n",distanceY[k]);
     }
     break;

     }
     if(lab[X-1][Y]==1&&lab[X+1][Y]==1&&lab[X][Y+1]==1&&lab[X][Y-1]==1) printf("%s","one more try");break;
    }

     }

}





