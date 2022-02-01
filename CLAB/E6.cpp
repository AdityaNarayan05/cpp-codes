//greedy fractional knapsack.
//BY : ADITYA NARAYAN JAISWAL.
//20U02065   lab 6
#include<bits/stdc++.h>
using namespace std;

//User defined snippets
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

bool compare(pii p1,pii p2){
    double v1=(double)p1.ff/p1.ss;
    double v2=(double)p2.ff/p2.ss;

    return v1>v2;
}

int main(){

    cout<<"BY: ADITYA NARAYAN JAISWAL 20U02065 LAB: 6"<<endl;
    int n;
    cout<<"enter no of objects"<<endl;
    cin>>n;

    vii a(n);
    cout<<"Enter profit and weight of object"<<endl;
    rep(i,0,n){
        cin>>a[i].ff>>a[i].ss;
    }
    int m;
    cout<<"Enter knapsack capacity"<<endl;
    cin>>m;
    
    sort(a.begin(),a.end(),compare);
    double ans=0;
    rep(i,0,n){
        if(m>=a[i].ss){
            ans+=a[i].ff;
            m-=a[i].ss;
            continue;
        }
        double vw=(double)a[i].ff/a[i].ss;
        ans+=vw*m;
        m=0;
        break;
    }
    rep(i,0,n){
        if(i==0){
            cout<<"profit of object      :  "<<a[i].ff<<"     "; 
        }
        else{
            cout<<a[i].ff<<"     ";
        }
    }
    cout<<endl;
    double t=ans;
    int j=1;
    rep(i,0,n){
        if(i==0){
            cout<<"fraction of weight in profit:"<<a[i].ff/ans<<" ";
            t-=a[i].ff;
        }
        else if(t>a[i].ff){
            cout<<a[i].ff/ans<<" ";
            t-=a[i].ff;
        }
        else if(t<=a[i].ff){
            cout<<t/ans<<" ";
            t=0;
        }
        else{
            cout<<"0"<<" ";
        }
    }
    cout<<endl;
    cout<<"maximum profit : "<<ans<<endl;
    return 0;
}