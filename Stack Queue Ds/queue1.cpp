#include<iostream>
using namespace std;

#define n 20

class queue{
    int* arr;
    int front,back;

    public:
    queue(){
        arr=new int[n];
        front=-1;
        back=-1;
    }
    void QInsert(int x){
        if(front==1&&back==n-1){
            cout<<"overflow"<<endl;
            return;
        }
        if(front==-1){
            front=1;
            back=1;
        }
        else if(back==n-1){
            back=0;
        }
        else{
            back++;
        }
        arr[back]=x;
    }
    void QDelete(){
        if(front==-1){
            cout<<"underflow"<<endl;
            return;
        }
        int a=arr[front];

        if(front==back){
            front=-1;
            back=-1;
        }
        else if(front==n-1){
            front=0;
        }
        else{
            front++;
        }
        return;
    }

    int peek(){
        if(front==-1||front>back){
            cout<<"underflow"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool empty(){
        if(front==-1||front>back){
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
    q.QDelete();
    if(q.empty()){
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<"queue has element"<<endl;
    }
    return 0;
}