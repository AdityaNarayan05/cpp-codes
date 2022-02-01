//Median of Running stream.
#include<bits/stdc++.h>
using namespace std;

//User defined snippets
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)

priority_queue<int,vector<int>> pMax;
priority_queue<int,vector<int>,greater<int>> pMin;

void insert(int a){
    if(pMin.size() ==pMax.size()){
        if(pMax.size()==0){
            pMax.push(a);
            return;
        }

        if(a<pMax.top()){
            pMax.push(a);
        }
        else{
            pMin.push(a);
        }
    }
    else{
        //two cases possible.
        //case 1:size of maxHeap>size of minHeap
        //case 2:size of minHeap>size of maxHeap
        if(pMax.size()>pMin.size()){
            if(a>=pMax.top()){
                pMin.push(a);
            }
            else{
                int temp=pMax.top();
                pMax.pop();
                pMin.push(temp);
                pMax.push(a);
            }
        }
        else{
            if(a<=pMin.top()){
                pMax.push(a);
            }
            else{
                int t=pMin.top();
                pMin.pop();
                pMax.push(t);
                pMin.push(a);
            }
        }
    }
}  

double median(){
    if(pMin.size()==pMax.size()){
        return (pMin.top()+pMax.top())/2.0;
    } 
    else if(pMax.size()>pMin.size()){
        return pMax.top();
    }
    else{
        return pMin.top();
    }
}

int main(){
    cout<<"enter the size of list"<<endl;
    int m;
    cin>>m;
    cout<<"enter your no."<<endl;
    rep(i,0,m){
        int n;
        cin>>n;
        insert(n);
        cout<<median()<<endl;
    }
    
        
    return 0;
}