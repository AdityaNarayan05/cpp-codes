//search in sorted rotated Array.
#include<iostream>
using namespace std;

int search(int arr[],int k,int l,int r){
    if(l>r){
        return -1;
    }
    int m=(l+r)/2;
    if(arr[m]==k){
        return m;
    }
    if(arr[l]<=arr[m]){
        if(k>=arr[l]&&k<=arr[m]){
            return search(arr,k,l,m-1);
        }
        return search(arr,k,m+1,r);
    }
    if(k>=arr[m]&&k<=arr[r]){
        return search(arr,k,m+1,r);
    }
    return search(arr,k,l,m-1);
}

int main(){
     int a[]={6,7,8,9,10,1,2,5};
     int n=8;
     int k=8;
     int i=search(a,k,0,n-1);

     if(i==-1){
         cout<<"key doesn't exist\n";
     }
     else{
         cout<<"key at :"<<i+1<<endl;
     }
     return 0;
}