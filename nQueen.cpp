#include<iostream>
using namespace std;

int x[10]={0};

int place(int k,int i){
    int j;
    for(j=1;j<k;j++){
        if((x[j]==i)or(abs(x[j]-i)==abs(j-k)))
        return 0;
    }
    return 1;
}

void nQueen(int k,int n){
    for(int i=1;i<=n;i++){
        if(place(k,i)){
            x[k]=i;
            if(k==n){
                for (int i = 1; i <= n; i++){
                    cout<<x[i]<<"\t";
                }
                cout<<endl;
            }
            else
                nQueen(k+1,n);
        }
    }
}

int main(){
    int m;
    cout<<"Enter the value of n: ";
    cin>>m;
    nQueen(1,m);
    return 0;
}