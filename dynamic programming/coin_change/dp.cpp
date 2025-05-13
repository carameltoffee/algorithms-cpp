#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &coins, int amount)
{
     vector<int> dp(amount + 1, INT_MAX);
     sort(coins.begin(), coins.end());

     dp[0] = 0;

     for (int i = 1; i <= amount; ++i)
     {
          for (auto coin : coins)
          {
               dp[i] = min(dp[i], dp[i - coin]);
          }
          if (dp[i] != INT_MAX)
          {
               dp[i]++;
          }
     }
     return dp[amount];
}

int main()
{
     int n, a;
     cin >> n >> a;
     vector<int> coins;
     for (int i = 0; i < n; ++i)
     {
          int k;
          cin >> k;
          coins.push_back(k);
     }
     cout << solve(coins, a);
     return 0;
}