//NAME: ADITYA NARAYAN JAISWAL
//ROLL NO: 20U02065
#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"NAME: ADITYA NARAYAN JAISWAL"<<endl;
    cout<<"roll no :20U02065"<<endl;
    int n;
    cout<<"Enter no of objects"<<endl;
    cin>>n;
    int p[n+1],wt[n+1];
    p[0]=0;
    wt[0]=0;
    for(int i=1;i<=n;i++){
        cout<<"Enter weight and their value"<<endl; 
        cin>>wt[i]>>p[i];
    }
    int m;
    cout<<"Enter knapsack capacity"<<endl;
    cin>>m;
    vector<vector<int>> k(n + 1, vector<int>(m + 1));

    for(int i=0;i<=n;i++){
        for(int w=0;w<=m;w++){
            if(i==0 or w==0){
                k[i][w]=0;
            }
            else if(wt[i]<=w){
                k[i][w]=max(p[i]+k[i-1][w-wt[i]],k[i-1][w]);
            }
            else{
                k[i][w]=k[i-1][w];
            }
        }
    }

    cout<<k[n][m]<<endl;

    return 0;
}