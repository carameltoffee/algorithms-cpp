#include <bits/stdc++.h>

using namespace std;

bool is_valid(string n) {
     stack<char> q;
     for(int i=0;i<n.size();++i){
          if (n[i] == ')' && q.size()!=0) {
               q.pop();
          } else {
               q.push(n[i]);
          }
     }
     if (q.size()==0){
          return true;
     }
     return false;
}

void generate_parenthesis(int n) {
     string a="";
     for(int i=0;i<n;++i){
          a+="()";
     }
     sort(a.begin(), a.end());
     do {
          if (is_valid(a)) {
               cout<<a<<"\n";
          }
     } while (next_permutation(a.begin(), a.end()));
}

int main(){
     int n;
     cin>>n;
     generate_parenthesis(n);
     return 0;
}