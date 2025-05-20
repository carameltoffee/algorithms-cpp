#include <bits/stdc++.h>

using namespace std;

void backtrack(string p, vector<string>& ans, 
     vector<int>& d, int c, unordered_map<int,vector<string>>& k){
     if(d.size()<=c){
          ans.push_back(p);
          return;
     }
     for(auto& v:k[d[c]]){
          p+=v;
          backtrack(p, ans, d, c+1, k);
          p.pop_back();
     }
}
 
int main(){
     unordered_map<int,vector<string>> k;
     k.emplace(2, vector<string>{"a","b","c"}); 
     k.emplace(3, vector<string>{"d","e","f"}); 
     k.emplace(4, vector<string>{"g","h","i"}); 
     k.emplace(5, vector<string>{"j","k","l"}); 
     k.emplace(6, vector<string>{"m","n","o"}); 
     k.emplace(7, vector<string>{"p","q","r","s"}); 
     k.emplace(8, vector<string>{"t","u","v"}); 
     k.emplace(9, vector<string>{"w","x","y","z"}); 
     int n;cin>>n;
     vector<int> d;
     for(int i=0;i<n;++i){
          int k;cin>>k;
          d.push_back(k);
     }
     vector<string>ans;
     backtrack("", ans, d, 0, k);
     for(auto v:ans){
          for(auto c:v){
               cout << c << " ";
          }
          cout<<"\n";
     }
}