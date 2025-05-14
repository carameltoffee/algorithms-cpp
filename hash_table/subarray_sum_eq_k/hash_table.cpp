#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> nums, long long int k) {
     unordered_map<long long, int> prefixsums; 
     int cnt = 0;
     long long curr_pref_sum = 0;
     prefixsums[0] = 1;
     for (auto num:nums) {
          curr_pref_sum+=num;
          if (prefixsums.count(curr_pref_sum - k)) {
               cnt++;
          }
          prefixsums[curr_pref_sum]++;

     }
     return cnt;
}


int main() {
     int n;
     cin >> n;
     vector<int>nums(n);
     for(int i=0;i<n;++i){
          int m;
          cin >> m;
          nums.push_back(m);
     }
     int k;
     cin >> k;
     cout << solve(nums, k);
     return 0;
}