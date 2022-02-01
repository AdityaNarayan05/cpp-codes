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

void makecycle(node* &head,int pos){
    node* temp=head;
    node* startnode;

    int count=1;
    while(temp->next!=NULL){

        if(count==pos){
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

bool dectectcycle(node* &head){
    node* slow=head;
    node* fast=head;

    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}

void breakcycle(node* &head){
    node* slow=head;
    node* fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }while (slow!=fast);

    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }

    slow->next=NULL;
    
    

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
    insertAttail(head,7);
    insertAttail(head,8);
    insertAttail(head,9);
    insertAttail(head,10);
    insertAttail(head,11);
    insertAttail(head,12);
    int p=5;
    makecycle(head,p);
    if(dectectcycle(head)){
        cout<<"there is cycle in list at  "<<p<<"th position"<<endl;
        breakcycle(head);
        display(head);
    }
    else{
        cout<<"there is no cycle in list"<<endl; 
        display(head);
    }
    return 0;
}