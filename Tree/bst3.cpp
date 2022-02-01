//Check whether bst is valid or not.
#include<iostream>
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
//Check for BST.
bool isValid(node* root,node* min=NULL,node* max=NULL){
    if(root==NULL){
        return true;
    }

    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }
    bool leftV=isValid(root->left,min,root);
    bool rightV=isValid(root->right,root,max);

    return leftV and rightV;
}
int main(){
    node* root=new node(5 );
    root->left=new node(1);
    root->right=new node(3);

    if(isValid(root,NULL,NULL)){
        cout<<"TREE IS VALID"<<endl;
    }
    else{
        cout<<"TREE IS INVALID \n";
    }
    return 0;
}

