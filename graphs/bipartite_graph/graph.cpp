#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>>& g, vector<bool>& c, int n,bool curr_c, vector<bool>& vis){
     vis[n]=true;
     c[n]=curr_c;
     for(auto v:g[n]){
          if(!vis[v]){
               if (!dfs(g,c,v,!curr_c,vis)) {
                return false;
          }
          }else if(c[v]==curr_c){
               return false;
          }
     }
     return true;
}

int main() {
     int n,m;
     cin>>n>>m;
     vector<vector<int>> g(n);

     for (int i=0;i<m;++i) {
          int u,v;
          cin>>u>>v;
          g[u].push_back(v);
          g[v].push_back(u);
     }

     vector<bool> color(n);
     vector<bool> visited(n,false);

     bool is_bipartite=true;
     for (int i=0;i<n;++i) {
          if (!visited[i]) {
               if (!dfs(g,color,i,0,visited)){
                    is_bipartite=false;
                    break;
               }
          }
     }

     cout << (is_bipartite ? "TRUE" : "FALSE") << '\n';
     return 0;
}