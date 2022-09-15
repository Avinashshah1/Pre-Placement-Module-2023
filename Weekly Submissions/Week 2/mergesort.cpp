#include<bits/stdc++.h>

using namespace std;

void merge(int a[],int n, int low, int mid, int high){
    int i=low,j=mid+1,k=low;
    int b[n];
    while(i<=mid && j<=high){
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
     }
    for(;i<=mid;i++)
        b[k++]=a[i];
    for(;j<=high;j++)
        b[k++]=a[j];
    for(int x=0;x<n;x++){
        a[x]=b[x];
    }
}

void mergeSort(int a[],int n, int low, int high){
    if(low<high){
       int mid=(low+high)/2;
       mergeSort(a,n,low,mid);
       mergeSort(a,n,mid+1,high);
       merge(a,n,low,mid,high);
    }
}


int main(){
    int a[]={8,5,7,3,2,4};
    int n=6;

    mergeSort(a,n,0,5);

    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;
    return 0;
}
