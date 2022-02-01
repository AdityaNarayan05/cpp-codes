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
//is identical
bool identical(node* root1,node* root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    else if(root1==NULL ||root2==NULL){
        return false;
    }
    else{
        bool c1=root1->data==root2->data;
        bool c2=identical(root1->left,root2->left);
        bool c3=identical(root1->right,root2->right);

        if(c1&&c2&&c3){
            return true;
        }
        else{
            return false;
        }
    }
}
int main(){
   
    node* root=new node(2);
    root->left=new node(1);
    root->right=new node(3);

    node* root1=new node(2);
    root->left=new node(1);
    root->right=new node(5); 

    if(identical(root,root)){
        cout<<"identical"<<endl;
    }
    else{
        cout<<"not identical"<<endl;
    }
    if(identical(root,root1)){
        cout<<"identical"<<endl;
    }
    else{
        cout<<"not identical"<<endl;
    }


    return 0;
}