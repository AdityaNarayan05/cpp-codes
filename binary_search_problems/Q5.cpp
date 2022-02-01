//find peak element of list.
#include<iostream>
using namespace std;

int find(int arr[],int l,int h,int n){
    int m=l+(h+l)/2;

    if((m==0||arr[m-1]<=arr[m])&&(m==n-1 ||arr[m+1]<=arr[m])){
        return m;
    }

    else if(m>0 &&arr[m-1]>arr[m]){
        return find(arr,l,m-1,n);
    }
    else{
        return find(arr,m+1,h,n);
    }
}

int main(){
    int a[]={0,6,8,5,7,9};
    int n=6;
    cout<<"peak element position:"<<find(a,0,n-1,n)+1<<endl;
    return 0;
}