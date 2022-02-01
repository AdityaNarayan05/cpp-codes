//Subarray with Palindromic Concatenation.
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isPalin(int n){//code for reversing no.
    int temp=n;
    int num=0;

    while(temp>0){
        num=num*10 +temp%10;
        temp=temp/10;
    }

    if(num == n){
        return true;
    }
    return false;
}

int fPalindrome(vector<int> arr,int k){
    int num=0;

    for(int i=0;i<k;i++){
        num=num*10 + arr[i];
    }

    if(isPalin(num)){
        return 0;
    }

    for(int j=k;j<arr.size();j++){
        num=(num%(int)pow(10,k-1))*10 +arr[j];

        if(isPalin(num)){
            return j-k+1;
        }
    }

    return -1;

}

int main(){
    vector<int> arr={2,3,5,1,1,5};
    int k=4;

    int ans=fPalindrome(arr,k);

    if(ans==-1){
        cout<<"palindrome subarray doesn't exist\n";
    }
    else{
        for(int i=ans;i<ans+k;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}