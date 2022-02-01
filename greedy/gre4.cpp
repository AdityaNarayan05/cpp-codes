//optimal pattern merge
#include<bits/stdc++.h>
using namespace std;

//User defined snippets
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
     
int main(){
    int n;
    cout<<"Enter no element in list"<<endl;
    cin >>n;

    vi a(n);
    cout<<"Enter your number"<<endl;
    rep(i,0,n){
        cin>>a[i];
    }
    priority_queue<int,vector<int>,greater<int>> mHeap;
    rep(i,0,n){
        mHeap.push(a[i]);
    }
    int ans=0;
    while(mHeap.size()>1){
        int n1=mHeap.top();
        mHeap.pop();
        int n2=mHeap.top();
        mHeap.pop();
        ans+=n1+n2;
        mHeap.push(n1+n2);
    }
    cout<<ans<<endl;
    return 0;
}