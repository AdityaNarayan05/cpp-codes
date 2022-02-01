#include<iostream>
using namespace std;

class Aj{
    public:
    fun(){
        cout<<"this is function with no argument"<<endl;
     }
     fun(int n){
        cout<<"this is function with integer argument"<<endl;
     }
     fun(double d){
        cout<<"this is function with double argument"<<endl;
     }
};

int main(){
    Aj ob;
    ob.fun();
    ob.fun(5);
    ob.fun(5.2);
     
     return 0;
}