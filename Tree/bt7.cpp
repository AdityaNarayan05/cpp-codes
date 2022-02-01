//replacing nodes withs their sum and vales at there subtree.
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
void sumNode(node* root){
    if(root==NULL){
        return;
    }
    sumNode(root->left);
    sumNode(root->right);
    if(root->left!=NULL){
        root->data+=root->left->data;
    }
    if(root->right!=NULL){
        root->data+=root->right->data;
    }
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    node* root=new node(5);

    root->left=new node(6);
    root->left->left=new node(9);
    root->left->right=new node(1);
    root->left->right->left=new node(2);
    root->left->right->left->left=new node(3);
    root->left->right->left->right=new node(5);
    root->left->right->left->right->right=new node(10);

    root->right=new node(3);
    root->right->left=new node(2);
    root->right->right=new node(1);
    root->right->left->right=new node(6);
    root->right->left->right->right=new node(7);

    preorder(root);
    cout<<endl;

    sumNode(root);
    
    preorder(root);
    cout<<endl;
    
    return 0;
}
