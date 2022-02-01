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
int calcHeight(node* root){//time complexity O(n).
    if(root==NULL){
        return 0;
    }
    int lH=calcHeight(root->left);
    int rH=calcHeight(root->right);
    return max(lH,rH)+1;
}
int calcDiameter(node* root){//time complexity O(n^2).
    if(root==NULL){
        return 0;
    }
    int lH=calcHeight(root->left);//yae ek baar call hua hae.
    int rH=calcHeight(root->right);
    
    int cD=lH+rH+1;

    int lD=calcDiameter(root->left);//yae ek baar  n*n
    int rD=calcDiameter(root->right);

    return max(cD,max(lD,rD));
}
int calcDiameter(node* root,int* height){//time complexity of O(n) as height and diameter are called in same funtion.
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lH=0,rH=0;
    int lD=calcDiameter(root->left,&lH);
    int rD=calcDiameter(root->right,&rH);

    int cD=lH+rH+1;
    *height=max(lH,rH)+1;
    return max(cD,max(lD,rD));
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
    //cout<<calcHeight(root)<<endl;
    //cout<<calcDiameter(root)<<endl;
    int h=0;
    cout<<calcDiameter(root,&h)<<endl;

    return 0;

}
