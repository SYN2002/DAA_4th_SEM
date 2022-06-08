#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
	char id;
	float profit;
	int deadline;
}job;

int comp(const job*p,const job*q){
	return q->profit - p->profit;
}

int min(int a,int b){
	if(a<b)
		return a;
	return b;
}

int max(job *p,int n){
    int max=p[0].deadline;
    for (int i = 1; i < n; i++){
        if(p[i].deadline>max)
            max=p[i].deadline;
    }
    return max;
}

void jobSeduling(job *p,int n){
	int i,j,x[n];
	bool slot[n];
	for(i=0;i<=n;i++){
		x[i]=0;
		slot[i]=false;
	}
	float pt=0;
	for(i=0;i<=n;i++){
		for(j=min(p[i].deadline,n);j>=0;j--){
			if(slot[j]==false){
				x[j]=i;
				slot[j]=true;
				pt=pt+p[j].profit;
				break;
			}
		}
	}
	pt=pt-p[x[0]].profit;
	printf("%.2f\n",pt);
	for ( i = 1; i <= n; i++){
        if (slot[i])
            printf("%c\t%.2f\t %d\n", p[x[i]].id,p[x[i]].profit,p[x[i]].deadline);
    }
}

int main()
{
    job jobs[]={{'A',15,7},{'B',20,2},{'C',30,5},{'D',18,3},{'E',18,4},{'F',10,5},{'G',23,2},{'H',16,7},{'I',25,3}};
    int n=sizeof(jobs)/sizeof(jobs[0]),i;
    qsort(jobs,n,sizeof(job),comp);
    jobSeduling(jobs,min(max(jobs,n),n));
    
    return 0;
}