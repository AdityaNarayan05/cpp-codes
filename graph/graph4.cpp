//DFS IT IS IMPLEMENTED USING STACKS.
//Aditya narayan jaiswal
//20U02065
#include<bits/stdc++.h>

using namespace std;
#define rep(i,a,b) for(int i=0;i<n;i++)
const int N=1e5+2;
bool vis[N];
vector<int> adj[N];

void dfspreorder(int n){
    cout<<"Aditya narayan jaiswal 20U02065"<<endl;
    //preorder
    vis[n]=1;
    cout<<n<<" ";

    //inorder
    vector<int> ::iterator it;
    for(it=adj[n].begin();it!=adj[n].end();it++){
        if(vis[*it]);
        else{
            dfspreorder(*it);
        }
    }
}

void dfspostorder(int n){
    vis[n]=1;
    
    //inorder
    vector<int> ::iterator it;
    for(it=adj[n].begin();it!=adj[n].end();it++){
        if(vis[*it]);
        else{
            dfspostorder(*it);
        }
    }

    //postorder
    cout<<n<<" ";

}

int main(){
    int n,m;
    cout<<"Enter no nodes and edges "<<endl;
    cin>>n>>m;
    rep(i,0,n){
        vis[i]=0;
    }
    rep(i,0,m){
        int x,y;
        cout<<"Enter connection between nodes"<<endl;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //dfspreorder(1);
    //cout<<endl;
    dfspostorder(1);
    cout<<endl;
    return 0;
}