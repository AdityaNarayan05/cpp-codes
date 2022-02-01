//zigzag traversal of BT    
#include<iostream>
#include<stack>
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
void zigzag(node* root){
    if(root==NULL){
        return;
    }
    stack<node*> currl;
    stack<node*> nextl;
    bool ltoR=true;

    currl.push(root);
    while(!currl.empty()){
        node* temp=currl.top();
        currl.pop();

        if(temp!=NULL){
            cout<<temp->data<<" ";

            if(ltoR){
                if(temp->left){
                    nextl.push(temp->left);
                }
                if(temp->right){
                    nextl.push(temp->right);
                }
            }
            else{
                 if(temp->right){
                    nextl.push(temp->right);
                }
                if(temp->left){
                    nextl.push(temp->left);
                }
            }

            if(currl.empty()){
                ltoR=!ltoR;
                swap(currl,nextl);
            }        
        }
    }
}
int main(){
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

    zigzag(root);
    cout<<endl;
    return 0;
}