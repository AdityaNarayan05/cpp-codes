//Coin change problem with dp.
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

const int N=1e3+2;
int dp[N][N];

int coin(vi &a,int n,int x){
    if(x==0){
        return 1;
    }
    if(x<0){
        return 0;
    }
    if(n<=0){
        return 0;
    }
    if(dp[n][x] !=-1){
        return dp[n][x];
    }
    dp[n][x]=coin(a,n,x-a[n-1])+coin(a,n-1,x);
    return dp[n][x];
}

int main(){

    rep(i,0,N){
        rep(j,0,N){
            dp[i][j]=-1;
        }
    }
    
    int n;
    cout<<"Enter no of coins"<<endl;
    cin>>n;
    vi a(n);
    rep(i,0,n){
        cout<<"Enter your coin"<<endl;
        cin>>a[i];
    }
    int x;
    cout<<"Enter your no"<<endl;
    cin>>x;

    //cout<<coin(a,n,x)<<endl;

    vvi d(n+1,vi(x+1,0));
    d[0][0]=1;
    rep(i,1,n+1){
        rep(j,0,x+1){
            if(j-a[i-1]>=0){
                d[i][j]+=d[i][j-a[i-1]];
            }
            d[i][j]+=d[i-1][j];
        }
    }
    cout<<d[n][x]<<endl;

    return 0;
}