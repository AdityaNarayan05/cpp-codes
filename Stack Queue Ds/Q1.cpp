//largest area of rectangle in histogram.
#include<bits/stdc++.h>
using namespace std;

int area(vector<int> a){
    int n=a.size(),ans=0,i=0;
    stack<int> st;
    a.push_back(0);
    while(i<n){
        while(!st.empty() and a[st.top()]>a[i]){
            int h=a[st.top()];
            st.pop();
            if(st.empty()){
                ans=max(ans,h*i);
            }
            else{
                int len=i-st.top()-1;
                ans=max(ans,h*len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}
int main(){
     //int n;
     //cout<<"enter no of histogram"<<endl;
     //cin>>n;
     vector<int> a={2,1,5,6,2,3};
     //cout<<"enter the size of histogram"<<endl;
     //for(auto i:a){
       //  cin>>i;
     //}
     cout<<"Max. area in histogram formed by largest rectangle:"<<area(a)<<endl;
     return 0;
}