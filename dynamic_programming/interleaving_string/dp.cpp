#include <bits/stdc++.h>

using namespace std;

bool solve(string s1,string s2,string s3){
     vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1));
     dp[0][0]=true;
     for(int i=1;i<=s1.size();i++){
          if(s1[i-1]==s3[i-1]) dp[i][0]=(dp[i-1][0]&&true);
     }
     for(int i=1;i<=s1.size();i++){
          if(s2[i-1]==s3[i-1]) dp[0][i]=(dp[0][i-1]&&true);
     }
     for(int i=1;i<=s1.size();i++){
          for(int j=1;j<=s2.size();j++){
               if(s2[j-1]==s3[i+j-1]){
                    dp[i][j]=(dp[i][j-1]&&true);
               }else if(s1[i-1]==s3[i+j-1]){
                    dp[i][j]=(dp[i-1][j]&&true);
               }
          }
     }
     return dp[s1.size()][s2.size()];
}

int main(){
     string s1,s2,s3;cin>>s1>>s2>>s3;
     cout<<(solve(s1,s2,s3)?"TRUE":"FALSE");
     return 0;
}