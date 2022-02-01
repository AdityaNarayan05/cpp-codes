#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int lH=height(root->left);
    int rH=height(root->right);
    return max(lH,rH)+1;
}
bool isBalance(node* root){//O(n^2).
    if(root==NULL){
        return true;
    }
    if(isBalance(root->left)==false){
        return false;
    }
    if(isBalance(root->right)==false){
        return false;
    }
    int lH=height(root->left);
    int rH=height(root->right);
    if(abs(lH-rH)<=1){
        return true;
    }
    else{
        return false;
    }
}
bool isBalance(node* root,int* height){

    if(root==NULL){
        return true;
    }
    int lH=0,rH=0;
    if(isBalance(root->left,&lH)==false){
        return false;
    }
    if(isBalance(root->right,&rH)==false){
        return false;
    }
    *height=max(lH,rH)+1;
    if(abs(lH-rH)<=1){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    /*    1
         / \
        2   3
       / \ / \
      4  5 6  7
      */
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    node* n=new node(5);
    n->left=new node(2);
    n->right=new node(0);
    n->left->left=new node(7);
    n->left->left->right=new node(4);
 
    int h=0;
    if(isBalance(n,&h)){
        cout<<"tree is balance\n";
    }
    else{
        cout<<"tree is unbalanced \n";
    }
    
    return 0;
}