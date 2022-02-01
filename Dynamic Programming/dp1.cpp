//Fibonacci Sequence
#include<bits/stdc++.h>
using namespace std;

//User defined snippets
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

const int N=1e5+2;
int dp[N];

int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n]; 
    }
    dp[n]=fib(n-1)+fib(n-2);
    return dp[n];
}

int main(){
    int n;
    cout<<"Enter your no"<<endl;
    cin>>n;
    //Memoization method
    rep(i,0,N){
        dp[i]=-1;
    }
    rep(i,0,n)
        cout<<fib(i)<<" "; 
    cout<<endl;
    //Tabulation method
    vi d(n+1);
    d[0]=0;
    d[1]=1;
    d[2]=1;
    rep(i,3,n+1){
        d[i]=d[i-1]+d[i-2];
    }
    rep(i,0,n)
        cout<<d[i]<<" "; 
    cout<<endl;    
    return 0;
}