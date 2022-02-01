//Smallest sequence with sum k.
//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#include<set>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>

//User defined snippets
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
     
int main(){
    int n,k;
    cout<<"enter the size of array and value of sum"<<endl;
    cin>>n>>k;

    vi a(n);
    cout<<"enter your no"<<endl;
    rep(i,0,n){
        cin>>a[i];
    }
    priority_queue<int,vi> maxH;
    rep(i,0,n){
        maxH.push(a[i]);
    }
    int sum=0;
    int cnt=0;

    while(!maxH.empty()){
        sum+=maxH.top();
        maxH.pop();
        cnt++;
        if(sum>=k){
            break;
        }
    }
    if(sum<k){
        cout<<"-1"<<endl;
    }
    else{
        cout<<cnt<<endl;
    }
    return 0;
}