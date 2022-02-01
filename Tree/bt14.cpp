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
int maxPathSumUtil(node *root,int &ans){
    if(root==NULL){
        return 0;
    }

    int l=maxPathSumUtil(root->left,ans);
    int r=maxPathSumUtil(root->right,ans);

    int nodeMax=max(max(root->data,root->data+l+r),max(root->data+l,root->data+r));
    ans=max(ans,nodeMax);

    int sps=max(root->data,max(root->data+l,root->data+r));
    return sps;
}
int maxPathSum(node *root){
    int ans=INT_MIN;
    maxPathSumUtil(root,ans);
    return ans;
}
int main(){
    node *root=new node(5);

    root->left=new node(6);
    root->left->left=new node(9);
    root->left->right=new node(1);
    //root->left->right->left=new node(12);
    //root->left->right->left->left=new node(3);
    //root->left->right->left->right=new node(4);
    //root->left->right->left->right->right=new node(10);

    root->right=new node(3);
    root->right->left=new node(2);
    root->right->right=new node(11);
    root->right->left->right=new node(8);
    root->right->left->right->right=new node(7);
    
    cout<<maxPathSum(root)<<endl;
    return 0;

}