#include <iostream>
using namespace std;

class bin{
    public:
    int* a;
    int  beg,end;
    bin(int n){
        a=new int[n];
        beg=0;
        end=n-1;
    }

int binarySearch( int l, int u, int v)
{
    int m = (l+u)/2;

    if (l<u)
    {
        
        if (a[m]==v)
        {
            cout << "Element is found at location:";
            return(m + 1);
        }
        else if (a[m]>v)
        {
            binarySearch(l,m-1,v);
        }
        else
        {
            binarySearch(m+1,u,v);
        }
        
    }
    else{
        return -1;
    }
    
}
};

int main()
{
    int n;
    cout << "Enter the size of your array:";
    cin >> n;
    bin ob(n);
    
    cout << "Enter elements in your array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ob.a[i];
    }
    cout << "Array:";
    for (int i = 0; i < n; i++)
    {
        cout << "    " << ob.a[i];
    }
    cout<<endl;
    int e;
    cout << "Enter your searching element"<<endl;
    cin >> e;

    cout << ob.binarySearch(ob.beg,ob.end, e) << endl;
}