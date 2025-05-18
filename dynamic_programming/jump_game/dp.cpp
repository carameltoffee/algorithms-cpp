#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int>& n){
     vector<bool> dp(n.size(),false);
     dp[n.size()-1]=true;
     for(int i=n.size()-2;i>=0;--i){
          for(int j=1;j<=n[i];j++){
               if(dp[i+j]==true){
                    dp[i]=true;
                    break;
               }
          }
     }
     return dp[0];
}

int main(){
     int n;cin>>n;
     vector<int> nums;
     for(int i=0;i<n;++i){
          int k;cin>>k;
          nums.push_back(k);
     }
     cout<<solve(nums);
     return 0;
}