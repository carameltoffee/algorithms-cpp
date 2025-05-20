#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> gr;
vector<vector<bool>> vis;
int max_gold=0;
int dr[2]={-1,1};

void backtrack(int n, int m,int curr_gold){
     vis[n][m]=true;
     max_gold=max(curr_gold,max_gold);
     for(auto d:dr){
          if((n+d)>=0&&(n+d)<gr.size()){
               if(!vis[n+d][m]&&gr[n+d][m]!=0){
                    backtrack(n+d,m,curr_gold+gr[n+d][m]);
               }
          }
          if((m+d)>=0&&(m+d)<gr[n].size()){
               if(!vis[n][m+d]&&gr[n][m+d]!=0){
                    backtrack(n,m+d,curr_gold+gr[n][m+d]);
               }
          }
     }
     vis[n][m]=false;
     return;
}

int main(){
     int n,m;cin>>n>>m;
     gr.assign(n, vector<int>(m));
     vis.assign(n, vector<bool>(m,false));
     for(int i=0;i<n;++i){
          for(int j=0;j<m;++j){
               int k;cin>>k;
               gr[i][j]=k;
          }
     }
     for(int i=0;i<n;++i){
          for(int j=0;j<m;++j){
               if(gr[i][j]!=0){
                    vis.assign(n,vector<bool>(m,false));
                    backtrack(i,j,gr[i][j]);
               }
          }
     }
     cout<<max_gold;
     return 0;
}