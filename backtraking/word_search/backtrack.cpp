#include <bits/stdc++.h>

using namespace std;

int dc[2] = {-1, 1};
vector<vector<bool>>vis;
vector<vector<char>>b;
string w;
// bool is_valid()

bool backtrack(int idx, int m, int n){
     // cout<<idx<<" "<<w.size()<<"\n";
     if(idx==w.size()){
          return true;
     }
     vis[m][n]=true;
     for(auto v:dc){
          if((m+v)>=0&&(m+v)<b.size()){
               // cout<<b[m+v][n]<<" ANDTB "<<w[idx]<<"\n";
               if(b[m+v][n]==w[idx]&&!vis[m+v][n]){
                    if(backtrack(idx+1,m+v,n)){
                         return true;
                    }
               }
          }
          if((n+v)>=0&&(n+v)<b[m].size()){
               // cout<<b[m][n+v]<<" ANDRL "<<w[idx]<<"\n";
               if(b[m][n+v]==w[idx]&&!vis[m][n+v]){
                    if(backtrack(idx+1,m,n+v)){
                         return true;
                    }
               }
          }
     }
     vis[m][n]=false;
     return false;
}

int main(){
     int n,m;cin>>n>>m; 
     b.assign(n, vector<char>(m));
     for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
               char k;cin>>k;
               b[i][j]=k;
          }
     }
     cin>>w;
     vis.assign(n, vector<bool>(m));
     for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
               if(b[i][j]==w[0]){
                    vis.assign(n, vector<bool>(m));
                    if(backtrack(1,i,j)){
                         cout<<"TRUE";
                         return 0;
                    }
               }
          }
     }
     cout<<"FALSE";
     return 0;
}