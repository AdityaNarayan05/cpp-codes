//Heap Stl
#include<bits/stdc++.h>
using namespace std;

//User defined snippets
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
     
int main(){
    
    priority_queue<int,vector<int>> pq;
    pq.push(2);
    pq.push(3);
    pq.push(1);

    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    cout<<endl; 
    priority_queue<int,vector<int>,greater<int>> p;
    p.push(15);
    p.push(10);
    p.push(5);
    p.push(7);

    cout<<p.top()<<endl;
    p.pop();
    cout<<p.top()<<endl;

    return 0;
}