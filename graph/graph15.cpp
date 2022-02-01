//Floyd Warshall Algorithm.
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
const int inf=1e9;

int main(){
    vector<vector<int>> M={{0,5,inf,10},
                           {inf,0,3,inf},
                           {inf,inf,0,1},
                           {inf,inf,inf,0}};
    int n=M.size();                       
    vector<vector<int>> d=M;
    rep(k,0,n){
        rep(i,0,n){
            rep(j,0,n){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    rep(i,0,n){
        rep(j,0,n){
            if(d[i][j]==inf){
                cout<<"#"<<"  ";//#->infinity.
            }else{
                cout<<d[i][j]<<"  ";
            }
            
        }
        cout<<endl;
    }
    //d[1][3] ka sortest path
    
    return 0;
}