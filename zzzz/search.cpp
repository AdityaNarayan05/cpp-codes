#include<iostream>
using namespace std;

int linear(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cout<<"Search completed"<<endl;
            return i+1;
            break;
        }
    }
    return -1;
}
int binary(int arr[],int n,int key){
    int l=0;
    int h=n-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]==key){
            return mid+1;
        }
        else if(key<arr[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}
int recBinary(int arr[],int l,int h,int key){
    if(l==h){
        if(arr[l]==key){
        return l+1;
        }
    
    else{
        return -1;
    }
}
    else{
        int mid=(l+h)/2;
        if(key==arr[mid]){
            return mid+1;
        }
        else if(key<arr[mid]){
            recBinary(arr,l,mid-1,key);
        }
        else{
            recBinary(arr,mid+1,h,key);
        }
    }
}

int main(){
    cout<<"NAME: ADITYA NARAYAN JAISWAL\n";
    cout<<"SCHOLAR NO:20U02065\n";
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"enter your searching no"<<endl;
    cin>>k;
    cout<<"Position of no via linear search  is:"<<linear(arr,n,k)<<endl;
    cout<<"Position of no via binary search  is:"<<binary(arr,n,k)<<endl;
    cout<<"Position of via reccurance binary search no is:"<<recBinary(arr,0,n-1,k)<<endl;

    return 0;
}