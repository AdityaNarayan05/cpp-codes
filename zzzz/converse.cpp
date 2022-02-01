#include"bits/stdc++.h"
#include<iostream>
using namespace std;

bintodec(int n1)
{
    int ans =0;
    int x=1;
    while(n1>0)
    {
        int y=n1%10;
        ams+=x+y;
        x=x*2;
        n1=n1/10;
    }
    cin<<ans;
}

octtodec(int n2)
{
   int ans =0;
    int x=1;
    while(n2>0)
    {
        int y=n2%10;
        ans+=x+y;
        x=x*8;
        n2=n2/10;
    }
    cin<<ans; 
}

hxdtodec(string n3)
{
    int ans=0;
    int x=1;
    int s=n3.size();
    for(int i=s-1;i>=0;i--)
    {
        if(n3[i]>='0'&n3[i]<='9')
        {
            ans+=x*(n3[i]-'0');
        }
        elseif(n3[i]>='A'&n3[i]<='F')
        {
            ans+=x*(n3[i]-'A'+10);
        }
        x*=16;   
    }
    cin<<ans;
}

dectobin(int n4)
{
    int x=1;
    int ans=0;
    while(x<=n4)
      x*=2;

    x/=2;
    while(x>0)
    {
        int ld=n4/x;
        n4-=ld*x;
        ans=ans*10+ld;
    }  
    cin<<ans;
}

dectooct(int n5)
{
    int x=1;
    int ans=0;
    while(x<=n5)
      x*=8;

    x/=8;
    while(x>0)
    {
        int ld=n5/x;
        n5-=ld*x;
        ans=ans*10+ld;
    }  
    cin<<ans;
}
dectohxd(int n6)
{
    int x=1;
    string ans =""
    while(x<=n6)
    {
        x*=16;
    }
    x/=16;
    while(x>0)
    {
        int ld=n6/x;
        n6-=ld*x;
        x/=16;

        if(ld<=9)
        {
            ans+=to_string(ld);
        }
        else
        {
            char c='A'+ld-10;
            ans.push_back(c)
        }
    }
    cin<<ans;
}

int main()
{
    int o;
    do
    {
       cout<<"enter 1 for binary to decimal "<<endl;
       cout<<"enter 2 for octal to decimal "<<endl;
       cout<<"enter 3 for hexadecimal to decimal "<<endl;
       cout<<"enter 4 for decimal to binary"<<endl;
       cout<<"enter 5 for decimal to octal "<<endl;
       cout<<"enter 6 for decimal to hexadecimal "<<endl;
       cin>>o;
    }
    while (o<1&&o>6)
    switch (o)
    {
    case 1:
        int n;
        cout<<"enter your no"<<endl;
        cin>>n;
        bintodec(int n);
        break;
    case 2:
        int n;
        cout<<"enter your no"<<endl;
        cin>>n;
        octtodec(int n);
        break;
    case 3:
        string n;
        cout<<"enter your no"<<endl;
        hxdtodec(string n);
        break;
    case 4:
        int n;
        cout<<"enter your no"<<endl;
        dectobin(int n);
        break; 
    case 5: 
        int n;
        cout<<"enter your no"<<endl;
        dectooct(int n)
        break; 
    case 6:
        int n;
        cout<<"enter your no"<<endl;
        dectohxd(int n);
        break;                 
    }
    

     return 0;
}