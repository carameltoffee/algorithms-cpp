#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> n){
     vector<int> dp(n.size(), 0);

     dp[0]=n[0];
     dp[1]=n[1];

     for(int i=0;i<n.size();++i){
          dp[i]=n[i]+min(dp[i-1],dp[i-2]);
     }
     return min(dp[n.size()-1], dp[n.size()-2]);
}

int main(){
     int n;
     cin>>n;
     vector<int> nums;
     for(int i=0;i<n;++i){
          int k;
          cin>>k;
          nums.push_back(k);
     }
     cout << solve(nums);
     return 0;
}