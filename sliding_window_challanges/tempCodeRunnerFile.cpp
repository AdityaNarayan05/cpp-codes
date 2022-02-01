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