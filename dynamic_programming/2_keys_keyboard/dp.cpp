#include <bits/stdc++.h>

using namespace std;

int solve(int n){
     vector<int> dp(n+1,INT_MAX);
     dp[1]=0;
     for(int i=2;i<=n;++i){
          for(int j=1;j<=i/2;++j){
               if(i%j==0){
                    dp[i]=min(dp[i],dp[j]+i/j);
               }
          }
     }
     return dp[n];
}

int main(){
     int n;cin>>n;
     cout<<solve(n);
     return 0;
}