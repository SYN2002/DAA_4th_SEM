#include<stdio.h>
#include<stdlib.h>
#include"queue.c"

int graph[20][20],n;

void read(){
    FILE *fp=fopen("xyz.txt","r");
    if(fp==NULL)
        printf("Error!!");
    else{
        fscanf(fp,"%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                fscanf(fp,"%d",&graph[i][j]);
        }
    }
}

void bfs(int s){
    read();
    int visited[n];
    for(int i=0;i<n;i++)
        visited[i]=0;
    visited[s]=1;
    push(s);
    while(!isEmpty()){
        int u=pop();
        printf("%c\t",u+65);
        for(int i=0;i<n;i++){
            if(visited[i]==0 && graph[u][i]==1){
                push(i);
                visited[i]=1;
            }
        }
    }
}

int main()
{
    int s;
    printf("Enter the starting vertex: ");
    scanf("%d",&s);
    bfs(s);

    return 0;
}