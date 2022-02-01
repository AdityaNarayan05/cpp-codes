//merge sort for linklist
//BY:ADITYA NARAYAN JAISWAL.
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
node* sortedMerge(node* &a,node* &b){
    node* result=NULL;

    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }

    if(a->data<b->data){
        result=a;
        result->next=sortedMerge(a->next,b);
    }
    else{
        result=b;
        result->next=sortedMerge(a,b->next);
    }
    return result;
}
void frontbackSplit(node* &head,node* &frontRef,node* &backRef){
    node* fast=head->next;
    node* slow=head;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }

    frontRef=head;
    backRef=slow->next;
    slow->next=NULL;
}
void mergeSort(node* &head){
    node* temp=head;
    node* a;
    node* b;

    if(temp==NULL || temp->next==NULL){
        return;
    }
    frontbackSplit(head,a,b);

    mergeSort(a);
    mergeSort(b);

    head=sortedMerge(a,b);
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
    int arr[]={7,9,2,6,8,1,3,4,5};
    for(int i=0;i<9;i++){
        insertAttail(head,arr[i]);
    }
    display(head);
    mergeSort(head);
    display(head);
    return 0;
}