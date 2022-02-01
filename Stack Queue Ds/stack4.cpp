//prefix and postfix evaluation.
#include<bits/stdc++.h>
using namespace std;

int prefixEvaluation(string s){
    stack<int> st;

    for(int i=s.length()-1;i>=0;i--){ 
        if(s[i]>='0'&&s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();
            switch(s[i])
            {
                case '+':
                    st.push(op1+op2);
                    break;

                case '-':
                    st.push(op1-op2);
                    break;
            
                case '*':
                    st.push(op1*op2);
                    break;
            
                case '/':
                    st.push(op1/op2);
                    break;

                case '^':
                    st.push(pow(op1,op2));
                    break;
            }

        }
    }
    return st.top();
} 

int postfixEvaluation(string s){
    stack<int> ob;

    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            ob.push(s[i]-'0');
        }
        else{
            int op2=ob.top();
            ob.pop();
            int op1=ob.top();
            ob.pop();
            switch(s[i])
            {
                case '+':
                    ob.push(op1+op2);
                    break;

                case '-':
                    ob.push(op1-op2);
                    break;
            
                case '*':
                    ob.push(op1*op2);
                    break;
            
                case '/':
                    ob.push(op1/op2);
                    break;

                case '^':
                    ob.push(pow(op1,op2));
                    break;
            }

        }
    }
    return ob.top();
}
int main(){
    int n=prefixEvaluation("-+7*45+20");
    cout<<n<<endl;
    int m=postfixEvaluation("46+2/5*7+");
    cout<<m<<endl;
    return 0;
}
