#include<bits/stdc++.h>
using namespace std;

int f(int ind,int w,vector<int>&wt,vector<int>&val,vector<vector<int>>dp){
    if(ind==0){
        if(wt[0] <=w) return val[0];
        return 0;
    }
    if(dp[ind][w] != -1) return dp[ind][w];

    int not_take=0+f(ind-1,w,wt,val,dp);
    int take=INT_MIN;
    if(wt[ind] <= w){
        take=val[ind]+f(ind-1,w-wt[ind],wt,val,dp);
    }

    return dp[ind][w]=max(take,not_take);

}
int main(){
    int n;cin>>n;
    int mx_wt;cin>>mx_wt;
    vector<int>wt(n);
    vector<int>val(n);

    for(int i=0;i<n;i++) cin>>wt[i];
    for(int i=0;i<n;i++) cin>>val[i];

    vector<vector<int>>dp(n,vector<int>(mx_wt+1,-1));
    int ans=f(n-1,mx_wt,wt,val,dp);
    cout<<ans<<endl;
    return 0;
}