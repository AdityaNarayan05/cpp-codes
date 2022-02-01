//graph representation.
//adjency matrix method.
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
     
int main(){
    int n,m;
    cout<<"Enter no nodes and edges"<<endl;
    cin>>n>>m;

    vvi adjM(n+1,vi(n+1,0));

    rep(i,0,m){
        int x,y;
        cout<<"enter connection between nodes"<<endl;
        cin>>x>>y;
        adjM[x][y]=1;
        adjM[y][x]=1;
    }

    cout<<"Adjancency matrix of graph is given as:"<<endl;

    rep(i,1,n+1){
        rep(j,1,n+1){
            cout<<adjM[i][j]<<" ";
        }
        cout<<endl;
    }
    int n1,n2;
    cout<<"Find the edge or not\n";
    cin>>n1>>n2;
    if(adjM[n1][n2]==1){
        cout<<"Edge hae\n";
    }
    else{
        cout<<"Edge nahi hae\n";
    }
    return 0;
}