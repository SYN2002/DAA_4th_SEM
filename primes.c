#include<stdio.h>
#include<stdlib.h>

int i,j;

int primeNumbers(int n){
    int c,k=0;
    if(n>1){
        for(i=1;i<=n;i++){
            c=0;
            for(j=1;j<=i;j++){
                if(i%j==0)
                c++;
            }
            if(c==2)
                k++;
        }
        return k;
    }
    else
    return 0;
}

int main()
{
    int n,t=0;
    scanf("%d",&n);
    int p=0;
    do{
        n=n-p;
        p=primeNumbers(n);
        t++;
    }while(p>0);
    printf("%d",t);
    
    return 0;
}