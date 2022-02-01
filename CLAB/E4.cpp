//20U02065_ADITYA NARAYAN JAISWAL
#include<iostream>
using namespace std;

void swap(int arr[],int i,int j){
    int t=arr[i];
    arr[i]=arr[j];
    arr[j]=t;
}

int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;

    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    } 
    swap(arr,i+1,r); 
    return (i+1);
}

void QS(int arr[],int l,int r){

    if(l<r){
        int pi=partition(arr,l,r);
        QS(arr,l,pi-1);
        QS(arr,pi+1,r);
    }
}

int main(){
    cout<<"20U02065_ADITYA NARAYAN JAISWAL"<<endl;
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"enter your no. to be sorted"<<endl;
        cin>>arr[i];
    }
    QS(arr,0,n-1);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}