//queue using stack via using 2array.
#include<bits/stdc++.h>
using namespace std;
class que{//compiler can get confusion as we are using stdc++.h
    stack<int> s1;
    stack<int> s2;
    
    public:
    void QInsert(int x){
        s1.push(x);
    }
    int QDelete(){
        if(s1.empty()&&s2.empty()){
            cout<<"underflow\n";
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval=s2.top();
        s2.pop();
        return topval;
    }
    bool empty(){
        if(s1.empty()&&s2.empty()){
            return true;
        }
    }
};
int main(){
    que q;
    q.QInsert(1);
    q.QInsert(4);
    q.QInsert(7);
    q.QInsert(12);
   
    cout<<q.QDelete()<<endl;
    cout<<q.QDelete()<<endl;
    cout<<q.QDelete()<<endl;
    cout<<q.QDelete()<<endl;
    cout<<q.QDelete()<<endl;
    if(q.empty()){
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<"queue has element"<<endl;
    }
    return 0;
}
