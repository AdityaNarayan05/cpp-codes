#include<iostream>
#include<climits>
//#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left,*right;
    node(int val){
        int data ;
        left=NULL;
        right=NULL;
    }
};
struct info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};
info largestBst(node* root){
    if(root==NULL){
        return {0,INT_MAX,INT_MIN,0,true};
    }
    if(root->left==NULL && root->right==NULL){
        return(1,root->data,root->data,1,true);
    }

    info linfo=largestBst(root->left);
    info rinfo=largestBst(root->right);

    info curr;
    curr.size=(1+ linfo.size + rinfo.size);

    if(linfo.isBST && rinfo.isBST && linfo.max < root->data && rinfo.min > root->data){
        curr.min=min(linfo.min,min(rinfo.min,root->data));
        curr.max=max(rinfo.max,max(rinfo.max,root->data));

        curr.ans=curr.size;
        curr.isBST=true;

        return curr;
    }
    curr.ans=max(linfo.ans,rinfo.ans); 
    curr.isBST=false;
    return curr;
}
int main(){
    node* root=new node(5);
    root->left=new node(3);
    root->left->left=new node(2);
    root->left->right=new node(4);
    root->right=new node(6);

    cout<<"Largest BST in BT :"<<largestBst(root).ans<<endl;

    return 0;
}