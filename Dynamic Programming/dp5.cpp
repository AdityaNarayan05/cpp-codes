//Longest increasing subsequence.
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

int lis(vi &a,int n){
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=1;//single element is also lis

    rep(i,0,n){
        if(a[n]>a[i]){
            dp[n]=max(dp[n],1+lis(a,i));
        }
    }

    return dp[n];
}

int main(){
    rep(i,0,N){
        dp[i]=-1;
    }
    int n;
    cout<<"Enter size of list"<<endl;
    cin>>n;

    vi a(n);
    cout<<"Enter no in list"<<endl;
    rep(i,0,n){
        cin>>a[i];
    }

    //cout<<lis(a,n-1)<<endl;//using memoiztion

    vi d(n,1);

    int ans=0;
    rep(i,1,n){
        rep(j,0,i){
            if(a[i]>a[j]){
                d[i]=max(d[i],1+d[j]);
            }
            ans=max(ans,d[i]);
        }
    }
    cout<<ans<<endl;

    return 0;
}