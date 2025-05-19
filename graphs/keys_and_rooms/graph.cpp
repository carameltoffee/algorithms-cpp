#include <bits/stdc++.h>

using namespace std;

bool solve(vector<vector<int>>& r){
     int cnt=1;
     vector<int> visited(r.size());
     for(int i=0;i<r.size();i++){
          for(int j=0;j<r[i].size();j++){
               if(!visited[r[i][j]]){
                    visited[r[i][j]]=true;
                    cnt++;
               }
          }
     }
     return cnt==r.size();
}

int main(){
     int n;cin>>n;
     vector<vector<int>>a;
     for(int i=0;i<n;++i){
          int k;cin>>k;
          vector<int>keys;
          for(int j=0;j<k;++j){
               int c;cin>>c;
               keys.push_back(c);
          }
          a.push_back(keys);
     }
     if(solve(a)){
          cout<<"TRUE";
     }else{
          cout<<"FALSE";
     }
     return 0;
}