//Expendition of cow's via truck.
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
    int t;
    cout<<"no test case"<<endl;
    cin>>t;
    while(t--){
        int n;
        cout<<"Enter no stops"<<endl;
        cin>>n;

        vii a(n);
        cout<<"Enter distance from start and fuel avilable"<<endl;
        rep(i,0,n){
            cin>>a[i].ff>>a[i].ss;
        }
        int l,p;
        cout<<"Enter total distance and initial fuel"<<endl;
        cin>>l>>p;
        
        rep(i,0,n){
            a[i].ff=l-a[i].ff;
        }
        sort(a.begin(),a.end());

        int ans=0;
        int curr=p;

        priority_queue<int,vector<int>> maxH;
        bool flag=0;
        rep(i,0,n){
            if(curr>=l){
                break;
            }
            while(curr<a[i].ff){
                if(maxH.empty()){
                    flag=1;
                    break;
                }
                ans++;
                curr+=maxH.top();
                maxH.pop();
            }
            if(flag){
                break;
            }
            maxH.push(a[i].ss);
        }
        if(flag){
            cout<<"-1"<<endl;
            continue;
        }

        while(!maxH.empty()&&curr<l){
            curr+=maxH.top();
            maxH.pop();
            ans++;
        }

        if(curr<l){
            cout<<"-1"<<endl;
            continue;
        }

        cout<<ans<<endl;
    }
    return 0;
}