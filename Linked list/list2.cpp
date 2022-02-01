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
void insertAtHead(node* &head,int val){
    node* n=new node(val); 
    n->next=head;
    head=n;
}
node* reverse(node* &head){
    node* prevptr=NULL;
    node*currptr=head;
    node* nxtptr;

    while(currptr!=NULL){
        nxtptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nxtptr;
    }
    return prevptr;
}

node* reverseRecursive(node* &head){//eversing using recuursive technique.
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newhead=reverseRecursive(head->next);
    head->next->next=head;
    
    head->next=NULL;

    return newhead;
     
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
    insertAtHead(head,10);
    display(head);

    //node* newhead=reverse(head);
    //display(newhead);

    node* newhead=reverseRecursive(head);
    display(newhead);
     return 0;
}