//bipartite Graph
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

vvi adj;
vector<bool> vis;
vi col;
bool bipart;

void colour(int u,int curr){
    if(col[u] !=-1 and col[u]!=curr){
        bipart=false;
        return;
    }
    col[u]=curr;
    if(vis[u]){
        return;
    }
    vis[u]=true;
    for(auto i :adj[u]){
        colour(i,curr xor 1);
    }
}

int main(){
    bipart=true;
    int n,m;
    cout<<"Enter no nodes and edges"<<endl;
    cin>>n>>m;
    adj=vector<vector<int>>(n);
    vis=vector<bool>(n,false);
    col=vector<int>(n,-1);
    rep(i,0,m){
        int u,v;
        cout<<"Enter the connection of node to node"<<endl;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i,0,n){
        if(!vis[i]){
            colour(i,0);
        }
    }
    if(bipart){
        cout<<"Graph is bipartite"<<endl;
    }
    else{
        cout<<"Graph is not bipartite"<<endl;
    }
    return 0;
}