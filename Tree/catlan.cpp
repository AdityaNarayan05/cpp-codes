#include<iostream>
using namespace std;

int catlan(int n){
    if(n<=1){
        return 1;
    }
    int res=0;
    for(int i=0;i<=n-1;i++){
        res+=catlan(i)*catlan(n-1-i);  
    }
    return res;
}
int main(){
    
    int n;
    cout<<"Enter the no of terms upto where you want no."<<endl;
    cin>>n;
    for(int i=0;i<=n;i++){
        cout<<"C"<<i<<"="<<catlan(i)<<endl;
    }

}