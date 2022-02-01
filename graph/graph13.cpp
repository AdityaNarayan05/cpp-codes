//Dijkstra Algorithm
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
const int inf=1e7;
     
int main(){
    int n,m;
    cout<<"Enter no of nodes and edges"<<endl;
    cin>>n>>m;
    vi dist(n+1,inf);
    vector<vector<pair<int,int>>> graph(n+1);
    rep(i,0,m){
        int u,v,w;
        cout<<"Enter connection between nodes and their weight"<<endl;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    int source;
    cout<<"Enter your source"<<endl;
    cin>>source;
    dist[source]=0;
    set<pair<int,int>> s;
    //{wt,vertex}
    s.insert({0,source});
    while(!s.empty()){
        auto x=*(s.begin());
        s.erase(x);
        for(auto it :graph[x.ss]){
            if(dist[it.ff]>dist[x.ss]+it.ss){
                s.erase({dist[it.ff],it.ff});
                dist[it.ff]=dist[x.ss]+it.ss;
                s.insert({dist[it.ff],it.ff});
            }
        }
    }
    rep(i,1,n){
        if(dist[i]<inf){
            cout<<dist[i]<<" ";
        }
        else{
            cout<<-1<<" ";
        }
    }
    cout<<endl;
    return 0;
}