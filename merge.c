#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void merge(int *arr,int l,int mid,int h){
    int b[h+1],i=l,k=l,j=mid+1;
    while(i<=mid && j<=h){
        if(arr[i]<arr[j]){
            b[k]=arr[i];
            i++;
        }
        else{
            b[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        b[k]=arr[i];
        i++;
        k++;
    }
    while(j<=h){
        b[k]=arr[j];
        j++;
        k++;
    }
    for(i=l;i<=h;i++){
        // printf("%d\t",b[i]);
        arr[i]=b[i];
    }
}

void mergeSort(int *arr,int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

int main(){
    int arr[]={3,8,5,1,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    // print(arr,n);

    return 0;
}