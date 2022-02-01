//Redundant parentheses.
#include<iostream>
#include<stack>
using namespace std;

int extra(string s){
    int p;
    stack<char> st;
    int i=0;
    while(i<=s.size()){
        if(s[i]=='+'||s[i]=='*'||s[i]=='/'||s[i]=='-'||s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.top()=='('){
                p=p+1;
                st.pop();
            }
            while(st.top()!='('){
                st.pop();
            }
        }
        i++;
    }
    return p;
}
int main(){
    string s;
    cout<<"enter your statement"<<endl;
    cin>> s;
    cout<<"Extra bracket are :"<<extra(s)<<endl;
    return 0;
}