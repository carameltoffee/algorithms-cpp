#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>& t){
     vector<int> ans(t.size(),0);
     stack<pair<int,int>> s;
     s.push({t[0],0});
     for(int i=1;i<t.size();++i){
          pair<int,int> l = s.top();
          ans[l.second]++;
          if (l.first >= t[i]){
               int j=0;
               while(l.first>=t[i+j] && i+j<t.size()){
                    j++;
               }
               if(i+j >= t.size()){
                    ans[l.second]=0;
               }else{
                    ans[l.second]+=j;
               }
               s.pop();
          }
          s.push({t[i], i});
     }
     return ans;
}

int main(){
     int n;cin>>n;
     vector<int> t;
     for(int i=0;i<n;i++){
          int k;cin>>k;
          t.push_back(k);
     }
     auto ans = solve(t);
     for(auto i:ans){
          cout << i << " ";
     }
     return 0;
}