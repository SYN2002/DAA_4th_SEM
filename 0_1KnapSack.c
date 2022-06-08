#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int x[20][20],i;

typedef struct{
    // char id;
    int weight;
    int profit;
}s;

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int knap(s *p,int n,int m){
    int w;
    for(i=0;i<=n;i++)
        x[i][0]=0;
    for(w=0;w<=n;w++)
        x[0][w]=0;
    for(i=1;i<=n;i++){
        for(w=1;w<=m;w++){
            if(p[i].weight<=w){
                x[i][w]=max((p[i].profit + x[i-1][w-p[i].weight]),x[i-1][w]);
            }
            else
                x[i][w]=x[i-1][w];
        }
    }
    printf("%d\n",x[n][m]);
    for(i=1;i<=n;i++){
        for(w=1;w<=m;w++){
            printf("%d\t",x[i][w]);
        }
        printf("\n");
    }
    return x[n][m];
}

void knapSack(s *p,int n,int m){
    int tp=knap(p,n,m);
    int w=m;
    for(i=n;i>0;i--){
        if(tp==x[i-1][w])
        continue;
        else{
            printf("%d\t",i);
            w=w-p[i].weight;
            tp=tp-p[i].profit;
            if(tp==0)
            break;
        }
    }
}

int main()
{
    // s arr[]={{'A',100,5},{'B',198,3},{'C',120,4},{'D',280,6}};
    s arr[10];
    arr[1].profit=100;
    arr[1].weight=5;
    arr[2].profit=198;
    arr[2].weight=3;
    arr[3].profit=120;
    arr[3].weight=4;
    arr[4].profit=280;
    arr[4].weight=7;
    int n=4,w=8;
    knapSack(arr,n,w);

    return 0;
}