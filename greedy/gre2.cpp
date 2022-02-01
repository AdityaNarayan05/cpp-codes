//activity seleciton problem.
#include<bits/stdc++.h>
using namespace std;

//User defined snippets
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
     
int main(){
    int n;
    cout <<"Enter the no of activites"<<endl;
    cin>>n;

    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        int st,en;
        cin>>st>>en;
        v.push_back({st,en});
    }
    sort(v.begin(),v.end(),[&](vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    });
    int t=1;
    int en=v[0][1];
    rep(i,1,n){
        if(v[i][0]>=en){
            t++;
            en=v[i][1]; 
        }
    }
    cout<<t<<endl;

    return 0;
}