//flatten a tree
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
void flatten(node* root){
    if(root==NULL||(root->left==NULL&&root->right==NULL)){
        return;
    }
    if(root->left!=NULL){
        flatten(root->left);

        node* temp=root->right;
        root->right=root->left;
        root->left=NULL;

        node* t=root->right;
        while(t->right!=NULL){
            t=t->right;
        }
        t->right=temp;
    }
    flatten(root->right);
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void print(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->right);
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
    //node* root=new node(1);
    //root->left=new node(2);
    //root->right=new node(3);
    //root->right->left=new node(4);
    //root->right->right=new node(5);

    preorder(root);
    cout<<endl;
    flatten(root);
    //preorder(root);
    print(root);
    cout<<endl;
    return 0;
}