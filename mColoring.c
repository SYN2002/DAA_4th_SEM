#include<stdio.h>
#include<stdlib.h>

int x[10]={0},g[10][10],n,m;

void read(){
    FILE *fp=fopen("xyz.txt","r");
    if(fp==NULL)
    printf("ERROR!");
    else{
        fscanf(fp,"%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                fscanf(fp,"%d",&g[i][j]);
        }
    }
}

void nextValue(int k){
    read();
    int j;
    while(1){
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)
            return;
        for(j=1;j<k;j++){
            if(g[k][j]==1 && x[k]==x[j])
            break;
        }
        if(k==j)
            return;
    }
}

void mColoring(int k){
    int i;
    while(1){
        nextValue(k);
        if(x[k]==0)
            return;
        if(k==n){
            for(i=1;i<=n;i++)
                printf("%3d",x[i]);
            printf("\n");
        }
        else
            mColoring(k+1);
    }
}

int main()
{
    read();
    printf("Enter the no. of colours: ");
    scanf("%d",&m);
    mColoring(1);

    return 0;
}