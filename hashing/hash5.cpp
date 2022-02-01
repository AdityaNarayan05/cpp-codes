//min sum of k size subarray using SWT.
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
    int n,k;
    cout<<"Enter size and value of k\n";
    cin>>n>>k;

    vi a(n);
    cout<<"enter no in list"<<endl;
    rep(i,0,n){
        cin>>a[i];
    }
    int s=0;
    int ans=INT_MAX;
    rep(i,0,k){
        s+=a[i];
    }
    cout<<s<<" ";
    ans=min(ans,s);
    //sliding window 
    rep(i,k,n){
        s=s-a[i-k]; 
        s=s+a[i];
        cout<<s<<" ";
        ans=min(ans,s);
    }
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}  