//using merge sort for soritng array list.
//NAME : ADITYA NARAYAN JAISWAL.
//REG NO:20U02065
#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int m,int h){
    int ll,t,f,s,temp[10];
    f=l;
    s=m+1;
    t=l;
    while(f<=m&&s<=h){
        if(arr[f]<arr[s]){
            temp[t]=arr[f];
            f++;
            t++;
        }
        else{
            temp[t]=arr[s];
            s++;
            t++;
        }
    }
    while(f<=m){
        temp[t]=arr[f];
        f++;
        t++;
    }
    while(s<=h){
        temp[t]=arr[s];
        s++;
        t++;
    }
    for(int i=l;i<=h;i++){
        arr[i]=temp[i];
    }
}
void mergeSort(int arr[],int l,int h){
    int m;
    if(l<h){
        m=(l+h)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,h);
        merge(arr,l,m,h);
    }
}
void print(int arr[],int n){
    cout<<"ADITYA NARAYAN JAISWAL"<<endl;
     for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl; 
}
int main(){
    int arr[]={7,9,2,21,17,3,11};
    print(arr,7);
    mergeSort(arr,0,6);
    print(arr,7);
    return 0;
}