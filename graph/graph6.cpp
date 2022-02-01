//CYCLE DETECTION IN UNDIRECTED GRAPH
#include<bits/stdc++.h>
using namespace std;


bool isCycle(int s,vector<vector<int>> &adj,vector<bool> &vis,int parent){
    vis[s]=true;
    for(auto i : adj[s]){
        if(i !=  parent){
            if(vis[i]){
                return true;
            }
            if(!vis[i] and isCycle(i,adj,vis,s)){
                return true;
            }
        }
    }
}

int main(){
    int n,m;
    cout<<"Enter no of nodes and edges"<<endl;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cout<<"Enter connection between nodes"<<endl;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    bool cycle=false;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i] and isCycle(i,adj,vis,-1)){
            cycle=true; 
        }
    }

    if(cycle){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }
}