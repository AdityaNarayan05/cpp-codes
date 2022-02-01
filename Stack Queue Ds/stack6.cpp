#include<iostream>
#include<stack>
using namespace std;

bool balance(string s){
    int n=s.length();
    stack<char> st;
    bool ans=true;
    for(int i=0;i<n;i++){
        if(s[i]=='['||s[i]=='{'||s[i]=='('){
            st.push(s[i]);
        }
        else if(!st.empty()&&s[i]==')'){
            if(st.top()=='('){
                st.pop();
            }
            else{
                ans= false;
                break;
            }
        }
        else if(!st.empty()&&s[i]=='}'){
            if(st.top()=='{'){
                st.pop();
            }
            else{
                ans=false;
                break;
            }
        }
        else if(!st.empty()&&s[i]==']'){
            if(st.top()=='['){
                st.pop();
            }
            else{
                ans=false;
                break;
            }
        }
    }

    if(!st.empty()){
        ans=false;
    }
    return ans;
}


int main(){
    string s;
    cout<<"enter your brackets"<<endl;
    cin>>s;
    if(balance(s)){
        cout<<"String is balance"<<endl;
    }
    else{
        cout<<"String is unbalanced"<<endl;
    }
     
     return 0;
}