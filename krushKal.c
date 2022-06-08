#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    char pred;
    char suc;
    int weight;
}s;

int parent[10],graph[10][10],n=6;

int comp(const s*p,const s*q){
    return p->weight - q->weight;
}

void makeSet(int v){
    parent[v]=v;
}

int find(int i){
    while(parent[i]!=i)
        i=parent[i];
    return i;
}

void uni(int i,int j){
    if(i!=j){
        parent[j]=i;
    }
}

int krushKal(s *p,int m){
    int a,b,u,v,i,w,tp=0;
    for(i=0;i<m;i++)
    makeSet(i);
    for(i=0;i<m;i++){
        u=(int)p[i].pred-65;
        v=(int)p[i].suc-65;
        w=p[i].weight;
        a=find(u);
        b=find(v);
        if(a!=b){
            uni(a,b);
            printf("%c-->%c\n",u+65,v+65);
            tp=tp+w;
        }
    }
    return tp;
}

int main()
{
    s arr[]={{'A','B',7},{'A','D',8},{'B','D',3},{'B','C',6},{'D','E',3},{'D','C',4},{'C','E',2},{'C','F',5},{'E','F',2}};
    int n=sizeof(arr)/sizeof(arr[0]);
    qsort(arr,n,sizeof(s),comp);
    printf("Minimum cost: %d",krushKal(arr,n));
    
    return 0;
}
