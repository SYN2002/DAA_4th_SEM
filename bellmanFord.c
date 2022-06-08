#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define inf 999

int v=6;

typedef struct{
    int u;
    int v;
    int weight;
}bford;

void display(int *dist,int s){
    //p-->parent
    printf("Edge\tweight\n");
    for(int i=0;i<v;i++)
    printf("%c->%c\t  %d\n",s+65,i+65,dist[i]);
}

void bellmanFord(bford *p,int s,int e){
    int a,b,w,i,j;
    int dist[v],parent[v];
    for(i=0;i<v;i++){
        dist[i]=inf;
        parent[i]=-1;
    }
    dist[s]=0;
    for(i=1;i<v;i++){
        for(j=0;j<e;j++){
            a=p[j].u;//(int)p[j].u-65;
            b=p[j].v;//(int)p[j].v-65;
            w=p[j].weight;
            if(dist[a]!=inf && dist[b]>dist[a]+w){
                dist[b]=dist[a]+w;
                parent[b]=a;
            }
        }
    }
    for(j=0;j<e;j++){
        a=p[j].u;
        b=p[j].v;
        w=p[j].weight;
        if(dist[a]!=inf && dist[b]>dist[a]+w){
            printf("Negative cycle exits!");
            return;
        }
    }
    display(dist,s);
}

int main()
{
    bford arr[]={{0,1,3},{0,2,2},{0,3,5},{1,4,-1},{2,4,-1},{2,5,4},{3,5,-2},{4,5,-1}};
    int s,e;
    e=sizeof(arr)/sizeof(arr[0]);
    printf("Enter the starting vertex: ");
    scanf("%d",&s);
    bellmanFord(arr,s,e);

    return 0;
}