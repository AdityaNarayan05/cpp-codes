#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};
class queue{
    node* front;
    node* back;
    public:
    queue(){
        front=NULL;
        back=NULL;
    }
    void QInsert(int x){
        node* n=new node(x);
        if(front==NULL){
            back=n;
            front=n;
            return;
        }
        back->next=n;
        back=n;
    }
    void QDelete(){
        if(front==NULL){
            cout<<"queue underflow"<<endl;
            return;
        }
        node* nn=front;
        front=front->next;

        delete nn;
    }
    int peek(){
        if(front==NULL){
            cout<<"queue underflow"<<endl;
            return -1;
        }
        return front->data;
    }
    bool empty(){
        if(front==NULL){
            return true;
        }
        return false;
    }
};
int main(){
    queue q;
    q.QInsert(1);
    q.QInsert(5);
    q.QInsert(8);
    q.QInsert(12);
   
    cout<<q.peek()<<endl;
    q.QDelete();
    cout<<q.peek()<<endl;
    q.QDelete();
    cout<<q.peek()<<endl;
    q.QDelete();
    cout<<q.peek()<<endl;
    //q.QDelete();
    if(q.empty()){
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<"queue has element"<<endl;
    }
    return 0;
}