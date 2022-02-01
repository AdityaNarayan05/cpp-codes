//topological sort
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
int main(){
    int n,m;
    cout<<"Enter no nodes and edges"<<endl;
    cin>>n>>m;
    int cnt=0;
    vector<vector<int>> adj(n);
    vector<int> id(n,0);
    rep(i,0,m){
        int u,v;
        cout<<"Enter the connection of node to node"<<endl;
        cin>>u>>v;//u-->v
        adj[u].push_back(v);
        id[v]++;
    }

    queue<int> pq;
    rep(i,0,n){
        if(id[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        cnt++;
        int x=pq.front();
        pq.pop();
        cout<<x<<" ";//x--->v
        for(auto it:adj[x]){
           id[it]--;
           if(id[it]==0){
               pq.push(it);
           } 
        }
    }
    return 0;
}