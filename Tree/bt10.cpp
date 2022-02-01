//yae bahut imp hae distance between two nodes.
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

node* LCA(node *root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1||root->data==n2){
        return root;
    }
    node* left=LCA(root->left,n1,n2);
    node* right=LCA(root->right,n1,n2);

    if(left!=NULL&&right!=NULL){
        return root;
    }
    if(left==NULL&&right==NULL){
        return NULL;
    }
    if(left!=NULL){
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right ,n1,n2);
}
int findDist(node *root,int k,int dist){
    if(root==NULL){
        return -1;
    }
    if(root->data==k){
        return dist;
    }

    int left=findDist(root->left,k,dist+1);
    if(left!=-1){
        return left;
    }
    return findDist(root->right,k,dist+1);
}
int DBNode(node *root,int n1,int n2){
    node *lca=LCA(root,n1,n2);

    int d1=findDist(lca,n1,0);
    int d2=findDist(lca,n2,0);

    return d1+d2;
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
    //node k values diffrent hone chiye nahi toh error aa sakta hae.
    int n1,n2;
    cout<<"enter the value of n1 and n2"<<endl;
    cin>>n1;
    cin>>n2;
    cout<<DBNode(root,n1,n2)<<endl;
    return 0;
}
