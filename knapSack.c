#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct {
    char id;
    float value;
    float weight;
    int pw;
}s;

int comp(const s *p,const s *q){
    return q->pw - p->pw;
}

float knapSack(s arr[],int n,int w){
    float profit=0;
    int i,u=w;
    float x;
    for ( i = 0; i < n; i++){
        if(u>=arr[i].weight){
            u=u-arr[i].weight;
            profit=profit+arr[i].value;
        }
        else{
            x=u/arr[i].weight;
            profit=profit+x*arr[i].value;
            break;
        }
    }
    return profit;
    
}

int main(){
    s arr[]={{'A',100,5},{'B',197,9},{'C',120,4},{'D',280,7},{'E',184,8}};
    int n=sizeof(arr)/sizeof(arr[0]),i;
    for (i = 0; i < n; i++)
        arr[i].pw=arr[i].value/arr[i].weight;
    qsort(arr,n,sizeof(arr[0]),comp);
    printf("Maximum profit:= %.2f",knapSack(arr,n,15));
    
    return 0;
}
