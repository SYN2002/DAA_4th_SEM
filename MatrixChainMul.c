#include<stdio.h>
int m[10][10], s[10][10];
int matrixMul(int a[], int n){
	int i,j,k,l,q;
	for(i=0;i<n;i++)
		m[i][i]=0;
	for(l=2;l<n;l++){
		for(i=1;i<n-l+1;i++){
			j=i+l-1;
			m[i][j]=99999;
			for(k=i;k<=j-1;k++){
				q=m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];
				if(q<m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}
			}	
		}
	}
	int r,p;
	for(r=1;r<n;r++){
		for(p=1;p<n;p++){
			if(p<r)
				printf("\t");
			else
				printf("%d\t",m[r][p]);
		}
		printf("\n");
	}
	printf("\n");
	for(r=1;r<n;r++){
		for(p=1;p<n;p++){
			if(p<=r)
				printf("\t");
			else
				printf("%d\t",s[r][p]);
		}
		printf("\n");
	}
	return m[1][n-1];
}
	
void POP(int i,int j){
	if(i==j) printf("A%d",i);
	else{
		printf("(");
		POP(i,s[i][j]);
		POP(s[i][j]+1,j);
		printf(")");
	}
}
			
int main(){
	int n;
	printf("Enter the number of matrices: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter: ");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	n=n+1;
	// int i;
	int res=matrixMul(a,n);
	printf("Minimum steps required %d\n",res);
	POP(1,4);
	return 0;
}

