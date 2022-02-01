#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,x,y;
    do{
        cin>>a>>b>>x>>y;
    }while(a<1&&a>1000&&b<1&&b>1000&&x<1&&x>1000&&y<1&&y>1000);
    int c=(a*x)+(b*y);
    cout<<c;
}