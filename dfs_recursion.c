#include<stdio.h>
#include<stdlib.h>
#define n 4

int graph[n][n],visit[n]={0};

void read(){
	int i,j;
    FILE *fp=fopen("xyz1.txt","r");
    if(fp==NULL)
        printf("Error!!");
    else{
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                fscanf(fp,"%d",&graph[i][j]);
        }
    }
}

void dfs_recursion(int s){
    read();
    visit[s]=1;
    printf("%d\t",s);
    int i;
    for(i=0;i<n;i++){
        if(graph[s][i]==1 && visit[i]==0){
            dfs_recursion(i);
        }
    }
}

int main()
{
    int s;
    printf("Enter the starting vertex: ");
    scanf("%d",&s);
    dfs_recursion(s);
    return 0;
}
