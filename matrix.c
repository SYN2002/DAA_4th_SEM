#include<stdio.h>
#include<stdlib.h>
#define inf 999

int m[10][10],s[10][10];

void display(int n){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(j<i)
				printf("\t");
			else
				printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}

int matrix(int *p,int n){
    int i,j,k,l,cost=0;
    for(i=1;i<=n;i++)
        m[i][i]=0;
    for(l=2;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
            j=i+l-1;
            m[i][j]=inf;
            for(k=i;k<j;k++){
                cost=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(cost<m[i][j]){
                    m[i][j]=cost;
                    s[i][j]=k;
                }
            }
        }
    }
    display(n);
    return m[1][n];
}

void pop(int i,int j){
    if(i==j)
        printf("A%d",i);
    else{
        printf("(");
        pop(i,s[i][j]);
        pop(s[i][j]+1,j);
        printf(")");
    }
}

int main()
{
    int p[]={2,3,5,2,4};
    int n=sizeof(p)/sizeof(p[0]);
    printf("Minimum cost:%d\n",matrix(p,n-1));
    pop(1,4);
    printf("\n");
    
    return 0;
}
