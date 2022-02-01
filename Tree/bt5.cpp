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
int sumAtk(node* root,int k){
    if(root==NULL){
        return -1;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;

    while(!q.empty()){
        node* node=q.front();
        q.pop();

        if(node!=NULL){
            if(level==k){
                sum+=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }  
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}
int count(node* root){
    if(root==NULL){
        return 0;
    }
    return count(root->left)+count(root->right)+1;
}
int sum(node* root){
    if(root==NULL){
        return 0;
    }
    return sum(root->left)+sum(root->right)+root->data;
}
int main(){
    node* root=new node(5);

    root->left=new node(6);
    root->left->left=new node(9);
    root->left->right=new node(1);
    root->left->right->left=new node(2);
    root->left->right->left->left=new node(3);
    root->left->right->left->right=new node(5);

    root->right=new node(3);
    root->right->left=new node(2);
    root->right->right=new node(1);
    root->right->left->right=new node(6);
    root->right->left->right->right=new node(7);

    //cout<<sumAtk(root,4)<<endl;
    //cout<<count(root)<<endl;//no of nodes in tree.
    cout<<sum(root)<<endl;//sum of all the nodesin a binary tree.
    return 0;
}