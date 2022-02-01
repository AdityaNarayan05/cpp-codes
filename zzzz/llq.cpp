#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int cf;
    int pw;
    node* next;
    node(int c,int p){
        cf=c;
        pw=p;
        next=NULL;
    }
};
void insert(node* &head,int c,int p){
    node* n=new node(c,p);
    if(head==NULL){
        head=n;
        return;
    }
    node* t=head;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=n;
}
void display(node* &head){
    node* t=head;
    while(t!=NULL){
        cout<<t->cf<<" "<<t->pw<<"->";
        t=t->next;
    }
    cout<<"NULL"<<endl;
}
void calc(node* &l1,node* &l2){
    node* l3=NULL;
    node* t1=l1;
    node* t2=l2;
    while(t1!=NULL or t2!=NULL){
        if(t1->pw > t2->pw){
            insert(l3,t1->cf,t1->pw);
            t1=t1->next;
        }
        else if(t1->pw <t2->pw){
            insert(l3,t2->cf,t2->pw);
            t2=t2->next;
        }
        else if(t1->pw == t2->pw){
            insert(l3,t1->cf+t2->cf,t1->pw);
            t1=t1->next;
            t2=t2->next;
        }
    }
    display(l3);
}

int main(){
    node* l1=NULL;
    int s1,c,p;
    cout<<"Enter size of list 1"<<endl;
    cin>>s1;
    for(int i=1;i<=s1;i++){
        cout<<"Enter your coef.and power"<<endl;
        cin>>c>>p;
        insert(l1,c,p);
    }
    int s2;
    node* l2=NULL;
    cout<<"Enter size of list 2"<<endl;
    cin>>s2;
    for(int i=1;i<=s2;i++){
        cout<<"Enter your coef.and power"<<endl;
        cin>>c>>p;
        insert(l2,c,p);
    }
    display(l1);
    display(l2);
    calc(l1,l2);

    return 0;
}