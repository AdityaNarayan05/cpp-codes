//painters partition problem.
#include<bits/stdc++.h>
using namespace std;

int findFesible(int boards[],int n,int limit){
    int s=0;
    int painters=1;
    for(int i=0;i<n;i++){
        s+=boards[i];
        if(s>limit){
            s=boards[i];
            painters++; 
        }
    }
    return painters;
}

int partition(int boards[],int n,int m){
    int tl=0,k=0;
    for(int i=0;i<n;i++){
        k=max(k,boards[i]);
        tl+=boards[i];
    }

    int low=k,high=tl;
    while(low<high){
        int mid=(low+high)/2;
        int painters=findFesible(boards,n,mid);
        if(painters<=m){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

int main(){
     int boards[]={10,20,30,40};
     int n=4;
     int m=2;

     cout<<"minimum time to paint board: "<<partition(boards,n,m)<<endl;

     return 0;
}