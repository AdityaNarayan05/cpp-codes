//we are working in binary search tree.
#include<iostream>
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
node* insert(node *root,int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{//val>root->data.
        root->right=insert(root->right,val);
    }
    return root;
}
node* search(node * root,int val){
    if(root==NULL){
        return NULL;
    }
    if(root->data ==val){
        return root;
    }
    if(root->data > val){
        return search(root->left,val);
    }
    else{//root->data<val.
        return search(root->right,val);
    }
}
node* inorderSucc(node* root){
    node*  curr=root;
    while(curr&&curr->left !=NULL){
        curr=curr->left;
    }
    return curr;
}
node* deleteinBST(node* root,int val){

    if(val<root->data){
        root->left=deleteinBST(root->left,val);
    }
    else if(val>root->data){
        root->right=deleteinBST(root->right,val);
    }
    else{
        if(root->left==NULL){
            node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node* temp=root->left;
            free(root);
            return temp;
        }
        //case 3:
        node* temp=inorderSucc(root->right);
        root->data=temp->data;
        root->right=deleteinBST(root->right,temp->data);
    }
    return root;
}
void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    node *root=NULL;
    //int n;
    //cout<<"Enter the no of nodes\n";
    //cin>>n;
    int arr[]={64,44,26,13,110,98,105,85,1,32,46,25,82};
    for(int i=0;i<13;i++){
        //cout<<"Enter the value for the node"<<endl;
        //int val;
        //cin>>val;
        if(i==0){
            root=insert(root,arr[i]);
        }
        else{
            insert(root,arr[i]);
        }
    }
    if(search(root,32)==NULL){
        cout<<"value does not exist"<<endl;
    }
    else{
        cout<<"value exist\n";
    }
    inorder(root);
    cout<<endl;
    root=deleteinBST(root,32);
    inorder(root);
    cout<<endl;
    if(search(root,32)==NULL){
        cout<<"value does not exist"<<endl;
    }
    else{
        cout<<"value exist\n";
    }
    return 0;
}