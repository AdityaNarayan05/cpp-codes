//infix to postfix and infix to prefix.
#include<bits/stdc++.h>
using namespace std;

int precedence(char c){

    if(c=='^'){
        return 3;
    }
    else if(c=='*'||c=='/'||c=='%'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPostfix(string s){
    stack<char> st;
    string res;
    
    for(int i=0;i<s.length();i++){

        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty()&&st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty()&& precedence(st.top())>=precedence(s[i])){//yae dhyan rakhna.
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    
    return res;

}

string infixToPrefix(string s){
    reverse(s.begin(),s.end());
    string revs;
    //cout<<s<<endl;
    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
            revs+='(';
        }
        else if(s[i]=='('){
            revs+=')';
        }
        else{
            revs+=s[i];
        }
    }
    //cout<<revs<<endl;
    string result;
    result=infixToPostfix(revs);
    reverse(result.begin(),result.end());
    return result;
}

int main(){
    cout<<infixToPostfix("(a-b/c)*(a/k-l)")<<endl;
    //cout<<infixToPostfix("A+B*C/(D+E/F)-G%H")<<endl;
    //cout<<infixToPostfix("x+y*z/m^n*p-x+y/z")<<endl;
     
    cout<<infixToPrefix("(a-b/c)*(a/k-l)")<<endl;
    //cout<<infixToPrefix("A+B*C/(D+E/F)-G%H")<<endl;
    //cout<<infixToPrefix("x+y*z/m^n*p-x+y/z")<<endl;

    return 0;
}