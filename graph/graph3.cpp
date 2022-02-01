//BFS IT IS IMPLEMENTED USING QUEUE.
//Aditya Narayan jaiswal
//20U02065
#include<bits/stdc++.h>
using namespace std;

//User defined snippets
#define rep(i,a,b) for(int i=a;i<b;i++)

const int N=1e5+2;
bool vis[N];
vector<int> adj[N];
     
int main(){
    cout<<"Aditya narayan jaiswal 20U02065"<<endl;
    rep(i,0,N){
        vis[i]=0;
    }
    int n,m;
    cout<<"Enter no nodes and edges "<<endl;
    cin>>n>>m;
    rep(i,0,m){
        int x,y;
        cout<<"Enter connection between nodes"<<endl;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vis[1]=true;
    
    cout<<"BFS ORDER IS:";
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";

        vector<int>::iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++){
            if(!vis[*it]){
                vis[*it]=1;
                q.push(*it);
            }
        }
    }
    cout<<endl;

    return 0;
}