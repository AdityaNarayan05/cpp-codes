//indian coin change.
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
    cout<<"Enter no of denomination\n";
    cin>>n;

    vi a(n);
    cout<<"enter your denomination\n";
    rep(i,0,n){
        cin>>a[i];
    }
    int x;
    cout<<"enter your no\n";
    cin>>x;

    sort(a.begin(),a.end(),greater<int>());
    int ans=0;

    rep(i,0,n){
        ans+=x/a[i];
        x-=x/a[i] *a[i];
    }

    cout<<ans<<endl;

    return 0;
}