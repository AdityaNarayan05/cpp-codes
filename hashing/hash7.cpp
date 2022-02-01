//soduko solver
//there is bug in code 
#include <bits/stdc++.h>
using namespace std;

void helper(int r, int c, vector<vector<int>> &a, map<pair<int, int>, map<int, int>> &mp, vector<map<int, int>> &row, vector<map<int, int>> &col){
    if(r==9){
        for(auto it : a){
            for(auto i : it){
                cout<<i<<" ";
            }
            cout<<endl;
        } 
        cout<<endl;
        return;
    }
    if(c==9){
        helper(r+1,0,a,mp,row,col);
        return;
    }
    if(a[r][c]!=0){
        helper(r,c+1,a,mp,row,col);
        return;
    }
    for(int i=1;i<=9;i++){
        int rw=r/3,cl=c/3;
        if(!mp[{rw,cl}][i] and !row[r][i] and !col[c][i]){
            mp[{rw,cl}][i]=1;
            row[r][i]=1;
            col[c][i]=1;  
            a[r][c]=i;
            helper(r,c+1,a,mp,row,col);
            mp[{rw,cl}][i]=0;
            row[r][i]=0;
            col[c][i]=0;  
            a[r][c]=0;     
        }
    }
}

void soduku(vector<vector<int>> &a)
{
    map<pair<int, int>, map<int, int>>mp;
    vector<map<int, int>> row(9);
    vector<map<int, int>> col(9);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
        {
            if (a[i][j] != 0)
            {
                mp[{i / 3, j / 3}][a[i][j]] = 1;
                row[i][a[i][j]] = 1;
                col[i][a[i][j]] = 1;
            }
        }
    }
    helper(0,0,a,mp,row,col);
}
int main()
{
    vector<vector<int>> s(9, vector<int> (9));
    cout<<"enter entities in sudoku blank as 0"<<endl;
    for(int i=0;i<9;i++){
        cout<<"enter entities  of each row"<<endl;
        cin >>s[i][0]>>s[i][1]>>s[i][2]>>s[i][3]>>s[i][4]>>s[i][5]>>s[i][6]>>s[i][7]>>s[i][8];
    }
    soduku(s);
    return 0;
}
