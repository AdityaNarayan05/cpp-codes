#include"bits/stdc++.h"
using namespace std;

class node{//class for doubly linked list
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}

void insertAttail(node* &head,int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }

    node* n=new node(val);
    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;//adding node at end of list
    n->prev=temp;

}
 void display(node* &head){
     node* temp=head;
     while(temp!=NULL){
         cout<<temp->data<<"  ";
         temp=temp->next;
     }
     cout<<endl;

     
}
void deleteAtHead(node* &head){//dleteing node at head or at position 1.
    node* todelete=head;
    head=head->next;
    head->prev=NULL;

    delete todelete;
}
void deletion(node* head,int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }

    node* temp=head;
    int count=1;

    while(temp!=NULL&&count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){//if we want to delete last element of ddubly list.
        temp->next->prev=temp->prev;
    }
    
    

    delete temp;
}

int main(){
    node* head=NULL;
    insertAttail(head,1);
    insertAttail(head,2);
    insertAttail(head,3);
    insertAttail(head,4);
    display(head);
    insertAtHead(head,5);
    display(head);
    int p;
    cout<<"enter the position  at which you want to delete"<<endl;
    cin>>p;
    deletion(head,p);
    display(head);

    return 0;
    

}
