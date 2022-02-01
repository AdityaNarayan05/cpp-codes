#include<iostream>
#include<set>
#include<unordered_set> 
using namespace std;

int main(){
    multiset<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    for(auto i: s){
        cout<<i<<" ";
    }
    cout<<endl;
    s.insert(5);
    for(auto i: s){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<s.size()<<endl;
    s.erase(2);
    s.erase(s.begin());
    for(auto i: s){
        cout<<i<<" ";
    }
    cout<<endl;
    unordered_set<int> a;
    
    a.insert(1);
    a.insert(2);
    a.insert(4);
    a.insert(5);
    a.insert(12);
    a.insert(15);
    for(auto i: a){
        cout<<i<<" ";
    }
    cout<<endl;
    s.insert(5);
    for(auto i: a){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}