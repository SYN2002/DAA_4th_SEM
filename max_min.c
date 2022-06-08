#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void maxMin(int *arr,int i,int j,int *max,int *min){
    int max1,min1;
    if(i==j)
        *max=*min=arr[i];
    else if(i==j-1){
        if(arr[i]>arr[j]){
            *max=arr[i];
            *min=arr[j];
        }
        else{
            *max=arr[j];
            *min=arr[i];
        }
    }
    else{
        int mid=(i+j)/2;
        maxMin(arr,i,mid,max,min);
        maxMin(arr,mid+1,j,&max1,&min1);
        if(max1 > *max)
            *max=max1;
        if(min1 < *min)
            *min=min1;
    }
}

int main(){
    int arr[]={8,3,7,1,9,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max,min;
    maxMin(arr,0,n-1,&max,&min);
    printf("Max=%d and min=%d",max,min);
    return 0;
}