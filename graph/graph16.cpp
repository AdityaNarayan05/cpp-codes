//snake and Ladder
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=0;i<b;i++)

int main(){
    int l,s;
    cout<<"Enter no of Ladders and snakes"<<endl;
    cin>>l>>s;
    map<int,int> ld;
    map<int,int> sn;
    rep(i,0,l){
        int u,v;
        cout<<"Enter starting and ending edge of Ladder"<<endl;
        cin>>u>>v;
        ld[u]=v; 
    }
    rep(i,0,s){
        int u,v;
        cout<<"Enter mouth and tail of Snake"<<endl;
        cin>>u>>v;
        sn[u]=v; 
    }
    int m=0;
    queue<int> q;
    q.push(1);
    bool found=false;
    vector<int> vis(101,0);
    vis[1]=true;
    while(!q.empty() and !found){
        int sz=q.size();
        while(sz--){
            int t=q.front();
            q.pop();
            rep(die,1,7){
                if(t+die==100){
                    found =true;
                }
                if(t+die<=100 and ld[t+die] and !vis[ld[t+die]]){
                    vis[ld[t+die]]=true;
                    if(ld[t+die]==100){
                        found=true;
                    }
                    q.push(ld[t+die]);
                }
                else if(t+die<=100 and sn[t+die] and !vis[sn[t+die]]){
                    vis[sn[t+die]]=true;
                    if(sn[t+die]==100){
                        found=true;
                    }
                    q.push(sn[t+die]);
                }
                else if(t+die<=100 and !sn[t+die] and !ld[t+die]and !vis[t+die]){
                    vis[t+die]=true;
                    q.push(t+die);
                }
            }
        }
        m++;
    }
    if(found){
        cout<<m;
    }
    else{
        cout<<-1;
    }


    return 0;
}