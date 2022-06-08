#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void maxHeap(int *arr,int n,int i){
    int largest=i; 
    int left=2*i+1,right=2*i+2;
    if(left<n && arr[left]>arr[largest])
        largest=left;
    if(right<n && arr[right]>arr[largest])
        largest=right;
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        maxHeap(arr,n,largest);
    }
}

void heapSort(int *arr,int n){
    int i;
    for(i=n/2-1;i>=0;i--)
    maxHeap(arr,n,i);
    for(i=n-1;i>=0;i--){
        swap(&arr[i],&arr[0]);
        maxHeap(arr,i,0);
    }
}

void print(int *arr,int n){
	int i;
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
}

int main()
{
    int arr[]={3,8,5,1,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapSort(arr,n);
    print(arr,n);
    
    return 0;
}
