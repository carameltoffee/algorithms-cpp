#include <bits/stdc++.h>

using namespace std;

bool validate_num(string s) {
     if (s.empty()||(s.length()>1&&s[0]=='0')) return false;
     int n=atoi(s.c_str());
     return n>=0&&n<=255;
}

void backtrack(set<string>& ans, string p, const string& ip, int dots, int curr) {
     if(dots==3) {
          if(curr<ip.size()) {
               string last=ip.substr(curr);
               if (validate_num(last)) {
                    ans.insert(p+"."+last);
               }
          }
          return;
     }

     for(int r=1;r<=3&&curr+r<=ip.size();++r) {
          string segment=ip.substr(curr,r);
          if(validate_num(segment)){
               backtrack(ans, p + "." + segment, ip, dots + 1, curr + r);
          }
     }
}

int main() {
     string s;cin>>s;
     set<string> ans;
     for (int i=1;i<= 3&&i<s.size();++i) {
          string first=s.substr(0,i);
          if (validate_num(first)) {
               backtrack(ans,first,s,1,i);
          }
     }
     for(const auto& v:ans){
          cout<<v<<"\n";
     }
     return 0;
}
