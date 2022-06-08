#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define inf 999

int n,graph[10][10],i;

void read(){
    FILE *fp=fopen("abc.txt","r");
    if(fp==NULL)
        printf("ERROR!");
    else{
        fscanf(fp,"%d",&n);
        for(i=0;i<n;i++){
            for(int j=0;j<n;j++)
                fscanf(fp,"%d",&graph[i][j]);
        }
    }
}

void display(int *p,int s){
    //p-->parent
    int t=0;
    printf("Edge\tweight\n");
    for(i=0;i<n;i++){
        if(i==s)
            continue;
        else{
            printf("%c->%c\t  %d\n",p[i]+65,i+65,graph[i][p[i]]);
            t=t+graph[i][p[i]];
        }
    }
    printf("Minimum cost: %d",t);
}

int minKey(int *key,bool *mst){
    int min=inf,index;
    for(int i=0;i<n;i++){
        if(mst[i]==false && key[i]<min){
            min=key[i];
            index=i;
        }
    }
    return index;
}

void prims(int s){
    read();
    int key[n],parent[n],u;
    bool mst[n];
    for ( i = 0; i < n; i++){
        key[i]=inf;
        mst[i]=false;
    }
    key[s]=0;
    parent[s]=-1;
    for (int j = 0; j < n-1; j++){
        int u=minKey(key,mst);
        mst[u]=true;
        for(i = 0; i < n; i++){
            if(graph[u][i]!=0){
                if(mst[i]==false && key[i]>graph[u][i]){
                    key[i]=graph[u][i];
                    parent[i]=u;
                }
            }
        }
    }
    display(parent,s);
}


int main()
{
    int s;
    printf("Starting vertex: ");
    scanf("%d",&s);
    prims(s);

    return 0;
}