//very imp Question.
//vertical order traversal using hashing
//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//#include<algorithm>
//#include<stack>
//#include<queue>
#include<map>
//#include<unordered_map>
//#include<set>
#include<vector>
//#include<string>

//User defined snippets
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

struct node{
    int data;
    node* left,*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void verTraversal(node* root,int hD,map<int,vi> &m){
    if(root==NULL){
        return;
    }
    m[hD].push_back(root->data);
    verTraversal(root->left,hD-1,m);
    verTraversal(root->right,hD+1,m);
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

    map<int,vector<int>> m;
    int hD=0;
    
    verTraversal(root,hD,m);

    map<int,vi>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        rep(i,0,(it->ss).size()){
            cout<<(it->ss)[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}