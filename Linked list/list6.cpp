 #include"bits/stdc++.h"
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

void insertAttail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;//only one node so directly adding it.
        return; 
    }

    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;//adding node at end of list
}
int length(node* &head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}
node* kappend(node* &head,int k){
    node* newHead;
    node* newTail;
    node* tail=head;

    int l=length(head);
    k=k%l;

    int count=1;
    while(tail->next!=NULL){
        if(count==l-k){
           newTail=tail;
        }
        if(count==l-k+1){
           newHead=tail;
        }
        tail=tail->next;
        count++;
    }
   newTail->next=NULL;
   tail->next=head;
   return newHead;
}
void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    insertAttail(head,1);
    insertAttail(head,2);
    insertAttail(head,3);
    insertAttail(head,4);
    insertAttail(head,5);
    insertAttail(head,6);
    display(head);
    node* newhead=kappend(head,3);
    display(newhead);
    return 0;
}
