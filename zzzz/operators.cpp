#include<iostream>

using namespace std;

int main(){
    int a=6,b=5;
    cout << "HELLO ADITYA";
    // Airthmatic operator
    cout<< " following are airthmatic operaters in C++" <<endl;
    cout<<"The value ofa+b:"<<a+b<<endl;
    cout<<"The value ofa-b:"<<a-b<<endl;
    cout<<"The value ofa*b:"<<a*b<<endl;
    cout<<"The value ofa/b:"<<a/b<<endl;
    cout<<"The value ofa%b:"<<a%b<<endl;
    cout<<"The value ofa++:"<<a++<<endl;
    cout<<"The value ofa--:"<<a--<<endl;
    cout<<"The value of++a:"<<++a<<endl;
    cout<<"The value of--a:"<<--a<<endl;
    cout<<"The value ofa:"<<a<<endl;
    cout<<"The value ofb:"<<b<<endl;
    // comparison operator
    cout<< " following are  camparison  operaters in C++"<<endl;
    cout<<"The value ofa==b:"<<(a==b)<<endl;
    cout<<"The value ofa!=b:"<<(a!=b)<<endl;
    cout<<"The value ofa>b:"<<(a>b)<<endl;
    cout<<"The value ofa<b:"<<(a<b)<<endl;
    cout<<"The value ofa<=b:"<<(a<=b)<<endl;
    cout<<"The value ofa>=b:"<<(a>=b)<<endl;
    cout<<"The value ofa+b:"<<(a+b)<<endl;
    //   logical operators
    cout<< " following are  logical  operaters in C++"<<endl;
    cout<<"The value of logical and comparison operator are "<<((a==b)&&(a<b)||(a>=b))<<endl;
    return 0;
}