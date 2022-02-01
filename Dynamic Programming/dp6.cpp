//longest common subsequence.
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
     
const int N=1e3+2,MOD=1e9+7;
int dp[N][N];
int lcs(string &s1,string &s2,int n,int m){
    if(n==0 or m==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(s1[n-1]==s2[m-1]){
        dp[n][m]=1+lcs(s1,s2,n-1,m-1);
    }
    else{
        dp[n][m]=max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
    }

    return dp[n][m];
}
     
int main(){
    rep(i,0,N){
        rep(j,0,N){
            dp[i][j]=-1;
        }
    }
    string s1,s2;
    cout<<"Enter your strings"<<endl;
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    //cout<<lcs(s1,s2,n,m)<<endl;
    
    //tabulation.
    vvi d(n+1,vi(m+1,-1));
    rep(i,0,n+1){
        rep(j,0,m+1){
            if(i==0 or j==0){
                d[i][j]=0;
                continue;
            }
            if(s1[i-1]==s2[j-1]){
                d[i][j]=1+d[i-1][j-1];
            }
            else{
                d[i][j]=max(d[i][j-1],d[i-1][j]);
            }
        }
    }
    cout<<d[n][m]<<endl;

    return 0;
}