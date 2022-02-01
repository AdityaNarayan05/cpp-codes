//top most frequent element.
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
    cout<<"Enter the size and value of k"<<endl;
    cin>>n>>k;
    vi a(n);
    cout<<"Enter your no"<<endl;
    rep(i,0,n){
        cin>>a[i];
    }

    map<int,int> f;
    rep(i,0,n){
        int preSize=f.size();
        if(f[a[i]]==0 && preSize==k){
            break;
        }
        f[a[i]]++;
    }

    vii ans;
    map<int,int> ::iterator it;
    for(it=f.begin();it!=f.end();it++){
        if(it->ss!=0){
            pii p;
            p.ff=it->ff;
            p.ss=it->ss;
            ans.push_back(p);
        }
    }

    sort(ans.begin(),ans.end(),greater<pii>());

    vii::iterator it1;
    for(it1=ans.begin();it1!=ans.end();it1++){
        cout<<it1->ff<<" "<<it1->ss<<" "<<endl;
    }
    return 0;
}