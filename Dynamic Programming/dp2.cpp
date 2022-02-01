//Minimum Number of squares
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
const int N=1e5+2,MOD=1e9+7;
int dp[N];

int square(int n){
    if(n==1 or n==2 or n==3 or n==0){
        return n;
    }
    if(dp[n]!=MOD){
        return dp[n];
    }
    for(int i=1;i*i<=n;i++){
        dp[n]=min(dp[n],1+square(n-i*i));
    }
    return dp[n];
}
int main(){
    //rep(i,0,N){
    //    dp[i]=MOD;
    //}
    int n;
    cout<<"Enter your no"<<endl;
    cin>>n;
    vi d(n+1,MOD);

    d[0]=0;
    d[1]=1;
    d[2]=2;
    d[3]=3;
    for(int i=1;i*i<=n;i++){
        for(int j=0;i*i+j<=n;j++){
            d[i*i+j]=min(d[i*i+j],1+d[j]);
       }
    }
    cout<<d[n]<<endl;
    //cout<<square(n)<<endl;

    
    return 0;
}