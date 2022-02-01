#include"bits/stdc++.h"
using namespace std;

class node{
    public :
    int data;
    node* next;

    node(int val ){
        data =val;
        next=NULL;
    }
};


void insertAtTail( node* &head,int val){
    node* n=new node(val); //creating new node
    if (head==NULL){
        head =n;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;//adding new node
}
void insertAtHead(node* &head,int data){
    node* l=new node(data);
    l->next=head;
    head=l;
}

bool search(node* head ,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;

}
void display (node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void deleteAthead(node* &head){
    node* todelete=head;
    head=head->next;

    delete todelete;
}
void deletion(node* &head,int val){
    if (head==NULL){
        return;
    }
    if(head->next==NULL)
    {
        deleteAthead(head);
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
}


int main()
{
   node* head=NULL;
   insertAtTail(head,10);
   insertAtTail(head,15);
   insertAtTail(head,25);
   insertAtTail(head,30);
   //display(head);
   
   insertAtTail(head,45);
    insertAtHead(head,124);
   display(head);
  // int i;
   //cout<<"enter the no you want to search"<<endl;
   //cin>>i;
   //cout<<search(head,i);
   deletion(head,25);
   display(head);
   deletion(head,45);
   display(head);
   deleteAthead(head);
   display(head);
}