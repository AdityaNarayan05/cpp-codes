//cpp program to find out lowest common ancestor pf two node.
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left,*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
//method 1:
bool getPath(node *root,int key,vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==key){
        return true;
    }

    if(getPath(root->left,key,path)||getPath(root->right,key,path)){
        return true;
    }
    path.pop_back();
    return false;
}
int LCA1(node* root,int n1,int n2){
    vector<int> p1,p2;
    if(!getPath(root,n1,p1)||!getPath(root,n2,p2)){
        return -1;
    }
    
    int pc;
    for(pc=0;pc<p1.size()&&p2.size();pc++){
        if(p1[pc]!=p2[pc]){
            break;
        }
    }
    return p1[pc-1];
}
//method:2
node* LCA(node* root,int n1,int n2){
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
int main(){
    node *root=new node(5);

    root->left=new node(6);
    root->left->left=new node(9);
    root->left->right=new node(1);
    root->left->right->left=new node(12);
    root->left->right->left->left=new node(3);
    root->left->right->left->right=new node(4);
    root->left->right->left->right->right=new node(10);

    root->right=new node(3);
    root->right->left=new node(2);
    root->right->right=new node(11);
    root->right->left->right=new node(8);
    root->right->left->right->right=new node(7);
    
    node* lca=LCA(root,9,10);
    cout<<lca->data<<endl;
    //cout<<LCA(root,3,10)<<endl;    
    //cout<<LCA(root,3,9)<<endl;
    //cout<<LCA(root,7,11)<<endl;
    //cout<<LCA(root,1,2)<<endl;
    //cout<<LCA(root,1,10)<<endl;   
    return 0;
}