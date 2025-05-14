#include <vector>
#include <iostream>

using namespace std;

long long int rec(vector<int> &coins, int curr, int sum)
{
     if (curr == sum)
     {
          return 0;
     }
     if (curr >= sum)
     {
          return __INT_MAX__;
     }

     long long int tmp = __INT_MAX__;
     for (int i = 0; i < coins.size(); ++i)
     {
          tmp = min(tmp, 1 + rec(coins, curr + coins[i], sum));
     }
     return tmp;
}

int main()
{
     int n;
     cin >> n;
     int am = 0;
     cin >> am;
     vector<int> nums;
     for (int i = 0; i < n; i++)
     {
          int val;
          cin >> val;
          nums.push_back(val);
     }
     cout << rec(nums, 0, am);
     return 0;
}