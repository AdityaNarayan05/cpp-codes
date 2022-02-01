//place elements to maximise minimum.
#include<iostream>
#include<algorithm>
using namespace std;

bool isFesible(int mid, int arr[],int n,int k){
    int pos=arr[0],ele=1;

    for(int i=1;i<n;i++){
        if(arr[i]-pos>=mid){
            pos=arr[i];
            ele++;
            if(ele==k){
                return true;
            }
        }
    }
    return false;
}

int distance(int arr[],int n,int k){
    sort(arr,arr+n);

    int res=-1;
    int left=1;
    int right=arr[n-1];

    while(left<right){
        int m=(left+right)/2;

        if(isFesible(m,arr,n,k)){
            res=max(res,m);
            left=m+1;
        }
        else{
            right=m;
        }
    }
    return res;
}
int main(){
    //int arr[]={1,2,8,4,9};
    int arr[]={11,2,7,5,1,12};
    int n=6,k=3;
    cout<<"largest distance between two no are:"<<distance(arr,n,k)<<endl;

     return 0;
}