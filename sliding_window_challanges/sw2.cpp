//minimum subarray size.
#include<iostream>
using namespace std;

int smallSubarray(int arr[],int n,int x){
    int sum=0,minL=n+1,st=0,end=0;
    while(end<n){
        while(sum<=x &&end<n){
            sum+=arr[end++];
        }

        while(sum>x &&st<n){
            if(end-st <minL){
                minL=end-st;
            }
            sum-=arr[st++];
        }
    }

    return minL;
}

int main(){

    int arr[]={1,4,45,6,10,19};
    int x=51;
    int n=6;
    int ans=smallSubarray(arr,n,x);
    

    if(ans==n+1){
        cout<<"No such array exist"<<endl;
    }
    else{
        cout<<"smallest lenght of sub array is:"<<ans<<endl;
    }
     
    return 0;
}