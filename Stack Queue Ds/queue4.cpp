 //queue using stack via one stack array and another in recursion.
 //#include<iostream>
 //#include<stack>
 #include<bits/stdc++.h>
 using namespace std;

 class que{
     stack<int> s1;
     public:
     void QInsert(int x){
         s1.push(x);
     }
     int QDelete(){
         if(s1.empty()){
             cout<<"underflow\n";
             return -1;
         }  
         int x=s1.top();
         s1.pop();
         if(s1.empty()){
             return x;
         }
         int item=QDelete();
         s1.push(x);
         return item;
         
     }
     bool empty(){
         if(s1.empty()){
             return true;
         }
         return false;
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