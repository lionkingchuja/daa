#include<bits/stdc++.h>
using namespace std;

void solve(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&left,vector<int>&upper,vector<int>&lower,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(left[row]==0 and lower[row+col]==0 and upper[n-1 +col-row]==0){
            
            board[row][col]='Q';
            left[row]=1;
            lower[row+col]=1;
            upper[n-1+col-row]=1;
            solve(col+1,board,ans,left,upper,lower,n);
            board[row][col]='.';
            left[row]=0;
            lower[row+col]=0;
            upper[n-1+col-row]=0;

        }
    }
}
int main(){
    int n;cin>>n;
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i]=s;
    }
    vector<int>left(n,0),upper(2*n-1,0),lower(2*n-1,0);

    solve(0,board,ans,left,upper,lower,n);


    for(int i=0;i<ans.size();i++){
        cout<<"Arrangement "<<i+1<<endl;
       for(int j=0;j<ans[i].size();j++) cout<<ans[i][j]<<endl;
       cout<<endl;
    }
    
    return 0;
}