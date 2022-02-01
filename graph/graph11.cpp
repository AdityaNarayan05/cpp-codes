//KRUSKAL'S ALGORITHM USING DSU.
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+6;
vector<int> parent(N);
vector<int> sz(N);

void make_set(int v){//code for DSU
    parent[v]=v;
    sz[v]=1;
}

int find_set(int v){//code for DSU
    if(v==parent[v]){
        return v;
    }
    return parent[v]=find_set(parent[v]);
}
void union_set(int a,int b){//code for DSU.
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        parent[b]=a;
        sz[a]+=sz[b];
    }
}
int main(){
    for(int i=0;i<N;i++){
        make_set(i);
    }
    int n,m;
    cout<<"Enter no of nodes and edges"<<endl;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cout<<"Enter connection between nodes and their weight"<<endl;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());//Sorting all the edges in decreasing order.
    int cost=0;
    for(auto i: edges){
        int w=i[0];
        int u=i[1];
        int v=i[2];
        int x=find_set(u);
        int y=find_set(v);
        if(x==y){
            continue;
        }
        else{
            cout<<u<<"  "<<v<<endl;
            cost+=w;
            union_set(u,v);
        }
    }
    cout<<"MCST COST IS:"<<cost<<endl;
    return 0;
}