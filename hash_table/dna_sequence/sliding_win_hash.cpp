#include <bits/stdc++.h>

using namespace std;

set<string> solve(string s) {
     unordered_map<string, bool> substr;
     set<string> ans;
     long long l = 0;

     while (l+10 <= s.length()) {
          string str = s.substr(l, 10);
          if (substr.find(str) != substr.end()) {
               ans.insert(str);
          } else {
               substr.insert({str, 1});
          }
          l++;
     }
     return ans;
} 


int main() {
     string s;
     cin >> s;
     auto ans = solve(s);
     for (auto str: ans) {
          cout << str << "\n";
     }
     return 0;
}