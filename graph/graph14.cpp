//Bellman ford algorithm.
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
const int inf=1e9;
     
int main(){
    int n,m;
    cout<<"Enter no nodes and edges"<<endl;
    cin>>n>>m;
    vvi edges;
    rep(i,0,m){
        int u,v,w;
        cout<<"Enter connection between nodes and their weights"<<endl;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    int src;
    cout<<"Enter your source"<<endl;
    cin>>src;
    vi dist(n,inf);
    dist[src]=0;
    rep(i,0,n-1){
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            dist[v]=min(dist[v],w+dist[u]);
        }
    }
    for(auto i : dist){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}