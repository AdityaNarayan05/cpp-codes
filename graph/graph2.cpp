//Adjency list method of graph representation.
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
vi adj[N];
int main(){
    int n,m;
    cout<<"Enter no nodes and edges "<<endl;
    cin>>n>>m;
    rep(i,0,m){
        cout<<"Enter connection between nodes"<<endl;
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<"Adjency list of above graph is given as"<<endl;
    rep(i,1,n+1){
        cout<<i<<"->";
        //vector<int> ::iterator it;
        //for(it=adj[i].begin();it!=adj[i].end();it++){
        //    cout<<*it<<" ";
        //}
        for(int x:adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;

    }
     
    return 0;
}