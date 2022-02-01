//Surrounded Region.
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter size of 2D grid"<<endl;
    cin>>n>>m;
    vector<vector<char>> A(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j]; 
            }
        }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 or i==n-1 or j==0 or j==m-1){
                if(A[i][j]=='O'){
                    A[i][j]='*';
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='O'){
                A[i][j]='X'; 
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='*'){
                A[i][j]='O';
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

}