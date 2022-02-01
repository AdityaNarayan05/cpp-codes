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
node* reversek(node* &head,int k){

    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL&&count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next=reversek(nextptr,k);
    }
    return prevptr;
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

    node* newhead=reversek(head,2);
    display(newhead);
    return 0;
}
