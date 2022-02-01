//Connected components of Graph.
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

vector<bool> vis;
int n,m;
vvi adj;
vi comp;

int get_comp(int idx){
    if(vis[idx]){
        return 0;
    } 
    vis[idx]=true;
    int ans=1;
    for(auto i : adj[idx]){
        if(!vis[i]){
            ans+=get_comp(i);
            vis[i]=true;
        }
    }
    return ans;
}

int main(){
    cout<<"Enter the no nodes and edges"<<endl;
    cin>>n>>m;
    adj=vector<vector<int>>(n);
    vis=vector<bool>(n,0);
    rep(i,0,m){
        int u,v;
        cout<<"Enter connection between nodes"<<endl;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    rep(i,0,n){
        if(!vis[i]){
            comp.push_back(get_comp(i));
        }
    }
    for(auto i : comp){
        cout<<i<<" ";
    }
    cout<<endl;
    //soln Q2
    long long a=0;
    for(auto i : comp){
        a += i*(n-i);
    }
    cout<<(a/2);

    return 0;
}