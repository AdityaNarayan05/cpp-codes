//building BT using binery search technique.
#include<iostream>
using namespace std;

struct node{
    int data;
    node* left, *right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
node* Build(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }

    int mid=(start+end)/2;
    node* root=new node(arr[mid]);

    root->left=Build(arr,start,mid-1);
    root->right=Build(arr,mid+1,end);

    return root;
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}
int main(){
    //int arr[]={1,3,7,9,13,15,19,20,21,36,60,64};
    int arr[]={10,20,30,40,50};
    node* root=Build(arr,0,4);
    preorder(root);
    cout<<endl;

    inorder(root);
    cout<<endl;
    return 0;
}