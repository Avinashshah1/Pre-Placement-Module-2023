#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> a={8,5,7,3,2,4};
    int n=a.size();

    for(int i=1;i<n;i++){
        int j=i-1;
        int temp=a[i];
        while(j>-1 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    for(auto x:a)
        cout<<x<<endl;
    return 0;
}
