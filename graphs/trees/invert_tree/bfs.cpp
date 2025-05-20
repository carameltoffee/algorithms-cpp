#include <bits/stdc++.h>

using namespace std;

class Tree{
public:
     int val;
     Tree *left;
     Tree *right;
     Tree():val(0), left(nullptr), right(nullptr) {}
     Tree(int x):val(x), left(nullptr), right(nullptr) {}
};

Tree* build_tree_from_array(const vector<int>& arr, int i = 0) {
     if(i>=arr.size()) return nullptr;

     Tree* root=new Tree(arr[i]);
     root->left=build_tree_from_array(arr,2*i+1);
     root->right=build_tree_from_array(arr,2*i+2);

     return root;
}

void dfs(Tree* r){
     if (!r) return;
     swap(r->left, r->right);
     dfs(r->left);dfs(r->right);
}

void print_tree_as_array(Tree* root) {
     vector<string> result;
     queue<Tree*> q;
     q.push(root);
     while(!q.empty()){
          Tree* node=q.front();q.pop();
          if(node){
               result.push_back(to_string(node->val));
               q.push(node->left);
               q.push(node->right);
          }else{
               result.push_back("n");
          }
     }
     while(!result.empty()&&result.back()=="n"){
          result.pop_back();
     }
     for (size_t i=0;i<result.size();++i) {
          cout<<result[i]<<" ";
     }
}

int main(){
     int n;cin>>n;
     vector<int> nums;
     for(int i=0;i<n;++i){
          int k;cin>>k;
          nums.push_back(k);
     }
     auto t=build_tree_from_array(nums);
     dfs(t);
     print_tree_as_array(t);
     return 0;
}

