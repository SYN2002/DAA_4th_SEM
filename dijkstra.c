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
    fclose(fp);
}

void display(int *dist,int r){
    //p-->parent
    printf("Edge\tweight\n");
    for(i=0;i<n;i++)
    printf("%c->%c\t  %d\n",r+65,i+65,dist[i]);
}

int minKey(int *dist,bool *mst){
    int min=inf,index;
    for(int i=0;i<n;i++){
        if(mst[i]==false && dist[i]<min){
            min=dist[i];
            index=i;
        }
    }
    return index;
}

void dijkstra(int r){
    read();
    int dist[n],parent[n],u;
    bool mst[n];
    for ( i = 0; i < n; i++){
        dist[i]=inf;
        mst[i]=false;
    }
    dist[r]=0;
    parent[r]=-1;
    for (int j = 0; j < n-1; j++){
        int u=minKey(dist,mst);
        mst[u]=true;
        for(i = 0; i < n; i++){
            if(!mst[i] && graph[u][i]!=0){
                if(dist[u]!=inf && dist[i]>(dist[u]+graph[u][i])){
                    dist[i]=dist[u]+graph[u][i];
                    parent[i]=u;
                }
            }
        }
    }
    display(dist,r);
}


int main()
{
    int v;
    printf("starting vertex: ");
    scanf("%d",&v);
    dijkstra(v);
    return 0;
}