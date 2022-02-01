//Building bst from preorder traversal.
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left,*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
node* construct(int podr[],int* pIdx,int k,int min,int max,int n){

    if(*pIdx>=n){
        return NULL;
    }

    node* root=NULL;
    if(k>min&&k<max){
        root=new node(k);
        *pIdx=*pIdx+1;

        if(*pIdx<n){
            root->left=construct(podr,pIdx,podr[*pIdx],min,k,n);
        }
        if(*pIdx<n){
            root->right=construct(podr,pIdx,podr[*pIdx],k,max,n); 
        }

    }
    return root;
}
void inorder(node* root){//l+Ro+R.
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int podr[]={5,1,2,3,4,6,9,8,7,10,13,12,11};
    int n=13;
    int pIdx=0;
    node* root=construct(podr,&pIdx,podr[0],INT_MIN,INT_MAX,n);
    inorder(root);

    return 0;
}