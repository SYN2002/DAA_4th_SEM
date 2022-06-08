#include<stdio.h>
#include<stdlib.h>

void swap(int *arr,int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int *arr,int l,int h){
    int i=l,j=h+1;
    int pivot=arr[l];
    while(i<j){
        do{
            i++;
        } while (i<=j && arr[i]<pivot);
        do{
            j--;
        } while (arr[j]>pivot);
        if(i<j)
            swap(arr,i,j);
    }
    swap(arr,l,j);
    return j;
}

void quickSort(int *arr,int l,int h){
    if(l<h){
        int j=partition(arr,l,h);
        quickSort(arr,l,j-1);
        quickSort(arr,j+1,h);
    }
}

int main()
{
    int arr[]={2,1,3,7,4,9};
    int n=sizeof(arr)/sizeof(arr[0]),i;
    quickSort(arr,0,n-1);
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

    return 0;
}
