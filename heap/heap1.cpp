//implementation of heap sort without reccursion.
#include<bits/stdc++.h>
using namespace std;
//BY: ADITYA NARAYAN JAISWAL 20u02065.

heapSort(int arr[],int n){
    while(n>1){
        for(int i=1;i<=n;i++){
            int c=i;
            int p=c/2;

            while(p>0 && arr[c]>arr[p]){
                swap(arr[c],arr[p]);
                c=p;
                p=c/2;
            }
        }
        swap(arr[1],arr[n]);
        n=n-1;
    }

   
}

int main(){
    cout<<"BY: ADITYA NARAYAN JAISWAL 20u02065"<<endl;
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int arr[n+1];
    arr[0]=0;
    cout<<"enter  your no"<<endl;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    heapSort(arr,n+1);
     for(int j=1;j<=n;j++){
        cout<<arr[j]<<" ";
    }
    cout<<endl;

    return 0;
}