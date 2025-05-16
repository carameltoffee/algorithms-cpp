#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& p){
     vector<int> dp(p.size(),0);
     dp[0]=0;
     for(int i=1;i<p.size();++i){
          int pr = p[i]-p[i-1];
          if (dp[i-1]+pr>=dp[i-1]){
               dp[i]=dp[i-1]+pr;
          }else{
               dp[i]=dp[i-1];               
          }
     }
     return dp[dp.size()-1];
}

int main(){
     int n;cin>>n;
     vector<int> p;
     for(int i=0;i<n;++i){
          int k;cin>>k;
          p.push_back(k);
     }
     cout<<solve(p);
     return 0;
}