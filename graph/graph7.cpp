//cycle detection in directed graph.
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

bool isCycle(int src,vector<vector<int>> &adj,vector<bool> &vis,vector<int> &stack){
    stack[src]=true;
    if(!vis[src]){
        vis[src]=true;
        for(auto i :adj[src]){
            if(!vis[i] and isCycle(i,adj,vis,stack)){
                return true;
            }
            if(stack[i]){
                return true;
            }
        }
    }
    stack[src]=false;
    return false;
}

int main(){
    int n,m;
    cout<<"Enter no nodes and edges"<<endl;
    cin>>n>>m;
    vvi adj(n);
    rep(i,0,m){
        int u,v;
        cout<<"Enter the connection of node to node"<<endl;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool cy=false;
    vi stack(n,0);
    vector<bool> vis(n,0);
    rep(i,0,n){
        if(!vis[i] and isCycle(i,adj,vis,stack)){
            cy=true;
        }
    }
    if(cy){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }
    return 0;
}