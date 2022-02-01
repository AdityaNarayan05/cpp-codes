//maximum and minimum difference.
#include<bits/stdc++.h>
using namespace std;

//User defined snippets
#define vi vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
     
int main(){
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    vi a(n);
    cout<<"Enter no in list"<<endl;
    rep(i,0,n){
        cin>>a[i];
    }

    sort(a.begin(),a.end());
    long long max=0;
    int min=0;
    rep(i,0,n/2){
        max+=(a[i+n/2]-a[i]);
        min+=(a[2*i+1]-a[2*i]); 
    }
    cout<<"maximum :"<<max<<endl;
    cout<<"minimum :"<<min<<endl;
    return 0;
}