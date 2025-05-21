#include <bits/stdc++.h>

using namespace std;

bool is_perfect_sqrt(int n){
     int l=0;
     int r=n;
     while(l<=r){
          int mid=((l+r)/2);
          if(mid*mid>n){
               r=mid-1;
          }else if(mid*mid<n){
               l=mid+1;
          }else if(mid*mid==n){
               return true;
          }
     }
     return false;
}

int main(){
     int n;cin>>n;
     cout<<((is_perfect_sqrt(n))?"TRUE":"FALSE");
     return 0;
}