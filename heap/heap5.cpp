//Merge K sorted arrays.
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
    int k;
    cout<<"enter no of arrays."<<endl;
    cin>>k;

    vector<vector<int>> a(k);

    rep(i,0,k){
        cout<<"enter size of array :"<<i+1<<endl;
        int size;
        cin>>size;

        a[i]=vector<int>(size);
        cout<<"enter no in array"<<endl;
        rep(j,0,size){
            cin>>a[i][j];
        }
    }
    vector<int> idx(k,0);
    priority_queue<pii,vector<pii>,greater<pii>> minH;

    rep(i,0,k){
        pii p;
        p.ff=a[i][0];
        p.ss=i;
        minH.push(p); 
    }
    vi ans;

    while(!minH.empty()){
        pii x=minH.top();
        minH.pop();
        ans.push_back(x.ff);

        if(idx[x.ss]+1<a[x.ss].size()){
            pii p;
            p.ff=a[x.ss][idx[x.ss]+1];
            p.ss=x.ss;
            minH.push(p);
        }
        idx[x.ss]+=1;
    }

    rep(i,0,ans.size()){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}