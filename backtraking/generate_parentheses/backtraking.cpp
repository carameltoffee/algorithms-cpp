#include <bits/stdc++.h>

using namespace std;

vector<string> backtraking(int left,int right,string curr,vector<string>& res){
     if (left==0&&right==0){
          res.push_back(curr);
          return res;
     }

     if (left>0){
          backtraking(left-1, right, curr+"(", res);
     }

     if (left<right){
          backtraking(left, right-1, curr+")", res);
     }
     return res;
}

int main(){
     int n;
     cin>>n;
     vector<string> res;
     res = backtraking(n,n,"",res);
     for (auto i:res){
          cout<<i<<"\n";
     }
     return 0;
}