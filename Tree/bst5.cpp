//APPLICATION OF CATLAN NO
//POSSIBLE BST.
#include<iostream>
#include<vector>
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
vector<node*> consTree(int start,int end){
    vector<node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start;i<=end;i++){
        vector<node*> LST=consTree(start,i-1);
        vector<node*> RST=consTree(i+1,end);

        for(int j=0;j<LST.size();j++){
            node* left=LST[j];
            for(int k=0;k<RST.size();k++){
                node* right=RST[k];
                node* root=new node(i);
                root->left=left;
                root->right=right;
                trees.push_back(root);
            }
        }
    }
    return trees;
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    vector<node*> totalTrees=consTree(1,4);
    for(int i=0;i<totalTrees.size();i++){
        cout<<(i+1)<<":";
        preorder(totalTrees[i]);
        cout<<endl;
    }

    return 0;
}