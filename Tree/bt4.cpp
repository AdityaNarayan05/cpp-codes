//level order traveral of Bt.//
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
void levelTraversal(node* root){
    if(root==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* node=q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<"  ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }

    }
}
int main(){
    //node* root=new node(1);
    //root->left=new node(2);
    //root->left->left=new node(4);
    //root->left->right=new node(5);
    //root->right=new node(3);
    //root->right->left=new node(6);
    //root->right->right=new node(7);

    node* root=new node(5);
    root->left=new node(3);
    root->left->left=new node(1);
    root->left->left->right=new node(2);
    root->left->right=new node(4);

    root->right=new node(6);
    root->right->right=new node(9);
    root->right->right->right=new node(13);
    root->right->right->right->right=new node(16); 
    root->right->right->right->left=new node(10);
    root->right->right->right->left->right=new node(12);
    root->right->right->left=new node(7);
    root->right->right->left->right=new node(8);
    
    //level order traversal.
    levelTraversal(root);
    return 0;
}